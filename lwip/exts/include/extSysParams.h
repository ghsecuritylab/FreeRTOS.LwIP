/*
* common logics used in booloader, RTOS and simhost. So only ANSI is used in this file
*/

#ifndef	__EXT_SYS_PARAMS_H__
#define	__EXT_SYS_PARAMS_H__

/* defined in stdlib.h */
#ifndef	EXIT_FAILURE
#define	EXIT_FAILURE 			1
#endif

#ifndef	EXIT_SUCCESS
#define	EXIT_SUCCESS 			0
#endif

#ifndef EXT_FALSE
#define EXT_FALSE				0
#endif

#ifndef EXT_TRUE
#define EXT_TRUE				(!EXT_FALSE)
#endif

#define	EXT_RW_BUFFER_SIZE				1024


#define	EXT_COMMAND_BUFFER_SIZE			1024	/* for output buffer */

#define	EXT_SC_KEY_MAX_LENGTH			32
#define	EXT_SC_ID_MAX_LENGTH				8

#define	EXT_MAGIC_SIZE					2

#define	EXT_USER_SIZE						16
#define	EXT_PASSWORD_SIZE				16


#define	EXT_MAGIC_VALUE_A				0xA5
#define	EXT_MAGIC_VALUE_B				0x5A

#define	EXT_MAC_ADDRESS_LENGTH			6

#define	EXT_IP_CFG_DHCP_ENABLE			(1<<0)
#define	EXT_IP_CFG_MC_ENABLE				(1<<1)	/* multicast */
#define	EXT_IP_CFG_ARP_ENABLE			(1<<2)		


/* configuration options for 767 board */
/** MAC address definition.  The MAC address must be unique on the network. */
#define ETHERNET_CONF_ETHADDR0                        0x00
#define ETHERNET_CONF_ETHADDR1                        0x04
#define ETHERNET_CONF_ETHADDR2                        0x25
#define ETHERNET_CONF_ETHADDR3                        0x1C
#ifdef EXTT_BOARD
#define ETHERNET_CONF_ETHADDR5                        0x01
#else
#define ETHERNET_CONF_ETHADDR5                        0x02
#endif

#define ETHERNET_CONF_ETHADDR4_TX			0x10
#define ETHERNET_CONF_ETHADDR4_RX			0xA0


#define	MCAST_DEFAULT_IPADDR0				239
#define	MCAST_DEFAULT_IPADDR1				100
#define	MCAST_DEFAULT_IPADDR2				1
#define	MCAST_DEFAULT_IPADDR3				1


/** The IP address being used. */
#define ETHERNET_CONF_IPADDR0					192
#define ETHERNET_CONF_IPADDR1					168
#if ARCH_ARM
	#ifdef EXTT_BOARD
	#define ETHERNET_CONF_IPADDR2_TX			168
	#define ETHERNET_CONF_IPADDR2_RX			168
	#define ETHERNET_CONF_IPADDR3_TX			120
	#else
	#define ETHERNET_CONF_IPADDR2_TX			169
	#define ETHERNET_CONF_IPADDR2_RX			169
	#define ETHERNET_CONF_IPADDR3_TX			121
	#endif
#else
	/* X86 test environment */
	#define ETHERNET_CONF_IPADDR2_TX			166
	#define ETHERNET_CONF_IPADDR2_RX			167
	#define ETHERNET_CONF_IPADDR3_TX			2
#endif

#if ARCH_ARM
#define ETHERNET_CONF_IPADDR3_RX				130
#else
#define ETHERNET_CONF_IPADDR3_RX				3
#endif


/** The gateway address being used. */
#define ETHERNET_CONF_GATEWAY_ADDR0                   192
#define ETHERNET_CONF_GATEWAY_ADDR1                   168
#if ARCH_ARM
	#ifdef EXTT_BOARD
	#define ETHERNET_CONF_GATEWAY_ADDR2_TX			168
	#define ETHERNET_CONF_GATEWAY_ADDR2_RX			168
	#else
	#define ETHERNET_CONF_GATEWAY_ADDR2_TX			169
	#define ETHERNET_CONF_GATEWAY_ADDR2_RX			169
	#endif
