#pragma once
#ifndef CHAT_H
#define CHAT_H
#include "StdAfx.h"
#include "GmSystem.h"

struct PMSG_STAT_UPDATE
{
	struct PBMSG_HEAD h; // 0
	BYTE result; // 3
	WORD btStatValue; // 4
	BYTE btFruitType; // 6
};

class cChat
{
public:
	cChat();
	~cChat();  
	bool WisperChat(LPOBJ gObj, PMSG_CHATDATA_WHISPER* lpMsg);
	bool ChatDataSend(LPOBJ gObj, PMSG_CHATDATA * lpChat);													   

private:			
	void AntiInject(char* message); 											  
	bool CheckCommand(LPOBJ gObj, int Config, cGmSystem::Commands Command, int NeedZen,
						int NeedLvl, int Filled, int CheckPlayer, char *CommandName,char *CommandUsage, char *Msg);
	void TakeCommand(LPOBJ gObj, int NeedZen,  char *CommandName);  
	bool GgCommand(LPOBJ gObj, char* Msg);		 
	bool VosklCommand(LPOBJ gObj, char* Msg);
	bool PostCommand(LPOBJ gObj, char *Msg);	 
	bool ReloadCommand(LPOBJ gObj, char *Msg);
	bool OnlineCommand(LPOBJ gObj, char *Msg);
	//bool LevelCommand(LPOBJ gObj);	
	//bool CheckCommand(LPOBJ gObj, char *Msg);	  
	bool AddCommands(LPOBJ gObj, char *Msg, int Type); 	   
	//bool AddMobCommand(LPOBJ gObj, char *Msg);	
	//bool GuildPost(LPOBJ gObj, char *Msg);
	//bool Core(LPOBJ gObj, char *Msg);

	bool TraceCommand(LPOBJ gObj, int Index);
	bool DiskCommand(LPOBJ gObj, int Index);  
	bool SummonCommand(LPOBJ gObj, int Index);

	bool SetCharCommand(LPOBJ gObj, char* Msg, int Index); 
	bool SetPKCommand(LPOBJ gObj, char *Msg, int Index);	
	bool SkinCommand(LPOBJ gObj, char *Msg, int Index);	
	void DropCommand(LPOBJ gObj, char *Msg, int Index);	
	//void DropCommand(int aIndex);
	bool GmoveCommand(LPOBJ gObj, char *Msg, int Index);	
	bool StatusCommand(LPOBJ gObj, char *Msg, int Index); 
	bool PKClearCommand(LPOBJ gObj, char *Msg, int Index);	 
	bool SetDropCommand(LPOBJ gObj, char *Msg, int Index);	
	bool SetZenCommand(LPOBJ gObj, char *Msg, int Index);

	//bool DisableChatCommand(LPOBJ gObj, char *Msg, int Index);	
	//bool EnableChatCommand(LPOBJ gObj, int Index);

	//bool OffTradeCommand(LPOBJ gObj);
	//bool ResetCommand(LPOBJ gObj); 
};

extern cChat Chat;


#endif