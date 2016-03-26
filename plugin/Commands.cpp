#include "StdAfx.h"
cChat Chat;
CRITICAL_SECTION Chat_Crit;

cChat::cChat()
{
	InitializeCriticalSection(&Chat_Crit); 
}

cChat::~cChat()
{
}

void cChat::AntiInject(char* message)
{
	for (UINT i = 0; i <= strlen(message); i++)
	{                          						   
		if(message[i] == '\'')		  
		{
			message[i] = ' ';
		}
	}
}

bool cChat::WisperChat(LPOBJ gObj, PMSG_CHATDATA_WHISPER* lpMsg)
{
	AntiInject(lpMsg->chatmsg);

	bool bResult = false;	

	char TempName[10];
	memcpy(TempName, lpMsg->id, sizeof(TempName));
	int Index = User.GetPlayerIndex(TempName);

	if (!memcmp(lpMsg->chatmsg,"@",strlen("@")) || !memcmp(lpMsg->chatmsg,"@@",strlen("@@")) || !memcmp(lpMsg->chatmsg,"~",strlen("~")))
	{
		PMSG_CHATDATA pMsg ={0};

		pMsg.h.Set((LPBYTE)&pMsg, 0x00, sizeof(pMsg));
		memcpy(pMsg.chatid, lpMsg->id, sizeof(pMsg.chatid));
		memcpy(pMsg.chatmsg, lpMsg->chatmsg, sizeof(pMsg.chatmsg));

		PChatProc(&pMsg, gObj->m_Index);
		return true;
	}
	if (!memcmp(lpMsg->chatmsg,"/gg",strlen("/gg")))
		bResult = GgCommand(gObj,lpMsg->chatmsg+strlen("/gg"));	 
	if (!memcmp(lpMsg->chatmsg,"!",strlen("!")))
		bResult = VosklCommand(gObj,lpMsg->chatmsg+strlen("!"));
	if (!memcmp(lpMsg->chatmsg,"/trace",strlen("/trace")))
		bResult = TraceCommand(gObj, Index);
	if (!memcmp(lpMsg->chatmsg,"/disconnect",strlen("/disconnect")))
		bResult = DiskCommand(gObj, Index);
	if (!memcmp(lpMsg->chatmsg,"/track",strlen("/track")))
		bResult = SummonCommand(gObj, Index);	
	/*  
	if (!memcmp(lpMsg->chatmsg,"/post",strlen("/post")))
		bResult = PostCommand(gObj,lpMsg->chatmsg+strlen("/post"));*/ 	
	if (!memcmp(lpMsg->chatmsg,"/setchar",strlen("/setchar")))
		bResult = SetCharCommand(gObj,lpMsg->chatmsg+strlen("/setchar"), Index);	
	/*if (!memcmp(lpMsg->chatmsg,"/setpk",strlen("/setpk")))
		bResult = SetPKCommand(gObj,lpMsg->chatmsg+strlen("/setpk"), Index);*/	
	if (!memcmp(lpMsg->chatmsg,"/setzen",strlen("/setzen")))
		bResult = SetZenCommand(gObj,lpMsg->chatmsg+strlen("/setzen"), Index);	
	if (!memcmp(lpMsg->chatmsg,"/skin",strlen("/skin")))
		bResult = SkinCommand(gObj,lpMsg->chatmsg+strlen("/skin"), Index);	
	if (!memcmp(lpMsg->chatmsg,"/drop",strlen("/drop")))
		this->DropCommand(gObj,lpMsg->chatmsg+strlen("/drop"), Index);	 
	if (!memcmp(lpMsg->chatmsg,"/gmove",strlen("/gmove")))
		bResult = GmoveCommand(gObj,lpMsg->chatmsg+strlen("/gmove"), Index);	 
	//if (!memcmp(lpMsg->chatmsg,"/online",strlen("/online")))
	//	bResult = OnlineCommand(gObj,lpMsg->chatmsg+strlen("/online"));
	if (!memcmp(lpMsg->chatmsg,"/status",strlen("/status")))
		bResult = StatusCommand(gObj,lpMsg->chatmsg+strlen("/status"), Index);
	/*if (!memcmp(lpMsg->chatmsg,"/reload",strlen("/reload")))
		bResult = ReloadCommand(gObj,lpMsg->chatmsg+strlen("/reload")); 	 
	if (!memcmp(lpMsg->chatmsg,"/pkclear",strlen("/pkclear")))
		bResult = PKClearCommand(gObj,lpMsg->chatmsg+strlen("/pkclear"), Index);	
	if (!memcmp(lpMsg->chatmsg,"/addstr",strlen("/addstr")))
		bResult = AddCommands(gObj,lpMsg->chatmsg+strlen("/addstr"),0);
	if (!memcmp(lpMsg->chatmsg,"/addagi",strlen("/addagi")))
		bResult = AddCommands(gObj,lpMsg->chatmsg+strlen("/addagi"),1);
	if (!memcmp(lpMsg->chatmsg,"/addvit",strlen("/addvit")))
		bResult = AddCommands(gObj,lpMsg->chatmsg+strlen("/addvit"),2);
	if (!memcmp(lpMsg->chatmsg,"/addene",strlen("/addene")))
		bResult = AddCommands(gObj,lpMsg->chatmsg+strlen("/addene"),3);
	if (!memcmp(lpMsg->chatmsg,"/addcmd",strlen("/addcmd")))
		bResult = AddCommands(gObj,lpMsg->chatmsg+strlen("/addcmd"),4);		 
	if (!memcmp(lpMsg->chatmsg,"/mobadd",strlen("/mobadd")))
		bResult = AddMobCommand(gObj,lpMsg->chatmsg+strlen("/mobadd"));	
	if (!memcmp(lpMsg->chatmsg,"/setdrop",strlen("/setdrop")))
		bResult = SetDropCommand(gObj,lpMsg->chatmsg+strlen("/setdrop"), Index);	
	if (!memcmp(lpMsg->chatmsg,"~core",strlen("~core")))
		bResult = Core(gObj,lpMsg->chatmsg+strlen("~core"));	 
	if (!memcmp(lpMsg->chatmsg,"@>",strlen("@>")))
		bResult = GuildPost(gObj,lpMsg->chatmsg+strlen("@>"));	*/

	return bResult;
}

