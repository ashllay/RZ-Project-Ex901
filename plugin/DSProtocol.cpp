#include "StdAfx.h"
#include "DSProtocol.h"

void DataServerProtocolCoreEx(char protoNum, LPBYTE aRecv, int aLen)
{
	if(aRecv[0] == 0xC1 || aRecv[0] == 0xC3) //0xC1 0xXX 0xF1 0x01
	{
		switch(aRecv[2])
		{

#if(COMPILE_CASHSHOP==1)
			case 0xF7:
				return;
			break;
#endif
		}
	}
	DataServerProtocolCore(protoNum,aRecv,aLen);
}
/*
void DGSetSummonerCreate(LPOBJ lpObj,int aIndex)
{
	CSHOP_SET_SUMMONER_CREATE pMsg;
	pMsg.h.set((LPBYTE)&pMsg,0xA2,sizeof(pMsg));
	memset(pMsg.szId,0,sizeof(pMsg.szId));
	memcpy(pMsg.szId,lpObj->AccountID,10);
	pMsg.Index = lpObj->m_Index;

	cDBSMng.Send((char*)&pMsg,sizeof(pMsg));
}*/