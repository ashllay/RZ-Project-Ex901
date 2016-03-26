#ifndef USEREX__H_
#define USEREX__H_
#include "User.h"
#include "CashShopInGame.h"

int POBJEX(int aIndex);
#define MAX_OBJ_EX (OBJ_MAX-OBJ_MIN)

struct PMSG_REQUEST_USEREX
{
	char Head[4];
	int aIndex;
	char Name[11];
};

struct PMSG_RETURN_USEREX
{
	char Head[4];
	int aIndex;
	char Name[11];
	int Resets;
};

struct PMSG_SAVE_RESETS
{
	char Head[4];
	int aIndex;
	char Name[11];
	int Resets;
};

class LPOBJEX
{
public:

	void Clear()
	{
#if(COMPILE_CASHSHOP==1)
#endif
	};

	int		POST_Delay;
#if(COMPILE_CASHSHOP==1)
#endif
	BYTE	OffTradeWaitItem;
	BYTE	bOffTrade;
	int		iOffTradeTime;
};

class CUserEx 
{
public:
	void Init();
	void Connect(int aIndex);
	//void RequestExData(int aIndex);
	//void ResultExData(PMSG_RETURN_USEREX * lpMsg);
	//void SaveResets(int aIndex);
};

extern CUserEx UserEx;

extern LPOBJEX * gObjEx;
#endif