#else
	#define ETHERNET_CONF_GATEWAY_ADDR2_TX			166
	#define ETHERNET_CONF_GATEWAY_ADDR2_RX			167
#endif

#define ETHERNET_CONF_GATEWAY_ADDR3                   1

/** The network mask being used. */
#define ETHERNET_CONF_NET_MASK0                       255
#define ETHERNET_CONF_NET_MASK1                       255
#define ETHERNET_CONF_NET_MASK2                       255
#define ETHERNET_CONF_NET_MASK3                       0

#define	EXT_HTTP_SVR_PORT					80


#define	EXT_MEDIA_PORT_RANGE					10		/* range of RTP port */

#define	EXT_MEDIA_PORT_TX_VIDEO				40000
#define	EXT_MEDIA_PORT_TX_AUDIO				40010
#define	EXT_MEDIA_PORT_TX_DATA				40020
#define	EXT_MEDIA_PORT_TX_STREA				40030

#define	EXT_MEDIA_PORT_RX_VIDEO				48000
#define	EXT_MEDIA_PORT_RX_AUDIO				48010
#define	EXT_MEDIA_PORT_RX_DATA				48020
#define	EXT_MEDIA_PORT_RX_STREA				48030


#define	EXT_767_PRODUCT_NAME				"SdiOverIP-767"

#define	EXT_767_MODEL							"500767"

#define	EXT_USER								"admin"
#define	EXT_PASSWORD							"admin"

#define	EXT_SUPER_USER						"extlab"
#define	EXT_SUPER_PASSWORD					"extlab"

#define	EXT_MDNS_HOST_NAME					"an767tx"
#define	EXT_MDNS_SERVICE_NAME				"nmos"



#define	EXT_NEW_LINE							"\r\n"
//#define	EXT_NEW_LINE							"\r"

#define	EXT_PROMPT							">"


#define	ASCII_KEY_TAB				( 0x09 )	/* horizontal TAB */
#define	ASCII_KEY_LF				( 0x0A )	/* Line Feed, \n */
#define	ASCII_KEY_CR				( 0x0D )	/* Carier Return, \r */
/* DEL acts as a backspace. */
#define	ASCII_KEY_DEL				( 0x7F )

#define	EXT_CMD_MAX_ARGUMENTS		10
#define	EXT_CMD_MAX_LENGTH			32



/* macros for version */
#define	EXT_VERSION_DOT(a, b, c)				a ##.## b ##.## c

#define	EXT_VERSION(a, b, c)					EXT_VERSION_DOT(a, b, c)

#define	EXT_STRINGIFY(s)         					EXT_TOSTRING(s)
#define	EXT_TOSTRING(s)						#s


#define	EXT_GLUE(a, b)							a ## b
#define	EXT_JOIN(a, b)							EXT_GLUE(a, b)

#define	EXT_VERSION_MAJOR					0
#define	EXT_VERSION_MINOR					1
#define	EXT_VERSION_REVISION					1

#define	BL_VERSION_MAJOR						0
#define	BL_VERSION_MINOR						1
#define	BL_VERSION_REVISION					1


#define	EXT_VERSION_INFO()					((EXT_VERSION_MAJOR<<16)|(EXT_VERSION_MINOR<<8)|(EXT_VERSION_REVISION))


#define	BL_VERSION_INFO()						((BL_VERSION_MAJOR<<16)|(BL_VERSION_MINOR<<8)|(BL_VERSION_REVISION))


#define	EXT_VERSION_INTEGER()					((EXT_VERSION_MAJOR)<<16 | (EXT_VERSION_MINOR)<<8 | (EXT_VERSION_REVISION))


#define	BL_VERSION_TOKEN						EXT_VERSION(BL_VERSION_MAJOR, BL_VERSION_MINOR, BL_VERSION_REVISION)
#define	EXT_VERSION_TOKEN					EXT_VERSION(EXT_VERSION_MAJOR, EXT_VERSION_MINOR, EXT_VERSION_REVISION)


