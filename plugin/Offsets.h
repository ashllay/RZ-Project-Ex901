#include "StdAfx.h"

#ifdef _GS
//-----------------------------------------------------------//
//#         Personalisando Gameserver        # //
//-----------------------------------------------------------//
#define GREENBARTEXTCOLOR					(0x00A139A8+1)//gs10
#define GREENBAR							(0x00A133D7+1)//gs10
#define oBarText							(0x00FD4124)//gs10
#define CLOSE_TIME							(0x00A17C0A+3)//gs10
#define ogObjViewportPaint					0x007E51F6//10
#define oGameMainInit						0x007D2D26//gs10
#define	oCheckShopServerReconnect			0x00C778E5
//-----------------------------------------------------------//
//			Events
//-----------------------------------------------------------//
#define	oDoppelminParty								(0x006F3744+6)//gs04	
//bloodCastle Time
#define GS_BLOODREMAIN				(0x008CC9B5+2)
#define GS_BLOODREMAIN2				(0x008CC9DE+2)
#define GS_BLOODREMAIN3				(0x008CCA0C+2)
#define	oDoppelminParty0			(0x00C3F7B8+6)
#define	oDoppelminParty1			(0x00C24721+6)
#define	oDoppelminParty2			(0x00C2476A+6)
//--------------------------------------------
#define GS_CCTimeRemain				(0x00B5F099+4)
#define	oCcMinPlayers				(0x00B67120+3)
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
//================================================//
//Shops											  //
//================================================//
#define	oShop0_Path			0x00B20899
#define	oShop1_Path			0x00B208B3
#define	oShop2_Path			0x00B208CD
#define	oShop3_Path			0x00B208E7
#define	oShop4_Path			0x00B20901
#define	oShop5_Path			0x00B2091B
#define	oShop6_Path			0x00B20935
#define	oShop7_Path			0x00B2094F
#define	oShop8_Path			0x00B20969
#define	oShop9_Path			0x00B20983
#define	oShop10_Path			0x00B2099D
#define	oShop11_Path			0x00B209B7
#define	oShop12_Path			0x00B209D1
#define	oShop13_Path			0x00B209EB
#define	oShop14_Path			0x00B20A05
#define	oShop15_Path			0x00B20A1F
#define	oShop16_Path			0x00B20A39
#define	oShop17_Path			0x00B20A53
#define	oShop18_Path			0x00B20A6D
#define	oShop19_Path			0x00B20A87
#define	oShop20_Path			0x00B20AA1
#define	oShop21_Path			0x00B20ABB
#define	oShop22_Path			0x00B20AD5
#define	oShop23_Path			0x00B20AEF
#define	oShop24_Path			0x00B20B09
#define	oShop25_Path			0x00B20B23
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
//================================================//
//Shops											  //
//================================================//
#define	oShop0_Path			0x00B68EF9
#define	oShop1_Path			0x00B68F13
#define	oShop2_Path			0x00B68F2D
#define	oShop3_Path			0x00B68F47
#define	oShop4_Path			0x00B68F61
#define	oShop5_Path			0x00B68F7B
#define	oShop6_Path			0x00B68F95
#define	oShop7_Path			0x00B68FAF
#define	oShop8_Path			0x00B68FC9
#define	oShop9_Path			0x00B68FE3
#define	oShop10_Path			0x00B68FFD
#define	oShop11_Path			0x00B69017
#define	oShop12_Path			0x00B69031
#define	oShop13_Path			0x00B6904B
#define	oShop14_Path			0x00B69065
#define	oShop15_Path			0x00B6907F
#define	oShop16_Path			0x00B69099
#define	oShop17_Path			0x00B690B3
#define	oShop18_Path			0x00B690CD
#define	oShop19_Path			0x00B690E7
#define	oShop20_Path			0x00B69101
#define	oShop21_Path			0x00B6911B
#define	oShop22_Path			0x00B69135
#define	oShop23_Path			0x00B6914F
#define	oShop24_Path			0x00B69169
#define	oShop25_Path			0x00B69183
#endif

#ifdef _GS

#define GameMainInit			((void(*)(HWND)) 0x00B397B0)//gs10

