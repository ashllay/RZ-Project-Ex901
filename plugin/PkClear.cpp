#include "StdAfx.h"
cPkClear PkClear;

void cPkClear::LoadPkClear()
{			
	//		pkclear		//	
	ClearCommand.Enabled				= Configs.GetInt(0, 1, 1, "PkClear", "PkClearEnabled", RZCmd);
	if(ClearCommand.Enabled)
	{
		ClearCommand.OnlyForGm				= Configs.GetInt(0, 1,						0,		 "PkClear",	"PkClearOnlyForGm",			RZCmd);
		ClearCommand.Type					= Configs.GetInt(0, 2,						1,		 "PkClear",	"PKClearType",				RZCmd);	 																													
		ClearCommand.PriceZen				= Configs.GetInt(0, 2000000000,				100000,  "PkClear",	"PkClearPriceZen",			RZCmd);	 
		ClearCommand.PriceZenForAll			= Configs.GetInt(0, 2000000000,				1000000, "PkClear",	"PkClearPriceZenForAll",	RZCmd);
		ClearCommand.LevelReq				= Configs.GetInt(0, Configs.Commands.MaxLvl,100,	 "PkClear",	"PkClearLevelReq",			RZCmd);  		  
		
	}

	ClearNpc.Enabled				= Configs.GetInt(0, 1, 1, "PkClearGuard", "LoadPkGuard", RZPkClear);
	if(ClearNpc.Enabled)
	{
		ClearNpc.NpcId					= Configs.GetInt(0, 32000,		249,	"PkClearGuard",	"PkClearGuardId",				RZPkClear);	   				 
		ClearNpc.Type					= Configs.GetInt(0, 2,			1,		"PkClearGuard",	"PKClearGuardType",				RZPkClear);																															
		ClearNpc.PriceZen				= Configs.GetInt(0, 2000000000,	100000,	"PkClearGuard",	"PkClearGuardPriceZen",			RZPkClear);	 
		ClearNpc.PriceZenForAll			= Configs.GetInt(0, 2000000000,	1000000,"PkClearGuard",	"PkClearGuardPriceZenForAll",	RZPkClear);
		ClearNpc.LevelReq				= Configs.GetInt(0, 400,		100,	"PkClearGuard",	"PkClearGuardLevelReq",			RZPkClear);
	}
}	   

void cPkClear::PkClear(LPOBJ gObj, LPOBJ NpcObj)
{
	int aIndex = User.GetPlayerIndex(gObj->Name);

	if (gObj->m_PK_Level < 4)
	{										 
		TNotice.NPCMessageLog(gObj, NpcObj, "You are good player. God bless your soul.");
		return;
	}	

	int PriceZen;
	switch(ClearNpc.Type)
	{	   
	case 1:	
		PriceZen = (ClearNpc.PriceZen * gObj->m_PK_Count);
		break;
	case 2:	
		PriceZen = ClearNpc.PriceZenForAll;			 
		break;
	case 0: 
		PriceZen = 0;					 
		break;
	}

	if(gObj->Money < PriceZen)
	{
		TNotice.NPCMessageLog(gObj, NpcObj, "You don't have enough Zen, you need %d more!", PriceZen - gObj->Money);
		return;
	}	   

	if (PriceZen > 0)
	{															 
		gObj->Money -= PriceZen; 
		GCMoneySend(gObj->m_Index, gObj->Money);
		TNotice.SendNotice(aIndex,1,"[Guard] You pay %d Zen", PriceZen);
	}

	TNotice.NPCMessageLog(gObj, NpcObj,"Cleaned %d kills. Don't tell anyone!", gObj->m_PK_Count); 

	gObj->m_PK_Level = 3;
	gObj->m_PK_Count = 0;

	GCPkLevelSend(gObj->m_Index,3);
}

bool cPkClear::NPCTalkEx(LPOBJ gObj, int NpcId)
{
	bool bResult = false;

	if (OBJECT_MAXRANGE(NpcId) == FALSE)
		return false;

	if (OBJECT_MAXRANGE(gObj->m_Index) == FALSE)
		return false;

	OBJECTSTRUCT *gObjNPC = (OBJECTSTRUCT*)OBJECT_POINTER(NpcId);
	if ((gObjNPC->Class == ClearNpc.NpcId) && (ClearNpc.Enabled))
	{
		PkClear(gObj, gObjNPC);
		bResult = true;		
	}
	return bResult;
}