/* only call EXT_STRINGFY, can't call EXT_TOSTRING; otherwise return string of 'EXT_VERSION_TOKEN' */
#define	EXT_VERSION_STRING		\
			EXT_STRINGIFY(EXT_VERSION_TOKEN)	
#define	BL_VERSION_STRING		\
			EXT_STRINGIFY(BL_VERSION_TOKEN)	


#define	BL_SYSTEM_NAME			"EXT Bootloader"
#define	EXT_SYSTEM_NAME			"EXT Demo System"

//EXT_NEW_LINE EXT_NEW_LINE 

#define	BUILD_DATE_TIME			__DATE__" "__TIME__

#define	EXT_SYSTEM_STRING(sysName, verInfo) 		\
		EXT_NEW_LINE"" sysName" (" \
		"Version: " verInfo "; " \
		"Built: " BUILD_DATE_TIME ")"EXT_NEW_LINE


#define	EXT_OS_NAME		EXT_SYSTEM_STRING(EXT_SYSTEM_NAME, EXT_VERSION_STRING)

#define	EXT_BL_NAME		EXT_SYSTEM_STRING(BL_SYSTEM_NAME, BL_VERSION_STRING)


#define	EXT_TASK_CONSOLE				"console"
#define	EXT_TASK_MAC					"macd"	/* GMAC controller */
#define	EXT_TASK_HTTP					"httpd"
#define	EXT_TASK_TELNET				"telnetd"
#define	EXT_TASK_SYS_CTRL				"sysd"



/** Debug level: ALL messages*/
#define	EXT_DBG_LEVEL_ALL				0x00
#define	EXT_DBG_LEVEL_INFO			0x01
#define	EXT_DBG_LEVEL_WARN			0x02
#define	EXT_DBG_LEVEL_ERROR			0x03
#define	EXT_DBG_LEVEL_FATAL			0x04


#define	EXT_DBG_MASK_LEVEL			0x04
#define	EXT_DBG_LEVEL_OFF			LWIP_DBG_LEVEL_ALL


#define	EXT_DBG_ON					0x80U
#define	EXT_DBG_OFF					0x00U


#define	EXT_DBG_TRACE					0x40U
#define	EXT_DBG_STATE					0x20U
#define	EXT_DBG_FRESH					0x10U
#define	EXT_DBG_HALT					0x08U


/* level used */
#define	EXT_DBG_TYPES_ON				EXT_DBG_ON
#define	EXT_DBG_MIN_LEVEL			EXT_DBG_LEVEL_ALL


/*
* ESC (27, 0x1b) charactor is '\e' or '\x1b'
*/

#define ANSI_COLOR_RED				"\x1b[31m"	/* ESC[31m : red */
#define ANSI_COLOR_GREEN			"\x1b[32m"
#define ANSI_COLOR_YELLOW			"\x1b[33m"
#define ANSI_COLOR_BLUE			"\x1b[34m"
#define ANSI_COLOR_MAGENTA		"\x1b[35m"
#define ANSI_COLOR_CYAN			"\x1b[36m"
#define ANSI_COLOR_RESET			"\x1b[0m"	/* for all colors, other than red, this must be used. April,15,2018. JL*/


#define	ERROR_TEXT_BEGIN			"\t\e[31m ERR:"
#define	ERROR_TEXT_END			"\e[0m"


#define	WARN_TEXT_BEGIN			""ANSI_COLOR_MAGENTA"WARN:"

#define	INFO_TEXT_BEGIN			""ANSI_COLOR_BLUE"INFO:"


#ifndef __EXT_RELEASE__
	#define	EXT_PRINTF(x)						{printf x ;}
	
