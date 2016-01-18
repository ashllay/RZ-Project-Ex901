#include "StdAfx.h"

static unsigned char bBuxCode[3]={0xFC, 0xCF, 0xAB};	// Xox Key for some interesting things :)
void BuxConvert(char* buf, int size)
{
	int n;

	for (n=0;n<size;n++)
	{
		buf[n]^=bBuxCode[n%3] ;		// Nice trick from WebZen
	}
}

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] = 0xC1;
	lpBuf[1] = size;
	lpBuf[2] = head;
}

void PHeadSetBE(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] = 0xC3;
	lpBuf[1] = size;
	lpBuf[2] = head;
}

void PHeadSubSetB(LPBYTE Packet,BYTE Head,BYTE SubHead,BYTE Size)
{
    Packet[0] = 0xC1;
	Packet[1] = Size;
	Packet[2] = Head;
	Packet[3] = SubHead;
}

void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size)
{
	lpBuf[0] = 0xC3;
	lpBuf[1] = size;
	lpBuf[2] = head;
	lpBuf[3] = sub;
}