bool cChat::ChatDataSend(LPOBJ gObj, PMSG_CHATDATA * lpChat)
{
	AntiInject(lpChat->chatmsg);

	bool bResult = false;		 
	if (!memcmp(lpChat->chatmsg,"/gg",strlen("/gg")))
		bResult = GgCommand(gObj,lpChat->chatmsg+strlen("/gg"));	 
	if (!memcmp(lpChat->chatmsg,"!",strlen("!")))
		bResult = VosklCommand(gObj,lpChat->chatmsg+strlen("!"));	  
	if (!memcmp(lpChat->chatmsg,"/post",strlen("/post")))
		bResult = PostCommand(gObj,lpChat->chatmsg+strlen("/post"));		 	
	if (!memcmp(lpChat->chatmsg,"/setchar",strlen("/setchar")))
		bResult = SetCharCommand(gObj,lpChat->chatmsg+strlen("/setchar"), gObj->m_Index);	
	if (!memcmp(lpChat->chatmsg,"/setpk",strlen("/setpk")))
		bResult = SetPKCommand(gObj,lpChat->chatmsg+strlen("/setpk"), gObj->m_Index);	
	if (!memcmp(lpChat->chatmsg,"/setzen",strlen("/setzen")))
		bResult = SetZenCommand(gObj,lpChat->chatmsg+strlen("/setzen"), gObj->m_Index);
	if (!memcmp(lpChat->chatmsg,"/skin",strlen("/skin")))
		bResult = SkinCommand(gObj,lpChat->chatmsg+strlen("/skin"), gObj->m_Index);	
	if (!memcmp(lpChat->chatmsg,"/drop",strlen("/drop")))
		this->DropCommand(gObj,lpChat->chatmsg+strlen("/drop"), gObj->m_Index);	 
	if (!memcmp(lpChat->chatmsg,"/gmove",strlen("/gmove")))
		bResult = GmoveCommand(gObj,lpChat->chatmsg+strlen("/gmove"), gObj->m_Index);	 
	if (!memcmp(lpChat->chatmsg,"/online",strlen("/online")))
		bResult = OnlineCommand(gObj,lpChat->chatmsg+strlen("/online"));
	if (!memcmp(lpChat->chatmsg,"/reload",strlen("/reload")))
		bResult = ReloadCommand(gObj,lpChat->chatmsg+strlen("/reload")); 	 
	if (!memcmp(lpChat->chatmsg,"/pkclear",strlen("/pkclear")))
		bResult = PKClearCommand(gObj,lpChat->chatmsg+strlen("/pkclear"), gObj->m_Index);
	if (!memcmp(lpChat->chatmsg,"/addstr",strlen("/addstr")))
		this->AddCommands(gObj,lpChat->chatmsg+strlen("/addstr"),0);
	if (!memcmp(lpChat->chatmsg,"/addagi",strlen("/addagi")))
		this->AddCommands(gObj,lpChat->chatmsg+strlen("/addagi"),1);
	if (!memcmp(lpChat->chatmsg,"/addvit",strlen("/addvit")))
		this->AddCommands(gObj,lpChat->chatmsg+strlen("/addvit"),2);
	if (!memcmp(lpChat->chatmsg,"/addene",strlen("/addene")))
		this->AddCommands(gObj,lpChat->chatmsg+strlen("/addene"),3);
	if (!memcmp(lpChat->chatmsg,"/addcmd",strlen("/addcmd")))
		this->AddCommands(gObj,lpChat->chatmsg+strlen("/addcmd"),4);		
	//if (!memcmp(lpChat->chatmsg,"/mobadd",strlen("/mobadd")))
	//	bResult = AddMobCommand(gObj,lpChat->chatmsg+strlen("/mobadd"));
	if (!memcmp(lpChat->chatmsg,"/setdrop",strlen("/setdrop")))
		bResult = SetDropCommand(gObj,lpChat->chatmsg+strlen("/setdrop"), gObj->m_Index);	 
	//if (!memcmp(lpChat->chatmsg,"/check",strlen("/check")))
	//	bResult = CheckCommand(gObj,lpChat->chatmsg+strlen("/check"));	
	//if (!memcmp(lpChat->chatmsg,"~core",strlen("~core")))
	//	bResult = Core(gObj,lpChat->chatmsg+strlen("~core"));	  
	//if (!memcmp(lpChat->chatmsg,"@>",strlen("@>")))
	//	bResult = GuildPost(gObj,lpChat->chatmsg+strlen("@>"));	  
	//if (!memcmp(lpChat->chatmsg,"/offtrade",strlen("/offtrade")))
	//	bResult = OffTradeCommand(gObj);   
	//if (!memcmp(lpChat->chatmsg,"/reset",strlen("/reset")))
	//	bResult = ResetCommand(gObj);

	return bResult;												
}

bool cChat::CheckCommand(LPOBJ gObj, int lConfig, cGmSystem::Commands Command, int NeedZen, int NeedLvl, int Filled, int CheckPlayer,char *CommandName, char *CommandUsage, char *Msg)
{
	int aIndex = User.GetPlayerIndex(gObj->Name);
	bool bResult = false;

	int spaces = 0;
	const int slen = strlen(Msg);
	for(unsigned int i = 0; i < slen; i++)
		if(Msg[i]==' ' && Msg[i-1]!=' ')
			spaces++;	

	if((Filled > 0) && ((Filled > spaces) || (((slen < 1) || (slen == 1)) && (Msg[0] == ' '))))/*False	2	833	V804	Decreased performance. The 'strlen' function is called twice in the specified expression to calculate length of the same string.	IA Julia 1.x.x	chatcommands.cpp	459	False*/
	{				
		TNotice.SendNotice(aIndex,1,"[%s] Usage: %s", CommandName, CommandUsage);
		return true;
	}

	if (lConfig == 0)
	{
		TNotice.SendNotice(aIndex,1,"[%s] Function temporarily disabled.", CommandName);
		return true;
	}

	if (!GmSystem.IsCommand(Command, gObj->Name))
	{
		TNotice.SendNotice(aIndex,1,"[%s] You can't use this command.", CommandName);
		return true;
	}		

	if (NeedLvl > 0 && gObj->Level < NeedLvl)
	{
		TNotice.SendNotice(aIndex,1, "[%s] You haven't got enough level.", CommandName);
		bResult = true;
	}

	if (NeedZen > 0 && NeedZen > gObj->Money)
	{
		TNotice.SendNotice(aIndex,1,"[%s] You haven't got enough money.", CommandName);
		bResult = true;
	}

	if(CheckPlayer != 0)
	{							
		if(CheckPlayer == -1)
		{													
			TNotice.SendNotice(aIndex,1,"[%s] Player offline or doesn't exist!", CommandName);
			bResult = true;
		}
	}
	//--
	if(gObj->WarehouseSave == 1)
	{
		TNotice.SendNotice(aIndex,1,"%s Close Warehouse to use Command.",gObj->Name);	
		return true;
	}
	// ---
	if(gObj->pTransaction == 1)
	{
		TNotice.SendNotice(aIndex,1,"%s Close Trade to use Command.",gObj->Name);		
		return true;
	}
	// ---
	if(gObj->ChaosLock == 1)
	{
		TNotice.SendNotice(aIndex,1,"%s Close ChaosBox to use Command.",gObj->Name);		
		return true;
	}
	// ---
	
	if(gObj->m_bPShopOpen == 1)
	{
		TNotice.SendNotice(aIndex,1,"%s Close Personal Shot to use Command.",gObj->Name);		
		//if(OfflineTrade.Configs.Enabled)
		//	return false;
		//else
			return true;
	}
	// ---
	if(gObj->DieRegen == 1)
	{
		TNotice.SendNotice(aIndex,1,"%s You Died and cant use command.",gObj->Name);		
		return true;
	}
	// ---
	if(gObj->m_IfState.Use == 1 && gObj->m_IfState.Type == 7)
	{
		TNotice.SendNotice(aIndex,1,"%s Close ChaosCard NPC to use command.",gObj->Name);		
		return true;
	}
	return bResult;
}			  

void cChat::TakeCommand(LPOBJ gObj, int NeedZen, char *CommandName)
{
	if(NeedZen > 0)
	{
		gObj->Money -= NeedZen;
		GCMoneySend(gObj->m_Index, gObj->Money);
	}
}			  

bool cChat::GgCommand(LPOBJ gObj, char *Msg)
{
	if(CheckCommand(gObj, Configs.Commands.IsGg, GmSystem.cGg, 0, 0, 0, 1, "GG", "/gg <msg>", Msg))
		return true;												

	//Log.CheckProcent(Msg);
	TNotice.MessageAll(0, 0, gObj, "[%s]: %s", gObj->Name, Msg);	 //PROTECT HERE MUST BE GOOOD

	//Log.ConsoleOutPut(0,  "[GG] %s: %s", gObj->Name,Msg);
	LogAddFuncColor(LOG::DARKBLUE,"[GG] %s: %s", gObj->Name,Msg);
	return true;
}			
//
bool cChat::VosklCommand(LPOBJ gObj, char *Msg)
{
	if(CheckCommand(gObj, 1, GmSystem.cVoskl, 0, 0, 0, 0, "!", "! <msg>", Msg))
		return true;												

	//Log.CheckProcent(Msg);
	//TNotice.MessageAll(0, 0, gObj, Msg);  //PROTECT HERE MUST BE GOOOD 

	//Log.ConsoleOutPut(0,  "[!] %s: %s", gObj->Name,Msg);
	LogAddFuncColor(LOG::DARKBLUE,"[!] %s: %s", gObj->Name,Msg);
	return true;
}		
//
bool cChat::TraceCommand(LPOBJ gObj, int Index)
{
	if(CheckCommand(gObj, 1, GmSystem.cTrace, 0, 0, 0, Index, "Trace", "[Name] /trace", ""))
		return true;

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	gObjTeleport(gObj->m_Index, tObj->MapNumber, (int)tObj->X, (int)tObj->Y);	
	TNotice.SendNotice(Index,1,"[Trace] You successfully traced to %s",tObj->Name);

	if(GmSystem.IsAdmin(gObj->Name) == 1)
		TNotice.SendNotice(Index,1,"[Trace] [Admin] %s traced to you", gObj->Name);		
	else if(GmSystem.IsAdmin(gObj->Name) == 2)
		TNotice.SendNotice(Index,1, "[Trace] [GM] %s traced to you", gObj->Name);	
	return true;
}		
//
bool cChat::SummonCommand(LPOBJ gObj, int Index)
{
	if(CheckCommand(gObj, 1, GmSystem.cTrace, 0, 0, 0, Index, "Track", "[Name] /track", ""))
		return true;

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	gObjTeleport(tObj->m_Index, gObj->MapNumber, (int)gObj->X, (int)gObj->Y);	
	TNotice.SendNotice(Index,1,"[Track] You successfully summoned %s",tObj->Name);

	if(GmSystem.IsAdmin(gObj->Name) == 1)
		TNotice.SendNotice(Index,1,"[Track] You was summoned to [Admin] %s", gObj->Name);		
	else if(GmSystem.IsAdmin(gObj->Name) == 2)
		TNotice.SendNotice(Index,1,"[Track] You was summoned to [GM] %s", gObj->Name);	
	return true;
}		