//	#define	EXT_DEBUGF(fmt, args...)	{printf("[%s-%u] DEBUG: " fmt EXT_NEW_LINE, __FILE__, __LINE__, ## args);}
	#define	EXT_DEBUGF(debug, message)		do { \
                               if ( \
                                   ((debug) & EXT_DBG_ON) && \
                                   ((debug) & EXT_DBG_TYPES_ON) && \
                                   ((s16_t)((debug) & EXT_DBG_MASK_LEVEL) >= EXT_DBG_MIN_LEVEL)) { \
                                 _TRACE_OUT(message); \
                                 if ((debug) & LWIP_DBG_HALT) { \
                                   while(1); \
                                 } \
                               } \
                             } while(0)

                             
	#define	EXT_INFOF(message)		{EXT_PRINTF((ANSI_COLOR_CYAN""));_TRACE_OUT(message);EXT_PRINTF((ANSI_COLOR_RESET));}
	
	#define	EXT_ERRORF(message)		{EXT_PRINTF((ERROR_TEXT_BEGIN"ERROR: "));_TRACE_OUT(message); EXT_PRINTF((ERROR_TEXT_END));}

//	#define	EXT_ASSERT(x)				{printf("Assertion \"%s\" failed at line %d in %s\n", x, __LINE__, __FILE__); while(1);}
	#define	EXT_ASSERT(msg, x)			{if((x)==0) {EXT_PRINTF((ERROR_TEXT_BEGIN"ERROR: "));printf (msg) ;EXT_PRINTF((ERROR_TEXT_END EXT_NEW_LINE)); while(0){};}}
	#define	EXT_ABORT(fmt, args... )		printf("ERROR in " __FILE__ ", line %u:" fmt EXT_NEW_LINE, __LINE__, ##args );while(1){}
#else
	#define	EXT_PRINTF(x)						{;}

	#define	EXT_DEBUGF(debug, message)		{}

	#define	EXT_INFOF(message)				{printf message ;printf(EXT_NEW_LINE);}

	#define	EXT_ERRORF(message)				{printf message ; printf(EXT_NEW_LINE);}
	
//	#define	EXT_ASSERT(x)				{while (1);}
	#define	EXT_ASSERT(msg, x)				{}
	#define	EXT_ABORT(fmt, args... )		{}
#endif

#define	_TRACE_OUT(message)	\
			{EXT_PRINTF(("[%s-%u.%s()]: ", __FILE__, __LINE__, __FUNCTION__) );EXT_PRINTF(message); EXT_PRINTF((EXT_NEW_LINE));}

#define	TRACE()						_TRACE_OUT((EXT_NEW_LINE) )




/* when RELEASE build, only omit the output  */
#define	EXT_DBG_ERRORF(message, expression, handler) do { if (!(expression)) { \
		_TRACE_OUT(message); handler;}} while(0)


#define EXT_ARRAYSIZE(x)		(sizeof(x)/sizeof((x)[0]))


#define CFG_MAKEU32(a,b,c,d) (((int)((a) & 0xff) << 24) | \
                               ((int)((b) & 0xff) << 16) | \
                               ((int)((c) & 0xff) << 8)  | \
                                (int)((d) & 0xff))


#define	CFG_SET_FLAGS(flags, value)	\
		flags |= (value) 

#define	CFG_CLEAR_FLAGS(flags, value)	\
		flags &= ~((value) ) 


#define	EXT_DHCP_IS_ENABLE(runCfg)		\
				((runCfg)->netMode&(EXT_IP_CFG_DHCP_ENABLE))

#define	EXT_CFG_SET_DHCP(runCfg, value)	\
				{ if(value==0) {CFG_CLEAR_FLAGS((runCfg)->netMode,(EXT_IP_CFG_DHCP_ENABLE));} \
				else{CFG_SET_FLAGS((runCfg)->netMode, (EXT_IP_CFG_DHCP_ENABLE));} }


#define ADD_ELEMENT(header, element)	\
	if (header == NULL){					\
		header  = element;				\
		element->next   = NULL;			\
	}									\
	else	{								\
		element->next   = header;		\
		header = element;				\
	}


#define REMOVE_ELEMENT(header, element, type)	\
{type **cp, *c1; cp = &header; \
	while ((*cp) != NULL){  c1 = *cp; \
		if (c1 == element ) \
		{ *cp = element->next;} \
		else	{ cp = &c1->next;} \
	}; }


#define		STR_BOOL_VALUE(bValue)	\
			(((bValue)==0)?"NO":"YES")



