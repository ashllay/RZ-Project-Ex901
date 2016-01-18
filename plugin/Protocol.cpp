#include "StdAfx.h"
#include "User.h"

BYTE ProtocolTable(BYTE type,BYTE head)
{
	if(type == 0) //Send
	{
		//=====================================================================================
		//Protocol Server Send
		//=====================================================================================

		switch(head)
		{
		case PROTOCOL_MOVE_GS:
			return PROTOCOL_MOVE;
		case PROTOCOL_POSITION_GS:
			return PROTOCOL_POSITION;
		case PROTOCOL_ATTACK_GS:
			return PROTOCOL_ATTACK;
		case PROTOCOL_BEATTACK_GS:
			return PROTOCOL_BEATTACK;
		default:
			return head;
		}
	}
	//=====================================================================================
	//Protocol Client Recv
	//=====================================================================================
	else if(type == 1) //Recv
	{
		switch(head)
		{
		case PROTOCOL_MOVE:
			return PROTOCOL_MOVE_GS;
		case PROTOCOL_POSITION:
			return PROTOCOL_POSITION_GS;
		case PROTOCOL_ATTACK:
			return PROTOCOL_ATTACK_GS;
		case PROTOCOL_BEATTACK:
			return PROTOCOL_BEATTACK_GS;
		default:
			return head;
		}
	}

	return head;
}

void DataSendEx(int aIndex, PBYTE aSend, int aLen)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
#ifndef INTERNATIONAL_KOREAN
	if(aSend[0] == 0xC1 || aSend[0] == 0xC3)
	{
	    aSend[2] = ProtocolTable(0,aSend[2]);
	}
	else 
	{
		aSend[3] = ProtocolTable(0,aSend[3]);
	}
#endif
	DataSend(aIndex,aSend,aLen);
}

bool ProtocolCoreEx(BYTE protoNum, BYTE * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

#ifndef INTERNATIONAL_KOREAN
	if(aRecv[0] == 0xC1 || aRecv[0] == 0xC3)
	{
	    aRecv[2] = ProtocolTable(1,protoNum);
		protoNum = ProtocolTable(1,protoNum);
	}
	else 
	{
	    aRecv[3] = ProtocolTable(1,protoNum);
		protoNum = ProtocolTable(1,protoNum);
	}
#endif
	switch(BYTE(protoNum))
	{
	case 0x03:
		TNotice.SendNotice(aIndex,0,"Wellcome %s Your Lvl is %d",lpObj->Name,lpObj->Level);
		LogAddFuncColor(1,"[Connect] Account:[%s] Name:[%s] Map:[%d]",lpObj->AccountID,lpObj->Name,lpObj->MapNumber);
		break;
	}
	ProtocolCore(protoNum,aRecv,aLen,aIndex,Encrypt,serial);
	return true;
}