bool cChat::DiskCommand(LPOBJ gObj, int Index)
{
	if(CheckCommand(gObj, 1, GmSystem.cDisconnect, 0, 0, 0, Index, "DC", "[Name] /disconnect", ""))
		return true;

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);
	TNotice.SendNotice(Index,1,"[Disconnect] %s was disconnected.", tObj->Name);

	if(GmSystem.IsAdmin(gObj->Name) == 1)
		TNotice.SendNotice(Index,1,"[Disconnect] You was disconnected by [Admin] %s", gObj->Name);		
	else if(GmSystem.IsAdmin(gObj->Name) == 2)
		TNotice.SendNotice(Index,1,"[Disconnect] You was disconnected by [GM] %s", gObj->Name);	

	CloseClient(Index);
	return true;
}			

bool cChat::PostCommand(LPOBJ gObj, char *Msg)
{
	int aIndex = User.GetPlayerIndex(gObj->Name);

	if(CheckCommand(gObj, Configs.Commands.IsPost, GmSystem.NONE, Configs.Commands.PostPriceZen, Configs.Commands.PostLvl, 1, 0, "Post", "/post <msg>", Msg))
		return true;

	if(AddTab[gObj->m_Index].POST_Delay > 0)
	{
		TNotice.SendNotice(aIndex,1,"[ANTI-FLOOD] Wait %d sec until you can post!", AddTab[gObj->m_Index].POST_Delay);
		return true;
	}

	TakeCommand(gObj, Configs.Commands.PostPriceZen, "Post"); 
	switch(Configs.Commands.PostColor)
	{
	case 0:
	case 1:
		TNotice.MessageAll(2, 1, gObj, "[POST] %s", Msg);	
		break;
	case 2:
		TNotice.MessageAll(2, 0, gObj, "@[POST] %s", Msg);	
		break;
	case 3:
		TNotice.MessageAll(2, 0, gObj, "~[POST] %s", Msg);	
		break;
	} 
	LogAddFuncColor(3,"[POST] %s: %s", gObj->Name,Msg);
	if(!GmSystem.IsAdmin(gObj->Name))
		AddTab[gObj->m_Index].POST_Delay = Configs.Commands.PostDelay;

	return true;
}
//
bool cChat::SetCharCommand(LPOBJ gObj, char* Msg, int Index)
{
	if(CheckCommand(gObj, Configs.Commands.IsSetChar, GmSystem.cSetZen, 0, 0, 0, Index, "SetChar", "[Name] /setchar <Zen> <AddPnt> <lvl> <Prof>", Msg))
		return true;

	DWORD Zen = 0;
	int AddPnt = 0, Lvl = 0, Prof = 0;

	sscanf(Msg, "%d %d %d %d %d %d", &Zen, &AddPnt, &Lvl, &Prof);

	if( Zen > 2000000000)
	{
		TNotice.MessageLog(1,  gObj, "[SetChar] Zen can't be less than 0 and more than 2000000000!");
		return true;
	}

	int MaximumAddPnt;
	//if(Configs.Enable65kStats == 0)
		MaximumAddPnt = 32767;
	//else
	//	MaximumAddPnt = 65000;

	if(AddPnt < 0 || AddPnt > MaximumAddPnt)
	{
		TNotice.MessageLog(1,  gObj, "[SetChar] AddPnt can't be less than 0 and more than %d!", MaximumAddPnt);
		return true;
	}

	if(Lvl < 0 || Lvl > Configs.Commands.MaxLvl)
	{
		TNotice.MessageLog(1,  gObj, "[SetChar] Lvl can't be less than 0 and more than %d!", Configs.Commands.MaxLvl);
		return true;
	}

	if(Prof < 0 || Prof > 3)
	{
		TNotice.MessageLog(1,  gObj, "[SetChar] Lvl can't be less than 0 and more than 3!");
		return true;
	}

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	if(Zen > 0)
	{
		tObj->Money = Zen;
		GCMoneySend (tObj->m_Index, Zen);
	}

	if(AddPnt > 0)
	{
		tObj->LevelUpPoint += AddPnt;
	}

	if(Lvl > 0)
	{
		tObj->Level	= Lvl;
	}

	if(Prof > 0)
	{
		switch(Prof)
		{
		case 0:
			{

			}
			break;
		case 1:
			{
				if(gObj->DbClass <= 3)
					gObj->DbClass = 0;
				else if(gObj->DbClass >= 16 && gObj->DbClass <= 19)
					gObj->DbClass = 16;
				else if(gObj->DbClass >= 32 && gObj->DbClass <= 35)
					gObj->DbClass = 32;
				else if(gObj->DbClass >= 48 && gObj->DbClass <= 50)
					gObj->DbClass = 48;
				else if(gObj->DbClass >= 64 && gObj->DbClass <= 66)
					gObj->DbClass = 64;
				else if(gObj->DbClass >= 80 && gObj->DbClass < 83)
					gObj->DbClass = 80;
			}
			break;
		case 2:
			{
				if( gObj->DbClass <= 3)
					gObj->DbClass = 1;
				else if(gObj->DbClass >= 16 && gObj->DbClass <= 19)
					gObj->DbClass = 17;
				else if(gObj->DbClass >= 32 && gObj->DbClass <= 35)
					gObj->DbClass = 33;
				else if(gObj->DbClass >= 80 && gObj->DbClass < 83)
					gObj->DbClass = 81;
			}
			break;
		case 3:
			{
				if( gObj->DbClass <= 3 )
					gObj->DbClass = 3;
				else if(gObj->DbClass >= 16 && gObj->DbClass <= 19)
					gObj->DbClass = 19;
				else if(gObj->DbClass >= 32 && gObj->DbClass <= 35)
					gObj->DbClass = 35;
				else if(gObj->DbClass >= 48 && gObj->DbClass <= 50)
					gObj->DbClass = 50;
				else if(gObj->DbClass >= 64 && gObj->DbClass <= 66)
					gObj->DbClass = 66;
				else if(gObj->DbClass >= 80 && gObj->DbClass < 83)
					gObj->DbClass = 83;
			}
			break;
		}
	}

	if (gObj == tObj)
	{
		if(AddPnt > 0 || Prof > 0 || Lvl > 0)
			TNotice.MessageLog(1,  tObj, "[SetChar] Your character was edited, you must relogin!");
		else
			TNotice.MessageLog(1,  tObj, "[SetChar] Your character was edited!");
	}
	else
	{
		TNotice.MessageLog(1,  gObj, "[SetChar] You successfully changed %s character.", tObj->Name);
		if(AddPnt > 0 || Prof > 0 || Lvl > 0)
			TNotice.MessageLog(1,  tObj, "[SetChar] Your character was edited by %s, you must relogin!", gObj->Name);
		else
			TNotice.MessageLog(1,  tObj, "[SetChar] Your character was edited by %s!", gObj->Name);
	}
	return true;
}			
//
bool cChat::OnlineCommand(LPOBJ gObj, char *Msg)
{
	char szTemp[256];
	int iGM = 0;
	int iPlayer = 0;

	for(int x = OBJ_MIN; x < OBJ_MAX; x++)
	{
		OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(x);
		if(lpObj->Connected == PLAYER_PLAYING)
		{
			if(lpObj->Authority == 8 || lpObj->Authority == 32)
			{
				iGM++;
			}
			iPlayer++;
		}
	}
	if(CheckCommand(gObj, Configs.Commands.IsOnline, GmSystem.NONE, 0, 0, 0, 0, "Online", "/online", Msg))
		return true;

	TNotice.MessageLog(1,  gObj, "[ONLINE]: %d Player(s), %d GM(s)",iPlayer,iGM);
	return true;
}
//
bool cChat::SetPKCommand(LPOBJ gObj, char *Msg, int Index)
{								 			
	if(CheckCommand(gObj, Configs.Commands.IsSetPK, GmSystem.cSetPK, 0, 0, 0, Index, "SetPK", "[Name] /setpk <pklvl>", Msg))
		return true;

	int SetLevel;
	sscanf(Msg,"%d", &SetLevel);		

	if(SetLevel < 0 || SetLevel > 100)
	{
		TNotice.MessageLog(1,  gObj, "[SetPK] PK lvl can't be less than 0 and more than 100!");
		return true;
	}			 

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	tObj->m_PK_Level = SetLevel;
	if(SetLevel >= 3)
		tObj->m_PK_Count = SetLevel - 3;
	GCPkLevelSend(tObj->m_Index,SetLevel);	 

	if (gObj == tObj)
		TNotice.MessageLog(1,tObj, "[SetPK] Your pk was changed to %d.", SetLevel);
	else
	{
		TNotice.MessageLog(1,gObj, "[SetPK] You successfully changed %s pk to %d.", tObj->Name, SetLevel);
		TNotice.MessageLog(1,tObj, "[SetPK] Your pk was changed to %d by %s.", SetLevel, gObj->Name);
	}
	return true;
}
//
bool cChat::ReloadCommand(LPOBJ gObj, char *Msg)
{
	if(CheckCommand(gObj, Configs.Commands.IsReload, GmSystem.cReload, 0, 0, 0, 0, "Reload", "/reload <number>", Msg))
		return true; 

	int NumberReload;
	sscanf(Msg,"%d",&NumberReload);

	switch (NumberReload)
	{
	case 0:
		{
			Configs.LoadAll();
			//MoveReq.Load();
			//ResetSystem.Init();
			TNotice.MessageLog(1,gObj, "[Reload] Data Reloaded.");
			break;
		}
	case 1:
		{
			GameMonsterAllCloseAndReLoad();
//#ifdef _GS
//			Monster.ReadMonsterAdd();
//#endif
			TNotice.MessageLog(1,  gObj, "[Reload] Monsters Reloaded.");
			break;
		}
	case 2:
		{
			ShopDataLoad();
			TNotice.MessageLog(1,  gObj, "[Reload] Shops Reloaded.");
			break;
		}
	case 3:
		{
			if (GmSystem.Config.IsGMSystem)
			{
				GmSystem.Load();
				TNotice.MessageLog(1,gObj, "[Reload] GMSystem Reloaded.");
			}
			else
				TNotice.MessageLog(1,gObj,"[Reload] GMSystem is disabled");
			break;
		}
	/*case 4:
		{
			DropSystem.Load();
#ifdef _GS
			DropEvent.updateBC();	// reload BC drop config
			DropEvent.updateIT();	// reload IT drop config
			DropEvent.updateWW();	// reload WW drop config
			DropEvent.updateCC();	// reload CC drop config
#endif
			MessageLog(1,  gObj, "[Reload] Item Drop Settings Reloaded.");
			break;
		}
	case 6:
		{
			Configs.LoadAll();
			GameMonsterAllCloseAndReload();
			pShopDataLoad();
			DropSystem.Load();
#ifdef _GS
			Monster.ReadMonsterAdd();
			DropEvent.updateBC();	// reload BC drop config
			DropEvent.updateIT();	// reload IT drop config
			DropEvent.updateWW();	// reload WW drop config
			DropEvent.updateCC();	// reload CC drop config
			ResetSystem.Init();
#endif
			MessageLog(1,  gObj, "[Reload] All Options Reloaded.");
			break;
		}
	default:
		{
			MessageLog(1,  gObj, "[Reload] Usage: /reload <Number>.");
			break;
		}*/
	} 
	return true;
}
//
bool cChat::StatusCommand(LPOBJ gObj, char *Msg, int Index)
{
	if(CheckCommand(gObj, Configs.Commands.IsStatus, GmSystem.cStatus, 0, 0, 0, Index, "Status", "[Name] /status", Msg))
		return true;

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	TNotice.MessageLog(0,gObj,"IP Address: %s",tObj->Ip_addr);
	TNotice.MessageLog(0,gObj,"Account: %s | Character: %s",tObj->AccountID,tObj->Name);
	TNotice.MessageLog(0,gObj,"Level: %d | Zen: %d",tObj->Level,tObj->Money);
	TNotice.MessageLog(0,gObj,"Map: %s (%d)(%d,%d)",User.GetMapName(tObj->MapNumber),tObj->MapNumber,tObj->X,tObj->Y); 

	/*if (AddTab[tObj->m_Index].IsMarried)
		MessageLog(0,  gObj, "Married on %s | Resets: %d", AddTab[tObj->m_Index].MarryName, AddTab[tObj->m_Index].Resets);
	else																								 
		MessageLog(0,  gObj, "Not married | Resets: %d", AddTab[tObj->m_Index].Resets);*/

	TNotice.MessageLog(1,  gObj, "[Status][GM] %s get your status!", gObj->Name);	  
	return true;
}
//
bool cChat::SkinCommand(LPOBJ gObj, char *Msg, int Index)
{  
	if(CheckCommand(gObj, Configs.Commands.SkinEnabled, GmSystem.cSkin, 0, 0, 0, Index, "Skin", "[Name] /skin <num>", Msg))
		return true;

	int NumSkin = 0;	

	sscanf(Msg,"%d", &NumSkin);

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	tObj->m_Change = NumSkin;
	gObjViewportListProtocolCreate(tObj);								
	if(tObj == gObj)
		TNotice.MessageLog(1,  tObj, "[Skin] Your Skin was changed.");
	else
	{
		TNotice.MessageLog(1,  gObj, "[Skin] You successfully change %s Skin.", tObj->Name);
		TNotice.MessageLog(1,  tObj, "[Skin] Your Skin was changed by %s.", gObj->Name);
	}
	return true;				
}

