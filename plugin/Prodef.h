//#include "StdAfx.h"

#ifndef _PRODEF_H
#define _PRODEF_H

#define OBJECT_MAXRANGE(aIndex) ( ((aIndex) < 0 )?FALSE: ( (aIndex) > OBJ_MAX -1 )?FALSE:TRUE   )
void BuxConvert(char* buf, int size);
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSetBE(LPBYTE lpBuf, BYTE head,int size);
void PHeadSubSetB(LPBYTE lpBuf,BYTE Head,BYTE sub,BYTE Size);
void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size);

#define SLOT_EMPTY -1
#define PLAYER_EMPTY  0
#define PLAYER_CONNECTED 1
#define PLAYER_LOGGED 2
#define PLAYER_PLAYING 3

#define MAX_ACCOUNT_LEN 10
#define MAX_ITEM_LEVEL	15
#define MAX_TYPE_ITEMS  16
#define MAX_SUBTYPE_ITEMS 512
#define MAX_PLAYER_EQUIPMENT 12

#define MAX_ITEMS (MAX_TYPE_ITEMS*MAX_SUBTYPE_ITEMS)


#define ITEMGET(x,y)       ((x)*512+(y))
#define SET_NUMBERH(x)     ((BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x)     ((BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x)    ((WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x)    ((WORD)((DWORD)(x) & 0xFFFF) )
#define MAKE_NUMBERW(x,y)  ((WORD)(((BYTE)((y)&0xFF)) |   ((BYTE)((x)&0xFF)<<8 )))
#define MAKE_NUMBERDW(x,y) ((DWORD)(((WORD)((y)&0xFFFF)) | ((WORD)((x)&0xFFFF)<<16)))
#define MAKEQWORD(a, b)    ((__int64)(((DWORD)((__int64)(a) & 0xffffffff)) | ((__int64)((DWORD)((__int64)(b) & 0xffffffff))) << 32))  
#define LODWORD(l)         ((DWORD)(__int64(l) & __int64(0xffffffff)))   
#define HIDWORD(l)         ((DWORD)(__int64(l) >> __int64(32)))   

// ADVANCE DEVIRVATED
struct PBMSG_HEAD
{
public:
	void Set(LPBYTE lpBuf, BYTE Head, BYTE Size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = Size;
		lpBuf[2] = Head;
	};

	void SetE(LPBYTE lpBuf, BYTE Head, BYTE Size)
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = Size;
		lpBuf[2] = Head;
	};

	BYTE c;
	BYTE size;
	BYTE headcode;
};



struct PWMSG_HEAD	// Packet - Word Type
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};



struct PBMSG_HEAD2 
{
public:
	void Set(LPBYTE lpBuf, BYTE Head, BYTE Sub, BYTE Size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = Size;
		lpBuf[2] = Head;
		lpBuf[3] = Sub;
	};

	void SetE(LPBYTE lpBuf, BYTE Head, BYTE Sub, BYTE Size)
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = Size;
		lpBuf[2] = Head;
		lpBuf[3] = Sub;
	};

	BYTE c;
	BYTE size;
	BYTE headcode;
	BYTE subcode;
};

struct PWMSG_HEAD2
{
public:

	void Set(LPBYTE lpBuf, BYTE Head, BYTE Sub, int Size){
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(Size);
		lpBuf[2] = SET_NUMBERL(Size);
		lpBuf[3] = Head;
		lpBuf[4] = Sub;
	}

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
	BYTE subcode;
};

struct PMSG_DEFAULT
{
	PBMSG_HEAD h;
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PMSG_CHATDATA_WHISPER
{
	PBMSG_HEAD h;	// C1:02
	char id[10];	// 3
	char chatmsg[60];	// D  
};

struct PMSG_CHATDATA
{
	PBMSG_HEAD h;	//	
	char chatid[10];	//	3
	char chatmsg[60];	//	D
};

struct PMSG_NOTICE
{
	PBMSG_HEAD h;
	BYTE type;
	BYTE btCount;
	WORD wDelay;
	int dwColor;
	BYTE btSpeed;
	char Notice[256];
};

struct PMSG_TEST
{
	PWMSG_HEAD h;
	char testbuf[1996];	// 4
	int count;	// 7D0
};

namespace LOG
{
	enum COLORS
	{
		BLACK = 1,
		RED = 2,
		GREEN = 3,
		BLUE = 4,
		DARKRED = 5,
		DARKBLUE = 6,
		PINK = 7
	};
};

//Configs Defines // 
#define RZItems				"..\\RZData\\Items.ini"	
#define RZGS				".\\GameServer.ini"
#define RZCommon			"..\\RZData\\Common.ini"
#define RZLog				".\\Log"
#define RZEvents			"..\\RZData\\Events.ini"

#define RZCmd				"..\\RZData\\Commands.ini"
#define RZGM				"..\\RZData\\GMSystem.txt"
#define RZPkClear			"..\\RZData\\PkClearGuard.ini"
#endif