#define	IS_STRING_NULL( str)	\
	(((str)==NULL)||(!strlen((str))) )


#define	IS_STRING_EQUAL( str1, str2)	\
	( !strcasecmp((str1), (str2)))


/* use option of -fpack-struct of GCC command options in Rules.mak. 05.07,2018 */

//#define	EXT_PACK_SET(bytes)		#pragma		pack(bytes)

//#define	EXT_PACK_RESET()			#pragma		pack()


//EXT_PACK_SET(1);
#pragma		pack(1)

typedef	enum _boot_mode
{
	BOOT_MODE_BOOTLOADER = 1,
	BOOT_MODE_RTOS,
	BOOT_MODE_TEST
}boot_mode;


#define		_RESET_BTN_RESTORE_FACTORY 				1
#define		_RESET_BTN_STAY_IN_BOOTLOADER			2

#define		RESET_BTN_DELAY_SECONDS					5

#define		RESET_BTN_MODE		_RESET_BTN_RESTORE_FACTORY

typedef	enum
{
	EXT_CFG_MAIN = 0,		/* main configuration in NVRAM */
	EXT_CFG_BACKUP		/* backup configuration in NVRAM */
}EXT_CFG_TYPE;


typedef	struct
{
	unsigned char		major;
	unsigned char		minor;
	unsigned char		revision;
}EXT_FM_VERSION;


typedef	struct
{/* must as 'unsigned', otherwise it output FFFFFFFa1 when print as char */
	unsigned char		address[EXT_MAC_ADDRESS_LENGTH];
}EXT_MAC_ADDRESS;


#define	MAC_ADDR_IS_BOARDCAST(macAddr)		\
	( (macAddr)->address[0]==0xFF && (macAddr)->address[1]==0xFF && (macAddr)->address[4]==0xFF && (macAddr)->address[5]==0xFF  )

#define	MAC_ADDR_IS_EQUAL(macAdd1, macAdd2 )	\
	( (macAdd1)->address[0]==(macAdd2)->address[0] && \
		(macAdd1)->address[1]==(macAdd2)->address[1] && \
		(macAdd1)->address[2]==(macAdd2)->address[2] && \
		(macAdd1)->address[3]==(macAdd2)->address[3] && \
		(macAdd1)->address[4]==(macAdd2)->address[4] && \
		(macAdd1)->address[5]==(macAdd2)->address[5]  )

#define	MAC_ADDR_IS_NULL(macAddr)		\
	( (macAddr)->address[0]==0 && (macAddr)->address[1]==0 && (macAddr)->address[4]==0 && (macAddr)->address[5]==0  )


#if 0//BYTE_ORDER == BIG_ENDIAN
#define _PP_HTONL(x) (x)
#else /* BYTE_ORDER != BIG_ENDIAN */
#define _PP_HTONL(x) ((((x) & 0x000000ffUL) << 24) | \
                     (((x) & 0x0000ff00UL) <<  8) | \
                     (((x) & 0x00ff0000UL) >>  8) | \
                     (((x) & 0xff000000UL) >> 24))
#endif /* BYTE_ORDER == BIG_ENDIAN */

#define IP_ADDR_IS_MULTICAST( addr)  \
		((addr & _PP_HTONL(0xf0000000UL)) == _PP_HTONL(0xe0000000UL))



#define	EXT_UUID_STR_LENGTH		36
/* UUID string  8-4-4-4-12 */

/* 128 bit UUID */
typedef	struct
{
	unsigned char		uuid[16];
}EXT_UUID_T;

typedef	struct
{
	unsigned int		seconds;
	unsigned int		nanoSeconds;
}ExtNmosVersion; /* version of this entity */


typedef	struct
{
	EXT_UUID_T						uuid;
	ExtNmosVersion					version;

}ExtNmosID;

typedef struct
{
	EXT_MAC_ADDRESS		mac;
	unsigned	int				ip;

	unsigned short			vport;
	unsigned short			aport;
	unsigned short			dport;	/* anccilary data port */
	unsigned short			sport;	/* anccilary strea port */
}EXT_VIDEO_CONFIG;