bool cChat::GmoveCommand(LPOBJ gObj, char *Msg, int Index)
{					
	if(CheckCommand(gObj, Configs.Commands.IsGmove, GmSystem.cGmove, 0, 0, 3, Index, "Gmove", "[Name] /gmove <map> <x> <y>", Msg))
		return true;

	char Map[250];
	int x,y;

	sscanf(Msg,"%s %d %d", &Map, &x, &y);
	LPOBJ tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	int aIndex = User.GetPlayerIndex(gObj->Name);

	int RMap;
	if(_strcmpi(Map, "0") == 0 || _strcmpi(Map, "Lorencia") == 0) RMap = MAP_INDEX_RORENCIA;
	else if	(_strcmpi(Map, "1") == 0 || _strcmpi(Map, "Dungeon") == 0) RMap = MAP_INDEX_DUNGEON;
	else if	(_strcmpi(Map, "2") == 0 || _strcmpi(Map, "Devias") == 0) RMap = MAP_INDEX_DEVIAS;
	else if (_strcmpi(Map, "3") == 0 || _strcmpi(Map, "Noria") == 0) RMap = MAP_INDEX_NORIA;
	else if (_strcmpi(Map, "4") == 0 || _strcmpi(Map, "Losttower") == 0) RMap = MAP_INDEX_LOSTTOWER;
	else if (_strcmpi(Map, "6") == 0 || _strcmpi(Map, "Stadium") == 0 || _strcmpi(Map, "Arena") == 0) RMap = MAP_INDEX_BATTLESOCCER;
	else if (_strcmpi(Map, "7") == 0 || _strcmpi(Map, "Atlans") == 0) RMap = MAP_INDEX_ATHLANSE;
	else if (_strcmpi(Map, "8") == 0 || _strcmpi(Map, "Tarkan") == 0) RMap = MAP_INDEX_TARKAN;		
	else if (_strcmpi(Map, "10") == 0 || _strcmpi(Map, "Icarus") == 0) RMap = 10;			  
	else if (_strcmpi(Map, "24") == 0 || _strcmpi(Map, "kalima1") == 0) RMap = 24;
	else if (_strcmpi(Map, "25") == 0 || _strcmpi(Map, "kalima2") == 0) RMap = 25; 
	else if (_strcmpi(Map, "26") == 0 || _strcmpi(Map, "kalima3") == 0) RMap = 26;		
	else if (_strcmpi(Map, "27") == 0 || _strcmpi(Map, "kalima4") == 0) RMap = 27;   
	else if (_strcmpi(Map, "28") == 0 || _strcmpi(Map, "kalima5") == 0) RMap = 28;
	else if (_strcmpi(Map, "29") == 0 || _strcmpi(Map, "kalima6") == 0) RMap = 29;   
	else if (_strcmpi(Map, "30") == 0 || _strcmpi(Map, "valleyofloren") == 0) RMap = 30;
	else if (_strcmpi(Map, "31") == 0 || _strcmpi(Map, "landoftrial") == 0 || _strcmpi(Map, "landsoftrial") == 0) RMap = 31;		 
	else if (_strcmpi(Map, "11") == 0 || _strcmpi(Map, "bc1") == 0) RMap = 11;   
	else if (_strcmpi(Map, "12") == 0 || _strcmpi(Map, "bc2") == 0) RMap = 12;  
	else if (_strcmpi(Map, "13") == 0 || _strcmpi(Map, "bc3") == 0) RMap = 13;   
	else if (_strcmpi(Map, "14") == 0 || _strcmpi(Map, "bc4") == 0) RMap = 14;  
	else if (_strcmpi(Map, "15") == 0 || _strcmpi(Map, "bc5") == 0) RMap = 15;  
	else if (_strcmpi(Map, "16") == 0 || _strcmpi(Map, "bc6") == 0) RMap = 16;  
	else if (_strcmpi(Map, "17") == 0 || _strcmpi(Map, "bc7") == 0) RMap = 17;    
	else if (_strcmpi(Map, "52") == 0 || _strcmpi(Map, "bc8") == 0) RMap = 52; 
	else if (_strcmpi(Map, "18") == 0 || _strcmpi(Map, "cc1") == 0) RMap = 18;
	else if (_strcmpi(Map, "19") == 0 || _strcmpi(Map, "cc2") == 0) RMap = 19;
	else if (_strcmpi(Map, "20") == 0 || _strcmpi(Map, "cc3") == 0) RMap = 20;
	else if (_strcmpi(Map, "21") == 0 || _strcmpi(Map, "cc4") == 0) RMap = 21;
	else if (_strcmpi(Map, "22") == 0 || _strcmpi(Map, "cc5") == 0) RMap = 22; 
	else if (_strcmpi(Map, "23") == 0 || _strcmpi(Map, "cc6") == 0) RMap = 23;  
	else if (_strcmpi(Map, "53") == 0 || _strcmpi(Map, "cc7") == 0) RMap = 53;    
	else if (_strcmpi(Map, "33") == 0 || _strcmpi(Map, "aida") == 0) RMap = 33;			   
	else if (_strcmpi(Map, "34") == 0 || _strcmpi(Map, "crywolf") == 0) RMap = 34;			   
	else if (_strcmpi(Map, "36") == 0 || _strcmpi(Map, "kalima7") == 0) RMap = 36;			   
	else if (_strcmpi(Map, "37") == 0 || _strcmpi(Map, "kanturu") == 0) RMap = 37;			   
	else if (_strcmpi(Map, "38") == 0 || _strcmpi(Map, "kanturutruins") == 0 || _strcmpi(Map, "kantrutruins") == 0) RMap = 38;			   
	else if (_strcmpi(Map, "39") == 0 || _strcmpi(Map, "kantrutower") == 0 || _strcmpi(Map, "kanturutower") == 0) RMap = 39;			   
	else if (_strcmpi(Map, "40") == 0 || _strcmpi(Map, "silent") == 0) RMap = 40;			   
	else if (_strcmpi(Map, "41") == 0 || _strcmpi(Map, "balgasbarrack") == 0) RMap = 41;			   
	else if (_strcmpi(Map, "42") == 0 || _strcmpi(Map, "balgasrefuge") == 0) RMap = 42;			   
	else if (_strcmpi(Map, "51") == 0 || _strcmpi(Map, "elbeland") == 0) RMap = 51;			   
	else if (_strcmpi(Map, "56") == 0 || _strcmpi(Map, "swampofcalmness") == 0 || _strcmpi(Map, "calmness") == 0) RMap = 56;			   
	else if (_strcmpi(Map, "57") == 0 || _strcmpi(Map, "raklion") == 0) RMap = 57;			   
	else if (_strcmpi(Map, "58") == 0 || _strcmpi(Map, "raklionboss") == 0) RMap = 58;			   
	else if (_strcmpi(Map, "62") == 0 || _strcmpi(Map, "santatown") == 0 || _strcmpi(Map, "santa") == 0) RMap = 62;			   
	else if (_strcmpi(Map, "63") == 0 || _strcmpi(Map, "vulcanus") == 0) RMap = 63;
	else if (_strcmpi(Map, "64") == 0 || _strcmpi(Map, "doppel1") == 0) RMap = MAP_INDEX_DOPPELGANGER_1;
	else if (_strcmpi(Map, "65") == 0 || _strcmpi(Map, "doppel2") == 0) RMap = MAP_INDEX_DOPPELGANGER_2;
	else if (_strcmpi(Map, "66") == 0 || _strcmpi(Map, "doppel3") == 0) RMap = MAP_INDEX_DOPPELGANGER_3;
	else if (_strcmpi(Map, "67") == 0 || _strcmpi(Map, "doppel4") == 0) RMap = MAP_INDEX_DOPPELGANGER_4;
	else if (_strcmpi(Map, "69") == 0 || _strcmpi(Map, "imperialfort1") == 0) RMap = MAP_INDEX_PARTYDUNGEON_DAYOFWEEK1;
	else if (_strcmpi(Map, "70") == 0 || _strcmpi(Map, "imperialfort2") == 0) RMap = MAP_INDEX_PARTYDUNGEON_DAYOFWEEK2;
	else if (_strcmpi(Map, "71") == 0 || _strcmpi(Map, "imperialfort3") == 0) RMap = MAP_INDEX_PARTYDUNGEON_DAYOFWEEK3;
	else if (_strcmpi(Map, "79") == 0 || _strcmpi(Map, "lorem market") == 0) RMap = MAP_INDEX_ROREN_MARKET;
	else if (_strcmpi(Map, "80") == 0 || _strcmpi(Map, "karutan1") == 0) RMap = MAP_INDEX_KARUTAN_1;
	else if (_strcmpi(Map, "81") == 0 || _strcmpi(Map, "karutan2") == 0) RMap = MAP_INDEX_KARUTAN_2;
	else if (_strcmpi(Map, "91") == 0 || _strcmpi(Map, "acheron") == 0) RMap = MAP_INDEX_ACHERON;
	else if (_strcmpi(Map, "92") == 0 || _strcmpi(Map, "arca") == 0) RMap = MAP_INDEX_ARCABATTLE;
	else if (_strcmpi(Map, "95") == 0 || _strcmpi(Map, "deventer") == 0) RMap = MAP_INDEX_DEVENTER;
	else if (_strcmpi(Map, "96") == 0 || _strcmpi(Map, "arcadeventer") == 0) RMap = MAP_INDEX_ARCABATTLE_DEVENTER;
	else if (_strcmpi(Map, "72") == 0 || _strcmpi(Map, "ccf") == 0) RMap = MAP_INDEX_CCF;
	else if (_strcmpi(Map, "98") == 0 || _strcmpi(Map, "itl1") == 0) RMap = MAP_INDEX_ITL1;
	else if (_strcmpi(Map, "99") == 0 || _strcmpi(Map, "itl2") == 0) RMap = MAP_INDEX_ITL2;
	else if (_strcmpi(Map, "100") == 0 || _strcmpi(Map, "uruk1") == 0) RMap = MAP_INDEX_URUK_MOUNTAIN;
	else if (_strcmpi(Map, "101") == 0 || _strcmpi(Map, "uruk2") == 0) RMap = MAP_INDEX_URUK_MOUNTAIN2;
	else if (_strcmpi(Map, "102") == 0 || _strcmpi(Map, "dsf") == 0) RMap = MAP_INDEX_DSF;
	else
	{
		TNotice.MessageLog(1,gObj,"[GMove] Such map doesn't exist!");	
		return true;
	} 
	if(x > 255 || y > 255 || x < 0 || y < 0)
	{	 								   
		TNotice.MessageLog(1,gObj,"[GMove] Such coords doesn't exist!");	
		return true;
	}  			
	gObjTeleport(tObj->m_Index, RMap, x, y);		
	if(tObj == gObj)		 
		TNotice.MessageLog(1,gObj,"[GMove] You successfully moved to %s %d %d!", Map, x, y);
	else
	{	   
		TNotice.MessageLog(1,gObj,"[GMove] You successfully move %s to %s %d %d!", tObj->Name, Map, x, y);
		TNotice.MessageLog(1,tObj,"[GMove] You successfully moved to %s %d %d by %s!", Map , x, y, gObj->Name);
	}
	return true;
}
//
bool cChat::PKClearCommand(LPOBJ gObj, char *Msg, int Index)
{
	if(CheckCommand(gObj, PkClear.ClearCommand.Enabled, GmSystem.NONE, 0, 0, 0, Index, "PKClear", "/pkclear", Msg))
		return true;

	if(GmSystem.IsCommand(GmSystem.cPkClear, gObj->Name))
	{
		OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

		if (tObj->m_PK_Level <=3)
		{												
			TNotice.SendNotice(Index,1,"[PkClear] %s is not pk!", tObj->Name);			
			return true;
		}	 				   

		tObj->m_PK_Level = 3;
		tObj->m_PK_Count = 0;
		GCPkLevelSend(tObj->m_Index, 3);	 					

		if (tObj == gObj)
		{
			TNotice.SendNotice(Index,1,"[PkClear] Your pk was cleared.");	
		}
		else
		{
			TNotice.SendNotice(Index,1, "[PkClear] You successfully clear %s pk.", tObj->Name);
			TNotice.SendNotice(Index,1, "[PkClear] Your pk was cleared by %s.", gObj->Name);	
		}
	}
	else if(!PkClear.ClearCommand.OnlyForGm)
	{
		int PriceZen;
		switch(PkClear.ClearCommand.Type)
		{	   
		case 1:	
			PriceZen = (PkClear.ClearCommand.PriceZen * gObj->m_PK_Count); 		 
			break;
		case 2:	
			PriceZen = PkClear.ClearCommand.PriceZenForAll;			 
			break;
		case 0: 
			PriceZen = 0;					 
			break;
		}

		if (gObj->m_PK_Level <=3)
		{												
			TNotice.SendNotice(Index,1,"[PkClear] Your are not pk!");			
			return true;
		}			
		if(CheckCommand(gObj, PkClear.ClearCommand.Enabled, GmSystem.NONE, PriceZen, PkClear.ClearCommand.LevelReq, 0, 0, "PKClear", "/pkclear", Msg))
			return true;

		TakeCommand(gObj, PriceZen,"PKClear");	
		gObj->m_PK_Level = 3;
		gObj->m_PK_Count = 0;
		GCPkLevelSend(gObj->m_Index, 3);	 
		TNotice.SendNotice(Index,1,"[PkClear] Your Pk successfully cleared!");
	}
	return true;				
}


