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

int DataSendEx(int aIndex, LPBYTE lpMsg, DWORD dwSize)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
#ifndef INTERNATIONAL_KOREAN
	if(lpMsg[0] == 0xC1 || lpMsg[0] == 0xC3)
	{
	    lpMsg[2] = ProtocolTable(0,lpMsg[2]);
	}
	else 
	{
		lpMsg[3] = ProtocolTable(0,lpMsg[3]);
	}
#endif
	DataSend(aIndex,(char*)lpMsg,dwSize);
	return true;
}

void ProtocolCoreEx(char ProtoNum, LPBYTE aRecv, int aLen, int aIndex, int Encrypt, int Serial)
{
	OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
#ifndef INTERNATIONAL_KOREAN
	if(aRecv[0] == 0xC1 || aRecv[0] == 0xC3)
	{
	    aRecv[2] = ProtocolTable(1,ProtoNum);
		ProtoNum = ProtocolTable(1,ProtoNum);
	}
	else 
	{
	    aRecv[3] = ProtocolTable(1,ProtoNum);
		ProtoNum = ProtocolTable(1,ProtoNum);
	}
#endif
	switch(BYTE(ProtoNum))
	{
	case 0x00:// Chat Protocol
		Chat.ChatDataSend(lpObj, (PMSG_CHATDATA *)aRecv);
		break;
	case 0x02:// Whisper Protocol
		Chat.WisperChat(lpObj, (PMSG_CHATDATA_WHISPER *)aRecv);
		break;
	case 0x03:
		UserEx.Connect(aIndex);
		//TNotice.SendNotice(aIndex,0,"Wellcome %s Your Lvl is %d",lpObj->Name,lpObj->Level);
		LogAddFuncColor(LOG::BLUE,"[Connect] Account:[%s] Name:[%s] Map:[%d]",lpObj->AccountID,lpObj->Name,lpObj->MapNumber);
		break;
#if(COMPILE_CASHSHOP==0)
	case 0x26:
		CGUseItemRecvEx((PMSG_USEITEM *)aRecv, aIndex);
		break;
#endif
	case 0x30: // Click NPC Protocol	  
		{
			PkClear.NPCTalkEx(lpObj, (aRecv[4] + aRecv[3] * 256));
		}
		break;
#if(COMPILE_CASHSHOP==1)
		case 0xD2:
			return;
		break;
#endif
	}
	return ProtocolCore(ProtoNum,aRecv,aLen,aIndex,Encrypt,Serial);
}

#if(COMPILE_CASHSHOP==0)
void CGUseItemRecvEx(PMSG_USEITEM* lpMsg, int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	CItem* DTitem = &lpObj->pInventory[lpMsg->inventoryPos];
	CItem* DTadd = &lpObj->pInventory[lpMsg->invenrotyTarget];

	if (DTitem->m_Type == ITEMGET(14, 162))
	{
		GDUpdateExtendedInvenCount(lpObj, 1, 0, lpMsg->inventoryPos, 0, 0);
	}
	if (DTitem->m_Type == ITEMGET(14, 163))
	{
		GDUpdateExtendedWarehouseCount(lpObj, 1, 0, lpMsg->inventoryPos, 0, 0);
	}
	/*if (DTitem->m_Type == ITEMGET(14, 91))
	{
		DataServerSetAccountInfo(lpObj, lpObj->m_Index, 1);
	}
	if (DTitem->m_Type == 0x1A63)
	{
		GDUpdateCharacterSlotCount(lpObj, 1, dwEventIndex);
	}*/
	//return CGUseItemRecv((PMSG_USEITEM *)lpMsg, aIndex);
}
#endif