/* firmware update */
typedef	enum
{
	EXT_FM_TYPE_NONE = 0,		/* no update */
	EXT_FM_TYPE_RTOS,
	EXT_FM_TYPE_FPGA,	
	EXT_FM_TYPE_UNKNOWN
}EXT_FM_T;

#ifndef	ARM
#include <stdio.h>		/* FILE * */
#endif

/* write to flash */
typedef struct
{
	unsigned char		type;
//	unsigned	int		startSector;
	
	unsigned char		isWrite;

	unsigned int		size;	/*total length saved in flash */


#ifndef	ARM
	FILE				*fp;
#endif
}EXT_FM_UPDATE;


typedef	enum
{
	EXT_RS232_PARITY_NONE = 0,
	EXT_RS232_PARITY_ODD,
	EXT_RS232_PARITY_EVEN,
}EXT_RS232_PARITY;

#define	EXT_RS232_PAR_STR_NONE		"none"
#define	EXT_RS232_PAR_STR_ODD		"odd"
#define	EXT_RS232_PAR_STR_EVEN		"even"

typedef	enum
{
	EXT_RS232_CHAR_LENGTH_5 = 5,
	EXT_RS232_CHAR_LENGTH_6,
	EXT_RS232_CHAR_LENGTH_7,
	EXT_RS232_CHAR_LENGTH_8
}EXT_RS232_CHAR_LENGTH;

typedef	enum
{
	EXT_RS232_STOP_BITS_1 = 1,
	EXT_RS232_STOP_BITS_2,
	EXT_RS232_STOP_BITS_15,
}EXT_RS232_STOP_BITS;

#define	EXT_BAUDRATE_9600		9600
#define	EXT_BAUDRATE_19200		19200
#define	EXT_BAUDRATE_38400		38400
#define	EXT_BAUDRATE_57600		57600
#define	EXT_BAUDRATE_115200		115200

typedef	enum
{
	EXT_V_FRAMERATE_T_23 = 23,
	EXT_V_FRAMERATE_T_24,
	EXT_V_FRAMERATE_T_25,
	EXT_V_FRAMERATE_T_29 = 29,
	EXT_V_FRAMERATE_T_30,
	EXT_V_FRAMERATE_T_50 = 50,
	EXT_V_FRAMERATE_T_59 = 59,
	EXT_V_FRAMERATE_T_60
}EXT_V_FRAMERATE;


typedef	enum
{/* value definitions are from FPGA */
	EXT_V_COLORSPACE_YCBCR_422		= 0,
	EXT_V_COLORSPACE_YCBCR_444 		= 1,
	EXT_V_COLORSPACE_RGB			= 2,
	EXT_V_COLORSPACE_YCBCR_420		= 3,
	EXT_V_COLORSPACE_XYZ			= 4,
	EXT_V_COLORSPACE_KEY			= 5,
	EXT_V_COLORSPACE_CL_YCBCR_422	= 8,
	EXT_V_COLORSPACE_CL_YCBCR_444	= 9,
	EXT_V_COLORSPACE_CL_YCBCR_420	= 11
}EXT_V_COLORSPACE;


typedef	enum
{
	EXT_V_DEPTH_8		= 8,	
	EXT_V_DEPTH_10	= 10,	
	EXT_V_DEPTH_12	= 12,	
	EXT_V_DEPTH_16	= 16
}EXT_V_DEPTH;



typedef	enum
{
	CMN_STR_T_RS_PARITY = 0,
	CMN_STR_T_V_COLORSPACE,
}CMN_STR_TYPE;


const char *extCmnStringFind(CMN_STR_TYPE strType, unsigned short type);
//const 
short extCmnTypeFind(CMN_STR_TYPE  strType, char *str);


#define	CMN_FIND_RS_PARITY(type)		\
	extCmnStringFind(CMN_STR_T_RS_PARITY, (type) )


#define	CMN_FIND_V_COLORSPACE(type)		\
	extCmnStringFind(CMN_STR_T_V_COLORSPACE, (type) )