bool cChat::AddCommands(LPOBJ gObj, char *Msg, int Type)
{
	int aIndex = User.GetPlayerIndex(gObj->Name);

	switch (Type)
	{
	case 0:
		if (CheckCommand(gObj, Configs.Commands.AddPointEnabled, GmSystem.NONE, Configs.Commands.AddPriceZen,
			Configs.Commands.AddPointLevelReq, 1, 0, "AddStats", "/addstr <num>", Msg))
			return true;
		break;
	case 1:
		if (CheckCommand(gObj, Configs.Commands.AddPointEnabled, GmSystem.NONE, Configs.Commands.AddPriceZen, Configs.Commands.AddPointLevelReq, 1, 0, "AddStats", "/addagi <num>", Msg))
			return true;
		break;
	case 2:
		if (CheckCommand(gObj, Configs.Commands.AddPointEnabled, GmSystem.NONE, Configs.Commands.AddPriceZen, Configs.Commands.AddPointLevelReq, 1, 0, "AddStats", "/addvit <num>", Msg))
			return true;
		break;
	case 3:
		if (CheckCommand(gObj, Configs.Commands.AddPointEnabled, GmSystem.NONE, Configs.Commands.AddPriceZen, Configs.Commands.AddPointLevelReq, 1, 0, "AddStats", "/addene <num>", Msg))
			return true;
		break;
	case 4:
		if (CheckCommand(gObj, Configs.Commands.AddPointEnabled, GmSystem.NONE, Configs.Commands.AddPriceZen, Configs.Commands.AddPointLevelReq, 1, 0, "AddStats", "/addcmd <num>", Msg))
			return true;
		if (gObj->Class != 4)
		{
			TNotice.SendNotice(aIndex, 1, "[AddStats] You are not Dark Lord!!!");
			//MessageLog(1, gObj, "[AddStats] You are not Dark Lord!!!");
			return true;
		}
		break;
	}
	DWORD Points;
	sscanf(Msg, "%d", &Points);

	if (Configs.Commands.MaxAddedStats > 0 && Configs.Commands.MaxAddedStats <= Points)
	{
		TNotice.SendNotice(aIndex, 1, "[AddStats] You can't add more than %d stats!!!", Configs.Commands.MaxAddedStats);
		return true;
	}

	int MaxPoints = 32767;
	//if(Configs.Enable65kStats >= 1)
	//	MaxPoints = -536;	

	int Stats = 0;
	bool bResult = false;
	switch (Type)
	{
	case 0x00:
		Stats = gObj->Strength;
		if (gObj->Class == 0)
			MaxPoints;
		else if (gObj->Class == 1)
			MaxPoints;
		else if (gObj->Class == 2)
			MaxPoints;
		else if (gObj->Class == 3)
			MaxPoints;
		else if (gObj->Class == 4)
			MaxPoints;
		else if (gObj->Class == 5)
			MaxPoints;
		break;
	case 0x01:
		Stats = gObj->Dexterity;
		if (gObj->Class == 0)
			MaxPoints;
		else if (gObj->Class == 1)
			MaxPoints;
		else if (gObj->Class == 2)
			MaxPoints;
		else if (gObj->Class == 3)
			MaxPoints;
		else if (gObj->Class == 4)
			MaxPoints;
		else if (gObj->Class == 5)
			MaxPoints;
		break;
	case 0x02:
		Stats = gObj->Vitality;
		if (gObj->Class == 0)
			MaxPoints;
		else if (gObj->Class == 1)
			MaxPoints;
		else if (gObj->Class == 2)
			MaxPoints;
		else if (gObj->Class == 3)
			MaxPoints;
		else if (gObj->Class == 4)
			MaxPoints;
		else if (gObj->Class == 5)
			MaxPoints;
		break;
	case 0x03:
		Stats = gObj->Energy;
		if (gObj->Class == 0)
			MaxPoints;
		else if (gObj->Class == 1)
			MaxPoints;
		else if (gObj->Class == 2)
			MaxPoints;
		else if (gObj->Class == 3)
			MaxPoints;
		else if (gObj->Class == 4)
			MaxPoints;
		else if (gObj->Class == 5)
			MaxPoints;
		break;
	case 0x04:
		Stats = gObj->Leadership;
		if (gObj->Class == 4)
			MaxPoints;
		break;
	}

	int MaxPointsTemp = MaxPoints;
	if (MaxPoints > 32767)
		MaxPoints = -32768 + (MaxPoints - 32767);

	if (((MaxPoints > 0) && (Stats >= MaxPoints || Stats < 0)) ||
		((MaxPoints < 0) && (Stats < 0) && (Stats >= MaxPoints)))
	{
		TNotice.SendNotice(aIndex, 1, "[AddStats] You have max points for this type!!!");
		return true;
	}

	int StatsTemp = Stats;
	Stats += Points;
	if (gObj->LevelUpPoint < Points)
	{
		TNotice.SendNotice(aIndex, 1, "[AddStats] You don't have enough points to add. Need %d more.", Points - gObj->LevelUpPoint);
		return true;
	}

	if (((MaxPoints > 0) && (Stats > MaxPoints || Stats < 0)) ||
		((MaxPoints < 0) && (Stats < 0) && (Stats > MaxPoints)))
	{
		TNotice.SendNotice(aIndex, 1, "[AddStats] You can't add more than %d points for this type!!!", MaxPoints - StatsTemp);
		return true;
	}

	TakeCommand(gObj, Configs.Commands.AddPriceZen, "AddStats");

	switch (Type)
	{
	case 0x00://str
	{
		//PMSG_CHARREGEN pMsg;
		PMSG_STAT_UPDATE pMsg;
		PHeadSetB((LPBYTE)&pMsg, 0x2C, sizeof(PMSG_STAT_UPDATE));
		pMsg.result = 0;
		pMsg.btFruitType = 3;
		pMsg.btStatValue = Points;
		gObj->Strength += Points;
		gObj->LevelUpPoint -= Points;

		GCLevelUpMsgSend(gObj->m_Index, 1);
		gObjCalCharacter(gObj->m_Index);
		gObjSetBP(gObj->m_Index);

		DataSend(gObj->m_Index, (char*)&pMsg, pMsg.h.size);
		//Utilits.SendEffect(gObj, 5);
		return true;
	}
	case 0x01://agi
	{
		PMSG_STAT_UPDATE pMsg;
		PHeadSetB((LPBYTE)&pMsg, 0x2C, sizeof(PMSG_STAT_UPDATE));
		pMsg.result = 0;
		pMsg.btFruitType = 2;
		pMsg.btStatValue = Points;
		gObj->Dexterity += Points;
		gObj->LevelUpPoint -= Points;

		GCLevelUpMsgSend(gObj->m_Index, 1);
		gObjCalCharacter(gObj->m_Index);
		gObjSetBP(gObj->m_Index);

		DataSend(gObj->m_Index, (char*)&pMsg, pMsg.h.size);

		return true;
	}
	case 0x02://vit
	{
		PMSG_STAT_UPDATE pMsg;
		PHeadSetB((LPBYTE)&pMsg, 0x2C, sizeof(PMSG_STAT_UPDATE));
		pMsg.result = 0;
		pMsg.btStatValue = Points;
		pMsg.btFruitType = 1;
		DataSend(gObj->m_Index, (char*)&pMsg, pMsg.h.size);
		gObj->Vitality += Points;
		gObj->MaxLife += gObj->VitalityToLife * Points;

		gObj->LevelUpPoint -= Points;
		GCLevelUpMsgSend(gObj->m_Index, 1);
		gObjCalCharacter(gObj->m_Index);
		GCReFillSend(gObj->m_Index, gObj->MaxLife + gObj->AddLife, 0xFE, 0, gObj->iMaxShield + gObj->iAddShield);
		gObjSetBP(gObj->m_Index);
		//Utilits.SendEffect(gObj, 2);
		return true;
	}
	case 0x03://ene
	{
		PMSG_STAT_UPDATE pMsg;
		PHeadSetB((LPBYTE)&pMsg, 0x2C, sizeof(PMSG_STAT_UPDATE));
		pMsg.result = 0;
		pMsg.btFruitType = 0;
		pMsg.btStatValue = Points;
		DataSend(gObj->m_Index, (char*)&pMsg, pMsg.h.size);
		gObj->Energy += Points;
		gObj->MaxMana += gObj->EnergyToMana * Points;

		gObj->LevelUpPoint -= Points;
		GCLevelUpMsgSend(gObj->m_Index, 1);
		gObjCalCharacter(gObj->m_Index);
		GCManaSend(gObj->m_Index, gObj->MaxMana + gObj->AddMana, 0xFE, 0, gObj->MaxBP + gObj->AddBP);
		gObjSetBP(gObj->m_Index);

		//Utilits.SendEffect(gObj, 2);
		return true;
	}
	case 0x04://cmd
	{
		PMSG_STAT_UPDATE pMsg;
		PHeadSetB((LPBYTE)&pMsg, 0x2C, sizeof(PMSG_STAT_UPDATE));
		pMsg.result = 0;
		pMsg.btFruitType = 4;
		pMsg.btStatValue = Points;
		gObj->Leadership += Points;
		gObj->LevelUpPoint -= Points;

		DataSend(gObj->m_Index, (char*)&pMsg, pMsg.h.size);
		gObjCalCharacter(aIndex);
		gObjSetBP(aIndex);
		GCLevelUpMsgSend(gObj->m_Index, 0);
		//Utilits.SendEffect(gObj, 2);
		return true;
	}
	default:
	{
		return true;
	}
	}

	TNotice.SendNotice(aIndex, 1, "[AddStats] Your stats successfully added!");
	TNotice.SendNotice(aIndex, 1, "Please Relog!");
	return true;
}

