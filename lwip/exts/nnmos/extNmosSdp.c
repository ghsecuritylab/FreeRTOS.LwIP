/*
* SDP descriptions of NMOS Sender
*/

#include "lwipExt.h"

#include "extHttp.h"
#include "jsmn.h"

#define	EXT_SDP_NTP_EPOCH_OFFSET		2208988800		/* network time protocol, from 1900, used in timing params */

#define	EXT_SDP_PROTOCOL				"RTP/AVP"

#define	EXT_SDP_NET_TTL					1

#define	EXT_SDP_MEDIA_VIDEO				"video"
#define	EXT_SDP_MEDIA_AUDIO				"audio"
#define	EXT_SDP_MEDIA_DATA				"video"

#define	EXT_SDP_FORMAT_VIDEO			96		/* 112 in 2110-20 */
#define	EXT_SDP_FORMAT_AUDIO			96
#define	EXT_SDP_FORMAT_DATA				106		/* 96 in S352m.pdf */

#define	EXT_SDP_DEFAULT_CLOLK_RATE			90000


/* output session and timing info of SDP */
static int _nmosSdpSessionTimeHander(char *data, unsigned int size, ExtNmosSender *snd)
{
	int index = 0;
	
	EXT_ASSERT(("Sender is null"),  snd!=NULL&&snd->device != NULL);

	/* resource core fields */
	index += snprintf(data+index, size-index, "v=0\n" );	/* version*/
	/* original */
	index += snprintf(data+index, size-index, "o=%s %ld %ld IN IP4 %s\n", 
		snd->device->node->runCfg->user, sys_now()/* sess ID*/, sys_now()/* sess ver */, EXT_LWIP_IPADD_TO_STR(&snd->device->node->runCfg->local.ip) );
	/* session name */
	index += snprintf(data+index, size-index, "s=NMOS %s stream\n", (snd->flow->format==NMOS_SOURCE_FORMAT_AUDIO)?"audio":"video" );
	/* connection */
	index += snprintf(data+index, size-index, "c=IN IP4 %s/%d\n", 
		(IP_ADDR_IS_MULTICAST(snd->device->node->runCfg->dest.ip))? EXT_LWIP_IPADD_TO_STR(&snd->device->node->runCfg->dest.ip) :EXT_LWIP_IPADD_TO_STR(&snd->device->node->runCfg->local.ip), EXT_SDP_NET_TTL );
	/* time */
	index += snprintf(data+index, size-index, "t=%d %d\n", 0/* start*/, 0/*stop*/ );

	return index;
}


static int _nmosSdpMediaHander(char *data, unsigned int size, ExtNmosSender *snd)
{
	int index = 0;
	
	EXT_ASSERT(("Sender is null"),  snd!=NULL&&snd->device != NULL);

	if(snd->flow->format == NMOS_SOURCE_FORMAT_AUDIO)
	{
		index += snprintf(data+index, size-index, "m="EXT_SDP_MEDIA_AUDIO" %d "EXT_SDP_PROTOCOL" %d\n", snd->device->node->runCfg->local.aport, EXT_SDP_FORMAT_AUDIO);
		/* RTP mapping */
		index += snprintf(data+index, size-index, "a=rtpmap:%d %s/%d/2\n", EXT_SDP_FORMAT_AUDIO, "L16", snd->flow->sampleRate.numberator );
		index += snprintf(data+index, size-index, "a=readonly\n" );
		/* packet time */
		index += snprintf(data+index, size-index, "a=ptime:1\n" );
		index += snprintf(data+index, size-index, "a=mediaclk:direct=%ld\n", sys_now());
		index += snprintf(data+index, size-index, "a=ts-refclk:ptp=IEEE1588-2008:%x-%x-%x-%x-%x-%x-%x-%x:domain-nmbr=0\n", 
			snd->resourceId.nmosId.uuid.uuid[0], snd->resourceId.nmosId.uuid.uuid[1],snd->resourceId.nmosId.uuid.uuid[2],snd->resourceId.nmosId.uuid.uuid[3],
			snd->resourceId.nmosId.uuid.uuid[4],snd->resourceId.nmosId.uuid.uuid[5],snd->resourceId.nmosId.uuid.uuid[6],snd->resourceId.nmosId.uuid.uuid[7]);	
	}
	else if(snd->flow->format == NMOS_SOURCE_FORMAT_VIDEO)
	{/* video */
		index += snprintf(data+index, size-index, "m="EXT_SDP_MEDIA_VIDEO" %d "EXT_SDP_PROTOCOL" %d\n", snd->device->node->runCfg->local.vport, EXT_SDP_FORMAT_VIDEO);	
		index += snprintf(data+index, size-index, "a=rtpmap:%d raw/%d\n", EXT_SDP_FORMAT_VIDEO, EXT_SDP_DEFAULT_CLOLK_RATE );
		/* fmtp: format params; TCS: SDR, etc; */
		index += snprintf(data+index, size-index, "a=fmtp:%d sample=YCbCr-4:2:2;width:%d;height:%d;exactframearte=%d/%d;depth=%d;TCS=%s;colorimetry=%s;PM=2119GPM;SSN=\"ST2110-20:2017\"\n", 
			EXT_SDP_FORMAT_VIDEO, snd->flow->frameWidth, snd->flow->frameHeight, snd->flow->source->gRate.numberator,snd->flow->source->gRate.numberator, snd->flow->bitDepth,
			NMOS_FIND_TRANSFER_CHARC(snd->flow->transferCharacter), NMOS_FIND_COLOR_SPACE(snd->flow->colorspace) );	

	}
	else
	{/* Ancillary data */
	
		index += snprintf(data+index, size-index, "a=group:FID V1 M1\n" );	
		index += snprintf(data+index, size-index, "m="EXT_SDP_MEDIA_DATA" %d "EXT_SDP_PROTOCOL" %d\n", snd->device->node->runCfg->local.dport, EXT_SDP_FORMAT_DATA );	
		index += snprintf(data+index, size-index, "a=rtpmap:%d ampte291/%d\n", EXT_SDP_FORMAT_DATA , EXT_SDP_DEFAULT_CLOLK_RATE);	
		index += snprintf(data+index, size-index, "a=fmtp:%d DID_SDID={0x%x,0x%x};DID_SDID={0x%x,0x%x}\n",EXT_SDP_FORMAT_DATA, 0x61, 0x02, 0x41, 0x05);	
		index += snprintf(data+index, size-index, "a=mid:M1\n");	
	}

	return index;
}

int extNmosSdpMediaHander(char *data, unsigned int size, ExtNmosSender *snd)
{
	int index = 0;

	index += _nmosSdpSessionTimeHander(data+index, size-index, snd);

	index += _nmosSdpMediaHander(data+index, size-index, snd);

	return index;
}