#define	oProtocolCore			0x007D148A
#define ProtocolCore            ((void(*)(unsigned char Protocol, LPBYTE aRecv, int Size, int aIndex, int Encrypt, int Serial)) 0x0084B7A0)//10
#define	oDataSend				0x007DC3EE
#define DataSend                ((void(*)(int aIndex, char *lpMsg, int dwSize)) 0x00980920)//10

#define DataSendAll             ((void(*)(LPBYTE lpMsg, int iMsgSize)) 0x0084F940)//10
#define	GCServerMsgStringSend	((void(*)(LPSTR  szMsg, int aIndex, BYTE type))0x00850C30)//10
#define	GCServerMsgStringSendEx	((void(*)(int aIndex, char Type, char *szFormat,...)) 0x00850CA0)
#define GCMoneySend				((void(*)(DWORD,int))0x00853FA0)//10
#define gObjTeleport			((void(*)(int, int, int, int))0x00A6F470)//10
#define LogAddFuncColor			((void(*)(BYTE Color, char* szLog, ...)) 0x00A0BF50)//10
#define LogAddTD 				((void(*)(char* szLog, ...)) 0x00A0BDE0)
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
#define PetItemSerialCreateSend	((void(*)(int aIndex, char MapNumber, char X, char Y, int Type, char Level, char Dur, char Op1, char Op2, char Op3, int LootIndex, char NewOption, char SetOption)) 0x00838DD0)

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

#define gObjIsConnected					((int(*)(int aIndex)) 0x00A260A0)

//#define	gObjDel						((short(*)(int index))0x00A258E0)
//expansion items
#define	CGUseItemRecv					((void(*)(PMSG_USEITEM *lpMsg, int aIndex))	0x0087F580)
#define	GDUpdateExtendedInvenCount		((void(*)(OBJECTSTRUCT *lpObj, char btExtendedInvenCount, unsigned int dwEventIndex, int iItemPos, char bBuyAtInGameShop, char bIsReplace))0x00842610) // idb
#define	GDUpdateExtendedWarehouseCount	((void(*)(OBJECTSTRUCT *lpObj, char btExtendedWarehouseCount, unsigned int dwEventIndex, int iItemPos, char bBuyAtInGameShop, char bIsReplace))0x00842A00)
#define	GCInventoryItemDeleteSend		((void(*)(int aIndex, char pos, char flag))0x008872A0) // idb
//chasshop cards
//#define	DataServerSetAccountInfo		((void(*)(OBJECTSTRUCT *lpObj, int aIndex, char btCharacterType))0x008422E0)
//#define	GDUpdateCharacterSlotCount		((void(*)(OBJECTSTRUCT *lpObj, char btAddSlotCount, unsigned int dwEventIndex))0x008424D0)

//CashShop Item
#define ItemGetSize						((void(*)(int ItemType, int & Width, int & Height)) 0x00B17510)
#define CheckInventoryEmptySpace		((int(*)(LPOBJ lpObj, int ItemHeight, int ItemWidth)) 0x00A4A8C0)

//Buff and Period Items
#define	oGetEffectDataFromItem			0xDA4D448//revised
#define CBuff_GetEffectDataFromItem		((BUFF_EFFECT_DATA*(__thiscall*)(LPVOID This, int ItemCode)) 0x00BFC4D0)//revised
#define	oSetPeriodItemInfo				0xDB7A528//ok
#define CPeriodItem_SetPeriodItemInfo	((bool(__thiscall*)(LPVOID This, LPOBJ lpObj, int ItemCode, int Serial, int Duration)) 0x00C5FD60)//fixed
//DataServer
#define	oDBSockMngSend					0x10FF560
#define DBSockMng_Send					((int(__thiscall*)(LPVOID This, char *Buff, int Size)) 0x008306E0)
#define	oDataServerProtocolCore			0x007D407C
#define DataServerProtocolCore			((void(*)(char protoNum, LPBYTE aRecv, int aLen)) 0x008308A0)//ok