//bool cChat::AddMobCommand(LPOBJ gObj, char *Msg)
//{
//#ifdef _GS
//	if(CheckCommand(gObj, 1, GmSystem.cSetZen, 0, 0, 0, 0, "AddMob", "/mobadd <mobid> <count> <speed> <distance> <map> <x> <y>", Msg))
//		return true;
//
//	int Mob;
//	int Map = gObj->MapNumber;
//	int Speed = 10;
//	int X1 = (int)gObj->X, X2 = (int)gObj->X;
//	int Y1 = (int)gObj->Y, Y2 = (int)gObj->Y;
//	int Dir = -1;
//	int Count = 1;
//	int Distance = 0;
//
//	sscanf(Msg, "%d %d %d %d %d %d %d", &Mob, &Count, &Speed, &Distance, &Map, &X1, &Y1);
//
//	FILE* AddMobFile;  
//
//	if((AddMobFile = fopen(NNMobAdd,"a+")) == NULL)
//	{						   
//		MessageBox(NULL, "Cant Find MonsterSpawn.ini", "Error", 0);
//	}
//	else
//	{				
//		//ID, Count, Speed, Distance, Map, X, Y
//		//Mob,Map,Speed,x1,y1,x2,y2,dir,count
//		//17	9	30	119	80	150	115	-1	35 // Cyclops
//		if(Count == 1)
//			Dir = gObj->Dir;
//		if(Distance > 0)
//		{
//			X1 -= Distance;
//			Y1 -= Distance;
//			X2 += Distance;
//			Y2 += Distance;
//		}
//
//		fprintf(AddMobFile, "\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", Mob, Map, Speed, X1, Y1, X2, Y2, Dir, Count); 	 
//		fclose(AddMobFile);
//	}		 
//	for(int i = 0; i < Count; i++)
//	{
//		Monster.MonsterAddAndSpawn(Mob, Map, Speed, X1, Y1, X2, Y2, Dir);
//	}
//	TNotice.MessageLog(1, gObj, "[AddMob] %d Mob Successfully spawned (Map: %d, X: %d, Y: %d, MobID: %d)", Count,Map,X1,Y1, Mob);
//#endif
//	return true;
//}
void cChat::DropCommand(LPOBJ gObj, char *Msg, int aIndex)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);
	if (!OBJMAX_RANGE(aIndex)) return;
	if (!gObjIsConnected(aIndex)) return;

	if (CheckCommand(lpObj, Configs.Commands.IsDrop, GmSystem.cDrop, 0, 0, 0, aIndex, "Drop", "[Name] /drop <ItemType> <ItemIndex> <Level> <Skill> <Luck> <JoLOption> <Excellent> <Ancient> <Count>", Msg))
		return;

	int ItemType = 0;
	int ItemIndex = 0;
	int Level = 0;
	int Skill = 0;
	int Luck = 0;
	int JoLOption = 0;
	int Durability = 0;
	int Excellent = 0;
	int Ancient = 0;
	int Element = 0;
	int Count = 0;

	if (Count < 1 || Count > 10) Count = 1;
	sscanf(Msg, "%d %d %d %d %d %d %d %d %d", &ItemType, &ItemIndex, &Level, &Skill, &Luck, &JoLOption, &Excellent, &Ancient, &Count);
	if ((ItemType < 0 || ItemType > 15) || ItemIndex < 0 || (Level<0 || Level > 15) || (Skill < 0 || Skill > 1) || (Luck < 0 || Luck > 1) || (JoLOption < 0 || JoLOption > 7) || (Durability < 0 || Durability > 255) || (Excellent < 0 || Excellent > 63) || (Ancient < 0 || Ancient > 40))
	{
		TNotice.SendNotice(aIndex, 1, "[Drop] Usage: /drop <ItemType> <ItemIndex> <Level> <Skill> <Luck> <JoLOption> <Excellent> <Ancient> <Count>");
		return;
	}
	else
	{
		int ItemNumber = ITEMGET(ItemType, ItemIndex);

		for (int i = 0; i < Count; i++)
		{
			if (ItemNumber == ITEMGET(13, 4) || ItemNumber == ITEMGET(13, 5)) //Dark Horse and Raven
			{


				PetItemSerialCreateSend(aIndex, lpObj->MapNumber, lpObj->X, lpObj->Y, ItemNumber,
					Level, Durability, Skill, Luck, JoLOption, aIndex, Excellent, 0);
			}
			else
			{
				ItemSerialCreateSend(aIndex, lpObj->MapNumber, lpObj->X, lpObj->Y, ItemNumber,
					Level, Durability, Skill, Luck, JoLOption, aIndex, Excellent, Ancient, 0, 0, 0, Element);
			}
		}
		TNotice.SendNotice(aIndex, 1, "[Drop] %d Item Created %d %d %d %d %d %d %d %d %d %d - Success",
			Count, ItemType, ItemIndex, Level, Durability, Skill, Luck, JoLOption, Excellent, Ancient, Element);
	}

	return;
}
bool cChat::SetDropCommand(LPOBJ gObj, char *Msg, int Index)
{					
	if(CheckCommand(gObj, Configs.Commands.IsDrop, GmSystem.cDrop, 0, 0, 1, Index, "SetDrop", "[Name] /setdrop <ItemIndex> <ItemLvl> <ItemLuck> <ItemOpt> <ItemExc> <ItemAnc>", Msg))
		return true;

	//int ItemType = 0;
	int ItemIndex = 0;
	int Level = 0;
	int Skill = 0;
	int Luck = 0;
	int JoLOption = 0;
	int Durability = 0;
	int Excellent = 0;
	int Ancient = 0;
	int Element = 0;
	int ItemMin = 7;

	//MG Set Season 4.6
	if(ItemIndex == 15 || ItemIndex == 20 || ItemIndex == 23 || ItemIndex == 32 || ItemIndex == 37 || ItemIndex == 47 || ItemIndex == 48)
	ItemMin = 8;

	//sscanf(Msg, "%d %d %d %d %d %d", &ItemIndex, &ItemLevel, &ItemLuck, &ItemOpt, &ItemExc, &ItemAncient);
	sscanf(Msg, "%d %d %d %d %d %d %d %d", &ItemIndex, &Level, &Skill, &Luck, &JoLOption, &Excellent, &Ancient, &ItemMin);
	if (ItemIndex < 0 || (Level<0 || Level > 15) || (Skill < 0 || Skill > 1) || (Luck < 0 || Luck > 1) || (JoLOption < 0 || JoLOption > 7) || (Durability < 0 || Durability > 255) || (Excellent < 0 || Excellent > 63) || (Ancient < 0 || Ancient > 40))
	
		//if(ItemIndex < 0 || (ItemLevel<0 || ItemLevel > 13) || (ItemOpt < 0 || ItemOpt > 7) || (ItemLuck < 0 || ItemLuck > 1) || (ItemExc < 0 || ItemExc > 63) || (ItemAncient < 0 || ItemAncient > 40))
	{
		//TNotice.SendNotice(aIndex, 1, "[SetDrop] Usage: /setdrop <ItemType> <ItemIndex> <Level> <Skill> <Luck> <JoLOption> <Durability> <Excellent> <Ancient> <Count>");
		TNotice.MessageLog(1,  gObj, "[SetDrop] Usage: /setdrop  <ItemIndex> <Level> <Skill> <Luck> <JoLOption> <Excellent> <Ancient>");
		return true;
	}

	OBJECTSTRUCT *gUbj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	for(int i = ItemMin; i < 12; i++)
	{
		int Item = i * 512 + ItemIndex;
		int Rand1 = rand() % 3;
		int Rand2 = rand() % 3;
		//ItemSerialCreateSend(gUbj->m_Index, gUbj->MapNumber, (int)gUbj->X + Rand1, (int)gUbj->Y + Rand2, Item, ItemLevel, 0, 0, 
		//	ItemLuck, ItemOpt, gUbj->m_Index, ItemExc, ItemAncient, lDuration, dwEventIndex, SocketOption, MainAttribute);
		
		ItemSerialCreateSend(gUbj->m_Index, gUbj->MapNumber, gUbj->X + Rand1, gUbj->Y + Rand2, Item,
			Level, Durability, Skill, Luck, JoLOption, gUbj->m_Index, Excellent, Ancient, 0, 0, 0, Element);
		//ItemSerialCreateSend(Index, tObj->MapNumber, (int)tObj->X, (int)tObj->Y, Item, ItemLevel, 0, ItemSkill, ItemLuck, ItemOpt, Index, ItemExc, ItemAncient, lDuration, dwEventIndex, SocketOption, MainAttribute);
	}
	return true;
}


