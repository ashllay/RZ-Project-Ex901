#ifndef PROTOC_H
#define PROTOC_H	   								

#include "User.h"
#include "Prodef.h"

struct PMSG_USEITEM
{
	PBMSG_HEAD h;
	BYTE inventoryPos;	// 3
	BYTE invenrotyTarget;	// 4
	BYTE btItemUseType;	// 5
};

struct SDHP_ANS_SET_EXTENDEDINVEN_COUNT
{
	PBMSG_HEAD h;
	WORD Number;
	BYTE Result;
	BYTE ExtendedInvenCount;
	DWORD EventIndex;
	int ItemPos;
	BYTE BuyAtInGameShop;
	BYTE IsReplace;
};

void ProtocolCoreEx(char ProtoNum, LPBYTE aRecv, int aLen, int aIndex, int Encrypt, int Serial);
int	DataSendEx(int aIndex, LPBYTE lpMsg, DWORD dwSize);
void CGUseItemRecvEx(PMSG_USEITEM* lpMsg, int aIndex);

#endif