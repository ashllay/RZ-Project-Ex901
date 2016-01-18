#pragma once
#include "StdAfx.h"
#ifndef _TNOTICE_H
#define _TNOTICE_H

class CTNotice
{
public:
	void MakeNoticeMsg(void * lpNotice, BYTE btType, char * szNoticeMsg);
	void SendNotice(int aIndex, int type, char* szMsg,...);
	void MessageAll(int Type, int Type2, LPOBJ gObj, char *Msg,...);
	void MsgSrv(LPOBJ gObj,char *Message, int Type);
	void NPCMessageLog(LPOBJ gObj, LPOBJ mObj, char* Msg,...);
	void MessageLog(int Type,LPOBJ gObj, char *Msg,...);
};
extern CTNotice TNotice;

#endif