//bool cChat::GuildPost(LPOBJ gObj, char *Msg)
//{ 
//	int aIndex = User.GetPlayerIndex(gObj->Name);
//
//	if(gObj->GuildStatus == 128 || gObj ->GuildStatus == 64 || gObj ->GuildStatus == 32)
//		GDGuildNoticeSave(gObj->GuildName, Msg);
//	else
//		TNotice.SendNotice(aIndex,1,"You aren't guild master or assistant");	
//	return true;
//}
//
//bool cChat::Core(LPOBJ gObj, char *Msg)
//{ 
//	MessageLog(1,  gObj,"IA Julia 1.1.%d.%d, Compiled %s %s",dBuild, dCommit, __DATE__, __TIME__);	
//	return true;
//}
//
bool cChat::SetZenCommand(LPOBJ gObj, char* Msg, int Index)
{
	if(CheckCommand(gObj, Configs.Commands.IsSetZen, GmSystem.cSetZen, 0, 0, 1, Index, "SetZen", "[Name] /setzen <Zen>", Msg))
		return true;

	DWORD Zen = 0;

	sscanf(Msg, "%d", &Zen);

	if(Zen <= 0 || Zen > 2000000000)
	{
		TNotice.MessageLog(1,  gObj, "[SetZen] Zen can't be less than 1 and more than 2000000000!");
		return true;
	}	

	OBJECTSTRUCT *tObj = (OBJECTSTRUCT*)OBJECT_POINTER(Index);

	tObj->Money = Zen;
	GCMoneySend(tObj->m_Index, Zen);
	if (gObj == tObj)
	{
		TNotice.MessageLog(1,tObj, "[SetZen] Your zen was edited!");
	}
	else
	{
		TNotice.MessageLog(1,gObj, "[SetZen] You successfully changed %s zen.", tObj->Name);
		TNotice.MessageLog(1,tObj, "[SetZen] Your zen was edited by %s!", gObj->Name);
	}
	return true;
}			

//bool cChat::OffTradeCommand( LPOBJ gObj)
//{ 
//#ifdef _GS
//	if(CheckCommand(gObj, OfflineTrade.Configs.Enabled, GmSystem.NONE, OfflineTrade.Configs.PriceZen, 0, OfflineTrade.Configs.LevelReq, 0,"OffTrade", "/off", ""))
//		return true;
//	if(gObj->m_bPShopOpen == false)
//	{
//
//		TNotice.MessageLog(1, gObj, "[OffTrade] Personal Shop isn't oppened");
//		return false;
//	} 
//	if(gObj->MapNumber != 0)
//	{
//		TNotice.MessageLog(1, gObj, "[OffTrade] You can use OffTrade only in Lorencia");
//		return false;
//	}
//	TakeCommand(gObj,OfflineTrade.Configs.PriceZen,"OffTrade"); 
//	OfflineTrade.CreateOfflineStore(gObj->m_Index);
//#endif
//	return true;
//}
//

//bool cChat::ResetCommand( LPOBJ gObj)
//{   
//	ResetSystem.Reset(gObj);
//	return true;
//} 
//