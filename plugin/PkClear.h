#ifndef PKCLEAR_H
#define PKCLEAR_H
#pragma once
#include "StdAfx.h"

class cPkClear
{
public:
	void LoadPkClear();
	bool NPCTalkEx(LPOBJ gObj, int NpcId); 																  
	struct sPkClear
	{
		int Enabled;
		int NpcId;	  
		int OnlyForGm;
		int Type;	
		DWORD PriceZen;
		DWORD PriceZenForAll;	  
		int LevelReq;
	};	

	sPkClear ClearNpc;			 
	sPkClear ClearCommand;
private:			
	void PkClear(LPOBJ gObj, LPOBJ NpcObj); 
};
extern cPkClear PkClear;
#endif