#define	CMN_FIND_STR_RS_PARITY(str)		\
	extCmnTypeFind(CMN_STR_T_RS_PARITY, (str) )


#define	CMN_FIND_STR_V_COLORSPACE(str)		\
	extCmnTypeFind(CMN_STR_T_V_COLORSPACE, (str) )



#define	EXT_INVALIDATE_STRING_TYPE			0xFFFF

typedef struct
{
	const unsigned short		type;
	const char				*name;
}EXT_CONST_STR;




/** Input parameters when initializing RS232 and similar modes. */
typedef struct _MuxRS232
{
	unsigned int		baudRate;
	unsigned 	char		charLength;

	unsigned char		parityType;
	/** 1, 1.5 or 2 stop bits. */
	unsigned char		stopbits;
}MuxRs232Cfg;


/* runtime parameters which can't be saved in flash */
typedef	struct
{
	unsigned short		vWidth;
	unsigned short		vHeight;

	unsigned char			vFrameRate;
	unsigned char			vColorSpace;
	unsigned char			vDepth;

	unsigned char			vIsInterlaced;
	unsigned char			vIsSegmented;

	unsigned short		aSampleRate;
	unsigned char			aChannels;
	unsigned char			aDepth;		/* 16, 24 bits, etc. */

	unsigned char			isConnect;
	
}MuxRunTimeParam;



/* IP address, port number and state are all defined as unsigned type */
struct	_EXT_RUNTIME_CFG
{
	unsigned char			magic[EXT_MAGIC_SIZE];

	/* in order to guanratee the compatible between bootloader and RTOS, put updateInfo at the beginning of this structure */
	EXT_FM_UPDATE		firmUpdateInfo;

	unsigned char			isTx;
	unsigned char			isMCast;
	unsigned char			isUpdate;	/*isUpdate: enter into bootloader and wait for further commands; otherwise, enter into OS directly */
	unsigned char			isDipOn;
	unsigned char			netMode;

#if 0
	EXT_MAC_ADDRESS	macAddress;
	
	unsigned int			ipAddress;
	
	unsigned int			destIp;
	EXT_MAC_ADDRESS	videoMacLocal;
	EXT_MAC_ADDRESS	videoMacDest;

	unsigned int			videoIpLocal;
	unsigned int			videoIpDest;

	unsigned short		videoPortLocal;
	unsigned short		videoPortDest;
	unsigned short		audioPortLocal;
	unsigned short		audioPortDest;
#else
	EXT_VIDEO_CONFIG	local;
	unsigned int			ipMask;
	unsigned int			ipGateway;
	
	EXT_VIDEO_CONFIG	dest;	/* only for TX */
#endif

#if 0
	unsigned int			mcIp;	/* multicast IP */
	unsigned short		mcPort;	/* port of multicast */
#endif

	/* following fields are not modified by SetParams command */
	char					name[32];	/* can be modified */
	char					model[32];
	EXT_FM_VERSION		version;

	char					user[EXT_USER_SIZE];
	char					password[EXT_PASSWORD_SIZE];

	char					superUser[EXT_USER_SIZE];
	char					superPassword[EXT_PASSWORD_SIZE];

	unsigned char			isStoreDefaultCfg;
	
	/* following fields are not transmitted to client */
	unsigned short		httpPort;

	MuxRs232Cfg			rs232Cfg;
	unsigned char			isConfigFpga;	/* whether configure FPGA when MCU startup. Just for FPGA debugging */

	ExtNmosID			nodeID;
	ExtNmosID			deviceID;

	/* in order to make old bootloader compatible with new RTOS, all new field must be added after here */
	
	unsigned char			endMagic[EXT_MAGIC_SIZE];


	/* following fields are only for runtime and not save in NVRAM */
	unsigned	int			debugOptions;
	
	unsigned int			currentTimestamp;	/* ms */
	char					currentHttpConns;	/* number of current HTTP connection */

	boot_mode			bootMode;

	unsigned char			*bufRead;	/* read buffer for Xmodem or SPI flash read when update RTOS in EFC flash */
	unsigned char			*bufWrite;	/* write buffer for SPI flash write or EFC flash write */
	unsigned short		bufLength;

