#include "StdAfx.h"

CTNotice TNotice;

char Messages[1024];

void CTNotice::MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg)
{
	PMSG_NOTICE * pNotice = (PMSG_NOTICE *)lpNotice;
	pNotice->type = btType;

	wsprintf(pNotice->Notice,szNoticeMsg);
	PHeadSetB((LPBYTE)pNotice,0x0D,strlen(pNotice->Notice) + sizeof(PMSG_NOTICE) - sizeof(pNotice->Notice)+1);
}

void CTNotice::SendNotice(int aIndex, int type, char* szMsg, ...)
{
	char szTemp[4096];
	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);

	PMSG_NOTICE pNotice;
	TNotice.MakeNoticeMsg(&pNotice,type,szTemp);
	DataSend(aIndex,(LPBYTE)&pNotice,pNotice.h.size);
}

void CTNotice::MsgSrv(LPOBJ gObj,char *Message, int Type)
{		 
	BYTE *Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	if(Type)
		*(Packet+2) = 0x02;	  
	else				   
		*(Packet+2) = 0x00;
	memcpy((Packet+3), gObj->Name, strlen( gObj->Name));
	memcpy((Packet+13), Message, strlen(Message));
	int Len = (strlen(Message) + 0x13);
	*(Packet+1) = Len;
	DataSendAll(Packet, Len);
	free (Packet);
}

void CTNotice::MessageAll(int Type, int Type2, LPOBJ gObj, char *Msg,...)
{					  
	Messages[0] = 0;
	char Temp[255]; 
	strcpy(Temp,Msg);
	va_list pArguments1;
	va_start(pArguments1, Msg);
	vsprintf_s(Messages, Temp, pArguments1);
	va_end(pArguments1); 

	if(Type == 2)
	{
		MsgSrv(gObj, Messages, Type2);
	}
	else
		for(int i=OBJECT_MIN; i<=OBJECT_MAX; i++)
		{											 
			OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);
			if(gObj->Connected < PLAYER_PLAYING)	continue;
			GCServerMsgStringSend(Messages, i, Type);
		}											 
}

void CTNotice::NPCMessageLog(LPOBJ gObj, LPOBJ mObj, char* Msg,...)
{						  
	Messages[0] = 0;
	va_list pArguments1;
	va_start(pArguments1, Msg);
	vsprintf_s(Messages, Msg, pArguments1);
	va_end(pArguments1);

	ChatTargetSend(mObj, Messages, gObj->m_Index); 
	//Log.ConsoleOutPut(1, LogColor, LogType, "[NPC] [%s]:\t%s", gObj->Name, Messages1);
	LogAddFuncColor(3,"[NPC] [%s]:\t%s", gObj->Name, Messages);
}

