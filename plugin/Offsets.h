#include "StdAfx.h"

#ifdef _GS
//-----------------------------------------------------------//
//#         Personalisando Gameserver        # //
//-----------------------------------------------------------//
#define GREENBARTEXTCOLOR						(0x00A139A8+1)//gs10
#define GREENBAR								(0x00A133D7+1)//gs10
#define oBarText									(0x00FD4124)//gs10

#define CLOSE_TIME									(0x00A17C0A+3)//gs10

#define ogObjViewportPaint						0x007E51F6//10
#define oGameMainInit						0x007D2D26//gs10
//-----------------------------------------------------------//
//			Events
//-----------------------------------------------------------//
#define	oDoppelminParty								(0x006F3744+6)//gs04	
//bloodCastle Time
#define GS_BLOODREMAIN			(0x008CC9B5+2)
#define GS_BLOODREMAIN2			(0x008CC9DE+2)
#define GS_BLOODREMAIN3			(0x008CCA0C+2)
//--------------------------------------------
#define GS_CCTimeRemain (0x00B5F099+4)
#define	oCcMinPlayers	(0x00B67120+3)
//-----------------------------------------------------------//
//			LogProc
//-----------------------------------------------------------//
#define oLogTextPaintProc						0x007D1D6D//gs10
#define oLogTextAdd								0x007E3432//gs10
//-----------------------------------------------------------//
//			LogProc
//-----------------------------------------------------------//
#define	GCPartyDelUserSend	((void(*) (int aIndex))	0x00871590)
#define	CGPartyListAll		((void(*) (int pnumber)) 0x00870170)//10
//================================================//
//Jewel Rates									  //
//================================================//
#define GS_SOUL_RATE_NORMAL		(0x00A717AF+3)//10
#define GS_SOUL_RATE_SPECIAL	(0x00A71772+3)//10//fixed 18-01
#define GS_SOUL_RATE_SOCKET		(0x00A717A3+3)//10//fixed 18-01
#define GS_SOUL_LUCK_ADD		(0x00A71712+2)//10//fixed 18-01
#define GS_JOL_FAIL_RATE		(0x00A72070+3)//10
#else
//-----------------------------------------------------------//
//#         Personalisando Gameserver        # //
//-----------------------------------------------------------//
#define GREENBARTEXTCOLOR						(0x00A5B098+1)//gscs10
#define GREENBAR								(0x00A5AAC7+1)//gscs10
#define oBarText								(0x01055F3C)//gscs10

#define CLOSE_TIME								(0x00A5F43A+3)//gscs10

#define oGameMainInit						0x007FB10E//gscs10
//================================================//
//Jewel Rates									  //
//================================================//
#define GS_SOUL_RATE_NORMAL		(0x00ABAA1F+3)//cs10
#define GS_SOUL_RATE_SPECIAL	(0x00ABA9E2+3)//cs10
#define GS_SOUL_RATE_SOCKET		(0x00ABAA13+3)//cs10
#define GS_SOUL_LUCK_ADD		(0x00ABA982+2)//cs10
#define GS_JOL_FAIL_RATE		(0x00ABB2E0+3)//cs10
#endif

#ifdef _GS

#define GameMainInit			((void(*)(HWND)) 0x00B397B0)//gs10

#define	oProtocolCore			0x007D148A
#define ProtocolCore            ((void(*)(BYTE protoNum, BYTE *aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)) 0x0084B7A0)//10
#define	oDataSend				0x007DC3EE
#define DataSend                ((void(*)(int aIndex, LPBYTE lpMsg, DWORD dwSize)) 0x00980920)//10