#define	gObjAddBuffEffect				((char(*) (OBJECTSTRUCT *lpObj, int iBuffIndex, char EffectType1, int EffectValue1, char EffectType2, int EffectValue2, int Duration))0x00BFCCD0)
//reload command
#define	ShopDataLoad					((int(*)())0x00B20890) // idb
#define GameMonsterAllCloseAndReLoad	((void(*)())0x00B3C690)
#else
#define GameMainInit			((void(*)(HWND)) 0x00B81C40)//gscs10
#define LogAddFuncColor			((void(*)(BYTE Color, char* szLog, ...)) 0x00A53640)//gscs10
#define DataSendAll             ((void(*)(LPBYTE lpMsg, int iMsgSize)) 0x0087A4B0)//gscs10
#define	GCServerMsgStringSend	((void(*)(LPSTR  szMsg, int aIndex, BYTE type))0x0087B7A0)//gscs10
#define ChatTargetSend			((void(*)(OBJECTSTRUCT *gObj, char*, DWORD)) 0x0087A540)//gcs
#define	oDataServerProtocolCore			0x007FC54A//ok
#define DataServerProtocolCore			((void(*)(char protoNum, LPBYTE aRecv, int aLen)) 0x00859D50)//ok

#define	oProtocolCore			0x007F9750//cs
#define ProtocolCore            ((void(*)(unsigned char Protocol, LPBYTE aRecv, int Size, int aIndex, int Encrypt, int Serial))0x008762F0)//10
#define	oDataSend				0x00804EED//cs
#define DataSend                ((void(*)(int aIndex, char *lpMsg, int dwSize))	0x009C8000)//10
#define gObjIsConnected					((int(*)(int aIndex)) 0x00A6DB70)

//expansion items
#define	CGUseItemRecv					((void(*)(PMSG_USEITEM *lpMsg, int aIndex))	0x008AA4D0)
#define	GDUpdateExtendedInvenCount		((void(*)(OBJECTSTRUCT *lpObj, char btExtendedInvenCount, unsigned int dwEventIndex, int iItemPos, char bBuyAtInGameShop, char bIsReplace))0x0086D160) // idb
#define	GDUpdateExtendedWarehouseCount	((void(*)(OBJECTSTRUCT *lpObj, char btExtendedWarehouseCount, unsigned int dwEventIndex, int iItemPos, char bBuyAtInGameShop, char bIsReplace))0x0086D550)
#define	GCInventoryItemDeleteSend		((void(*)(int aIndex, char pos, char flag))0x008B22E0) // idb
//commands
#define	ItemSerialCreateSend	((void(*)(int aIndex, char MapNumber, char x, char y, int type, char level, char dur, char Op1, char Op2, char Op3, int LootIndex, char NewOption, char SetOption, int lDuration, unsigned int dwEventIndex, char *SocketOption, char MainAttribute))0x00861F30)
#define PChatProc				((void(*)(PMSG_CHATDATA* lpChat, short aIndex)) 0x0087A610)//
#define GCPkLevelSend			((void(*)(int,unsigned char)) 0x0087E0E0)
#define gObjViewportListProtocolCreate ((void(*)(OBJECTSTRUCT* tObj))0x00AAEB60) // Skin
#define GCMoneySend				((void(*)(DWORD,int))0x0087EB10)//10
#define gObjTeleport			((void(*)(int, int, int, int))0x00AB86E0)//10
#define gObjMoveGate			((void(*)(int, int))0x00AB4320)//10
#define	CloseClient             ((void(*)(DWORD)) 0x009C8EE0)//void __cdecl CloseClient(int index)
#define PetItemSerialCreateSend	((void(*)(int aIndex, char MapNumber, char X, char Y, int Type, char Level, char Dur, char Op1, char Op2, char Op3, int LootIndex, char NewOption, char SetOption)) 0x00862280)

//add commands
#define gObjCalCharacter        ((void(*)(int aIndex))	0x00B0E840) //
#define gObjSetBP				((int(*)(int aIndex))0x00A63050)
#define GCReFillSend			((int(*)(int aIndex, WORD Life, BYTE Ipos, unsigned char flag,  WORD wShield))0x008B2150)
#define GCLevelUpMsgSend		((void(*)(int,unsigned char))0x0087DB30)
#define GCManaSend				((int(*)(int aIndex, short Mana, BYTE Ipos, unsigned char flag,  WORD BP))0x008B21F0)
//reload commands
#define	ShopDataLoad					((int(*)())0x00B68EF0) // idb
#define GameMonsterAllCloseAndReLoad	((void(*)())0x00B84E50)
#endif