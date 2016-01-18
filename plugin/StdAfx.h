#ifndef STDAFX_H
#define STDAFX_H

#pragma warning(disable: 4786)
#pragma warning(disable: 4099)
#pragma warning(disable: 4244)

//#define DebugConsole 1

#define INTERNATIONAL_KOREAN

#define PROTOCOL_MOVE_GS		0xD3
#define PROTOCOL_POSITION_GS	0xDF
#define PROTOCOL_ATTACK_GS		0xD7
#define PROTOCOL_BEATTACK_GS	0x10

#ifdef INTERNATIONAL_THAILAND
#define PROTOCOL_MOVE		0x11
#define PROTOCOL_POSITION	0xD4
#define PROTOCOL_ATTACK		0xD6
#define PROTOCOL_BEATTACK	0xD9
#endif

#ifdef INTERNATIONAL_KOREAN	
#define PROTOCOL_MOVE		0xD3
#define PROTOCOL_POSITION	0xDF
#define PROTOCOL_ATTACK		0xD7
#define PROTOCOL_BEATTACK	0x10
#endif

#ifdef INTERNATIONAL_ENGLISH
#define PROTOCOL_MOVE		0xD4
#define PROTOCOL_POSITION	0x15
#define PROTOCOL_ATTACK		0x11
#define PROTOCOL_BEATTACK	0xDB
#endif

#ifdef INTERNATIONAL_JAPAN
#define PROTOCOL_MOVE		0x1D
#define PROTOCOL_POSITION	0xD6
#define PROTOCOL_ATTACK		0xDC
#define PROTOCOL_BEATTACK	0xD7
#endif

#ifdef INTERNATIONAL_CHINA
#define PROTOCOL_MOVE		0xD7
#define PROTOCOL_POSITION	0xDA
#define PROTOCOL_ATTACK		0xD9
#define PROTOCOL_BEATTACK	0x1D
#endif

#ifdef INTERNATIONAL_TAIWAN
#define PROTOCOL_MOVE		0xD6
#define PROTOCOL_POSITION	0xDF
#define PROTOCOL_ATTACK		0xDD
#define PROTOCOL_BEATTACK	0xD2
#endif

#ifdef INTERNATIONAL_VIETNAM
#define PROTOCOL_MOVE		0xD9
#define PROTOCOL_POSITION	0xDC
#define PROTOCOL_ATTACK		0x15
#define PROTOCOL_BEATTACK	0x1D
#endif

#ifdef INTERNATIONAL_PHILIPPINES
#define PROTOCOL_MOVE		0xDD
#define PROTOCOL_POSITION	0xDF
#define PROTOCOL_ATTACK		0xD6
#define PROTOCOL_BEATTACK	0x11
#endif



#pragma once

#include "Resource.h"

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE

// Windows Header Files:
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <Rpc.h> // Protectl
#pragma comment ( lib,  "Rpcrt4.lib" ) //Protect
#pragma comment ( lib , "comctl32.lib" )
#pragma comment ( lib , "WS2_32.lib" )
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <process.h>
#include <algorithm>
#include <math.h>
#include <atltime.h>
#include <string>
#include <string.h>
#include <fcntl.h>
#include <io.h>
#include <WinDef.h>
//
#include "Protocol.h"
#include "Prodef.h"
#include "Utilits.h"
#include "Hooks.h"
#include "User.h"
#include "Offsets.h"
#include "Fixes.h"
#include "Configs.h"
#include "Readscript.h"
#include "TMessage.h"
#include "Main.h"


//#include "SecuredMemory.h"
#endif