#define DataSendAll             ((void(*)(LPBYTE lpMsg, int iMsgSize)) 0x0084F940)//10
#define	GCServerMsgStringSend	((void(*)(LPSTR  szMsg, int aIndex, BYTE type))0x00850C30)//10
#define GCMoneySend				((void(*)(DWORD,int))0x00853FA0)//10
#define gObjTeleport			((void(*)(int, int, int, int))0x00A6F470)//10
#define LogAddFuncColor			((void(*)(BYTE Color, char* szLog, ...)) 0x00A0BF50)//10
#define gObjMoveGate			((void(*)(int, int))0x00A6B350)//10
//#define	Move					((bool(*)(bool, int MoveNum))0x00644070)
#define	CloseClient             ((void(*)(DWORD)) 0x009816C0)//void __cdecl CloseClient(int index)
//add commands
#define gObjCalCharacter        ((void(*)(int aIndex))	0x00AC4900) //
#define gObjSetBP				((int(*)(int aIndex))0x00A1B7B0)
#define GCReFillSend			((int(*)(int aIndex, WORD Life, BYTE Ipos, unsigned char flag,  WORD wShield))0x00887110)
#define GCLevelUpMsgSend		((void(*)(int,unsigned char))0x00852FC0)
#define GCManaSend				((int(*)(int aIndex, short Mana, BYTE Ipos, unsigned char flag,  WORD BP))0x008871B0)
//----------------------------------------
//
#define GDGuildNoticeSave		((void(*)(char* Name, char* MSG)) 0x008AAAA0)
#define	ItemSerialCreateSend	((void(*)(int aIndex, char MapNumber, char x, char y, int type, char level, char dur, char Op1, char Op2, char Op3, int LootIndex, char NewOption, char SetOption, int lDuration, unsigned int dwEventIndex, char *SocketOption, char MainAttribute))0x00838A80)
#define PChatProc				((void(*)(PMSG_CHATDATA* lpChat, short aIndex)) 0x0084FAA0)//
#define GCPkLevelSend			((void(*)(int,unsigned char)) 0x00853570)
#define ChatTargetSend			((void(*)(OBJECTSTRUCT *gObj, char*, DWORD)) 0x0084F9D0)
#define gObjViewportListProtocolCreate ((void(*)(OBJECTSTRUCT* tObj))0x00A65D30) // Skin
//offtrade
#define oCGPShopAnsClose				0x007D20C9//ok
#define oResponErrorCloseClient			0x007DA521//ok
#define oCloseClient2					0x007EF80E//ok
#define oCSPJoinIdPassRequest			0x007EB9FC//ok
#define ogObjDel						0x007DA035//ok
#define ogObjCloseSet					0x007E216D//ok

#define gObjDel						((short(*) (int)) 0x00A258E0)
#define CGPShopAnsClose				((void(*)(int,BYTE))0x0086A7C0)//ok
#define ResponErrorCloseClient		((void(*)(int))0x00981800)//ok
#define CloseClient2_Ex				((void(*)(_PER_SOCKET_CONTEXT*,int))0x009815B0)//void __cdecl CloseClient(_PER_SOCKET_CONTEXT *lpPerSocketContext)
#define CSPJoinIdPassRequest		((void(*)(PMSG_IDPASS *lpMsg, int aIndex)) 0x00851400)//ok
#define	DataEncryptCheck			((int(*)(int aIndex, char protoNum, int Encrypt))0x0084B730)
//#define	gObjDel						((short(*)(int index))0x00A258E0)
//--
#else
#define GameMainInit			((void(*)(HWND)) 0x00B81C40)//gscs10
#define LogAddFuncColor			((void(*)(BYTE Color, char* szLog, ...)) 0x00A53640)//gscs10
#define DataSendAll             ((void(*)(LPBYTE lpMsg, int iMsgSize)) 0x0087A4B0)//gscs10
#define	GCServerMsgStringSend	((void(*)(LPSTR  szMsg, int aIndex, BYTE type))0x0087B7A0)//gscs10
#define ChatTargetSend			((void(*)(OBJECTSTRUCT *gObj, char*, DWORD)) 0x0087A540)//gcs

#define	oProtocolCore			0x007F9750//cs
#define ProtocolCore						((void(*)(BYTE,PBYTE,DWORD,...))					0x008762F0)//10
#define	oDataSend				0x00804EED//cs
#define DataSend						((void(*)(DWORD aIndex,PBYTE Packet,DWORD Size))	0x009C8000)//10
#endif