void CTNotice::MessageLog(int Type,LPOBJ gObj, char *Msg,...)
{	
	Messages[0] = 0;
	char Temp[255]; 
	strcpy(Temp,Msg);
	va_list pArguments1;
	va_start(pArguments1, Msg);
	vsprintf_s(Messages, Temp, pArguments1);
	va_end(pArguments1); 
	GCServerMsgStringSend(Messages, gObj->m_Index, Type);
	// Type = 1 - ?блок?сообщени?
	// Type = 0 - золото?по середине
	if(Type)
		LogAddFuncColor(1,"[%s:%s]: %s", gObj->AccountID, gObj->Name, Messages);
	else														
		LogAddFuncColor(1,"[GoldMessage] %s", Messages);
}	
//void CTNotice::SendNoticeToAll(int type, char* szMsg, ...)
//{
//	char szTemp[4096];
//	va_list pArguments;
//	va_start(pArguments,szMsg);
//	vsprintf(szTemp,szMsg,pArguments);
//	va_end(pArguments);
//
//	PMSG_NOTICE pNotice;
//	TNotice.MakeNoticeMsg(&pNotice,type,szTemp);
//
//	for(int x = OBJECT_MIN; x < OBJECT_MAX; x++)
//	{
//		OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(x);
//
//		if(lpObj->Connected == PLAYER_PLAYING)
//		{
//			DataSend(x,(LPBYTE)&pNotice,pNotice.h.size);
//		}
//	}
//}
//
//void CTNotice::ServerMsgSend(DWORD wId,int Type, char Sender[11],const char*Message,...)
//{
//	char szBuffer[1024];
//	va_list pArguments;
//	va_start(pArguments,Message);
//	vsprintf(szBuffer,Message,pArguments);
//	va_end(pArguments);
//	BYTE*Packet;
//	Packet=(BYTE*)malloc(200);
//	memset(Packet,0x00,200);
//	*Packet=0xC1;
//	if (Type)*(Packet+2)=0x02;
//	else *(Packet+2)=0x00;
//	memcpy((Packet+3),Sender,strlen(Sender));
//	memcpy((Packet+13),szBuffer,strlen(szBuffer));
//	int Len=(strlen(szBuffer)+0x13);
//	*(Packet+1)=Len;
//	DataSendAll(Packet,Len);
//	free(Packet);
//}
//
//void CTNotice::ChatWisperServer(const char *Format, ...)
//{
//	char Message[255];
//	va_list pArguments;
//	va_start(pArguments,Format);
//	vsprintf(Message,Format,pArguments);
//	va_end(pArguments);
//	BYTE *Packet;
//	Packet = (BYTE*) malloc(200);
//	memset(Packet,0x00,200);
//	*Packet = 0xC1;
//	*(Packet+2) = 0x02;
//	memcpy((Packet+13),Message,strlen(Message));
//	int Len = (strlen(Message)+0x13);
//	*(Packet+1) = Len;
//	DataSendAll(Packet,Len);
//	free(Packet);
//}
//
//void CTNotice::ChatGuildServer(const char* Format, ...) 
//{
//	char Message[255];
//	va_list pArguments;
//	va_start(pArguments,Format);
//	vsprintf(&Message[0],Format,pArguments);
//	va_end(pArguments);
//	BYTE *Packet;
//	Packet = (BYTE*) malloc(200);
//	memset(Packet, 0x00, 200);
//	*Packet = 0xC1;
//	*(Packet+2) = 0x00;
//	*(Packet+13) = '@';
//	memcpy((Packet+14),Message,strlen(Message));
//	int Len = (strlen(Message)+15);
//	*(Packet+1) = Len;
//	DataSendAll(Packet,Len);
//	free (Packet);
//}
//
//void CTNotice::ChatPartyServer(const char* Format, ...) 
//{
//	char Message[255];
//	va_list pArguments;
//	va_start(pArguments, Format);
//	vsprintf(&Message[0], Format, pArguments);
//	va_end(pArguments);
//	BYTE *Packet;
//	Packet = (BYTE*) malloc(200);
//	memset(Packet, 0x00, 200);
//	*Packet = 0xC1;
//	*(Packet+2) = 0x00;
//	*(Packet+13) = '~';
//	memcpy((Packet+14),Message,strlen(Message));
//	int Len = (strlen(Message)+15);
//	*(Packet+1) = Len;
//	DataSendAll(Packet,Len);
//	free (Packet);
//}
//
//void CTNotice::ChatAllianceServer(const char* Format, ...) 
//{
//	char Message[255];
//	va_list pArguments;
//	va_start(pArguments, Format);
//	vsprintf(&Message[0], Format, pArguments);
//	va_end(pArguments);
//	BYTE *Packet;
//	Packet = (BYTE*) malloc(200);
//	memset(Packet, 0x00, 200);
//	*Packet = 0xC1;
//	*(Packet+2) = 0x00;
//	*(Packet+13) = 0x40;
//	*(Packet+14) = 0x40;
//	memcpy((Packet+15),Message,strlen(Message));
//	int Len = (strlen(Message)+16);
//	*(Packet+1) = Len;
//	DataSendAll(Packet,Len);
//	free (Packet);
//}