	MuxRunTimeParam		runtime;

	void					*data;
};//__attribute__((packed));

//EXT_PACK_RESET();

// #pragma		pack()

/* update size by setParams command */
#define		EXT_RUNTIME_CFG_UPDATE_SIZE		(offsetof(struct _EXT_RUNTIME_CFG, name))

#define		EXT_RUNTIME_CFG_WRITE_SIZE		(offsetof(struct _EXT_RUNTIME_CFG, debugOptions))


//#if ( sizeof(EXT_FM_VERSION) != 3 )
//	#error Data structure is packed wrong
//#endif

typedef char assertion_on_mystruct[( sizeof(EXT_FM_VERSION)==3  )*2-1 ];

#define DUMB_STATIC_ASSERT(test)	typedef char assertion_on_mystruct[( !!(test) )*2-1 ]


//DUMB_STATIC_ASSERT( sizeof(mystruct)==1024 );
//DUMB_STATIC_ASSERT( sizeof(my_other_struct)==23 );
//DUMB_STATIC_ASSERT( sizeof(minimum_size_struct) >= 23 );

//static_assert(sizeof(EXT_FM_VERSION) == 3,   "Check your assumptions");


typedef	struct _EXT_RUNTIME_CFG		EXT_RUNTIME_CFG;


typedef	char (*MuxDelayJob)(void *data);


char extSysAtoInt8(const char *str, unsigned char *value);
char	extMacAddressParse(EXT_MAC_ADDRESS *macAddress, const char *macStr);

void extCfgFromFactory( EXT_RUNTIME_CFG *cfg );
void extCfgInitAfterReadFromFlash(EXT_RUNTIME_CFG *runCfg);


void	extNmosIdGenerate(ExtNmosID *nmosId, EXT_RUNTIME_CFG *runCfg);

unsigned int cmnMuxCRC32b(void *message, int len);


char extTxMulticastIP2Mac(EXT_RUNTIME_CFG *runCfg);


extern	EXT_RUNTIME_CFG			extRun;


#define	EXT_DEBUG_FLAG_IP_IN					(1<<0)
#define	EXT_DEBUG_FLAG_IP_OUT				(1<<1)
#define	EXT_DEBUG_FLAG_UDP_IN				(1<<2)
#define	EXT_DEBUG_FLAG_UDP_OUT				(1<<3)
#define	EXT_DEBUG_FLAG_TCP_IN				(1<<4)
#define	EXT_DEBUG_FLAG_TCP_OUT				(1<<5)


#define	EXT_DEBUG_FLAG_IGMP					(1<<8)		

/* bit31~16 for software debugging */
#define	EXT_DEBUG_FLAG_CMD					(1<<16)		/* debug IP CMD */	



#define	EXT_DEBUG_IS_ENABLE(flag)		\
				((extRun.debugOptions&(flag)) )


#define	EXT_DEBUG_SET_DISABLE(_optFlag)	\
				CFG_CLEAR_FLAGS(extRun.debugOptions, (_optFlag) )

#define	EXT_DEBUG_SET_ENABLE(_optFlag)	\
				CFG_SET_FLAGS(extRun.debugOptions, (_optFlag) )


#define	EXT_IS_TX(runCfg)	\
			((runCfg)->isTx != 0 )


#define	UUID_IS_NULL(_uuid)	\
		((_uuid)->uuid[0]==0 && (_uuid)->uuid[1]==0 && (_uuid)->uuid[2]==0 && (_uuid)->uuid[4]==0 && (_uuid)->uuid[15]==0 )

#ifndef __EXT_RELEASE__
#define	CONSOLE_DEBUG_MEM(buffer, size, address, msg)	\
	{printf("[%s-%u.%s()]-%s: "EXT_NEW_LINE, __FILE__, __LINE__, __FUNCTION__, (msg) );bspConsoleDumpMemory((buffer), (size), (address));}

#else
#define	CONSOLE_DEBUG_MEM(buffer, size, address, msg)	

#endif


#endif

