#include "Stdafx.h"
#include "User.h"
#include "UserEx.h"

LPOBJEX * gObjEx;

int POBJEX(int aIndex)
{
	if(aIndex >= OBJ_MIN)
	{
		return aIndex-OBJ_MIN;
	}

	return 0;
}

CUserEx UserEx;

void CUserEx::Init()
{
	gObjEx = new LPOBJEX[MAX_OBJ_EX];

	for(int i=OBJ_MIN; i < OBJ_MAX;i++)
	{
		gObjEx[POBJEX(i)].Clear();
	}
	
	Console.Log("LPOBJEX Size : 0x%X",sizeof(LPOBJEX));
	Console.Log("[UserEx] All objects cleared");
}

void CUserEx::Connect(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex)) return;
	if(!gObjIsConnected(aIndex)) return;
			
	//LPOBJ * lpObj = (LPOBJ*)POBJ(aIndex);
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	//Clear External Objectstructure
	LPOBJEX * lpObjEx = &gObjEx[POBJEX(aIndex)];
	lpObjEx->Clear();

	//LogAddC(LOG::BLACK,"[UserEx](%s)(%s) Player Connect (%d,%d)",lpObj->AccountID,lpObj->Name,lpObj->Index,POBJEX(aIndex));

	//GCServerMsgStringSendEx(aIndex,1,"Server powered by XtremeCoderz");
	//GCServerMsgStringSendEx(aIndex,0,CommonServer.ConnectMessage);
	//Send Player enter In Game
	//Msg.Send(POST::WHISHPER,-1,Msg.Get(CMSG::ETC,0),lpObj->Name);

	//AutoAdd Helper Extension
	/*if(CommonServer.AddHelperExtensionBuff == true)
	{
		gObjAddBuffEffect(lpObj,BUFFTYPE_MACRO_PAID_EXTENSION,0,0,0,0,((3600 * 24) * 30));
	}*/
#if(COMPILE_CASHSHOP==1)

#endif

	//Request UserEx Data
	//this->RequestExData(aIndex);

	//Request VIP
	//VIPSystem.RequestVIP(aIndex);
}
/*
void CUserEx::RequestExData(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex)) return;
	if(!gObjIsConnected(aIndex)) return;
	
	LPOBJ * lpObj = (LPOBJ*)POBJ(aIndex);

	PMSG_REQUEST_USEREX pMsg;
	pMsg.Head[0] = 0xC1;
	pMsg.Head[1]  = sizeof(pMsg);
	pMsg.Head[2]  = 0xCC;
	pMsg.Head[3]  = 0x01;
	pMsg.aIndex = lpObj->Index;
	memcpy(pMsg.Name,lpObj->Name,sizeof(lpObj->Name));
	
#ifdef GS_N
	DBSockMng_Send((LPVOID)0x9623F0,(char*)&pMsg,sizeof(pMsg));
#else
	DBSockMng_Send((LPVOID)0x9EEFF0,(char*)&pMsg,sizeof(pMsg));
#endif
}

void CUserEx::ResultExData(PMSG_RETURN_USEREX * lpMsg)
{
	int aIndex = lpMsg->aIndex;

	if(!OBJMAX_RANGE(aIndex)) return;
	if(!gObjIsConnected(aIndex)) return;
	
	LPOBJ * lpObj = (LPOBJ*)POBJ(aIndex);
	LPOBJEX * lpObjEx = &gObjEx[POBJEX(aIndex)];

	lpObjEx->Resets = lpMsg->Resets;

	GCServerMsgStringSendEx(aIndex,1,Msg.Get(CMSG::ETC,2),lpObjEx->Resets);

	Console.Log("[UserEx][%s][%s] Character Resets: %d",lpObj->AccountID,lpObj->Name,lpObjEx->Resets);
}

void CUserEx::SaveResets(int aIndex)
{
	if(!OBJMAX_RANGE(aIndex)) return;
	if(!gObjIsConnected(aIndex)) return;
	
	LPOBJ * lpObj = (LPOBJ*)POBJ(aIndex);
	LPOBJEX * lpObjEx = &gObjEx[POBJEX(aIndex)];

	PMSG_SAVE_RESETS pMsg;
	pMsg.Head[0] = 0xC1;
	pMsg.Head[1]  = sizeof(pMsg);
	pMsg.Head[2]  = 0xCC;
	pMsg.Head[3]  = 0x02;
	pMsg.aIndex = lpObj->Index;
	pMsg.Resets = lpObjEx->Resets;
	memcpy(pMsg.Name,lpObj->Name,sizeof(lpObj->Name));
	
#ifdef GS_N
	DBSockMng_Send((LPVOID)0x9623F0,(char*)&pMsg,sizeof(pMsg));
#else
	DBSockMng_Send((LPVOID)0x9EEFF0,(char*)&pMsg,sizeof(pMsg));
#endif
}*/