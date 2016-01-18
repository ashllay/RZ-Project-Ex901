#ifndef PROTOC_H
#define PROTOC_H	   								

#include "User.h"
#include "Prodef.h"

bool ProtocolCoreEx(BYTE protoNum, BYTE *aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
void DataSendEx(int aIndex,unsigned char* aSend, int aLen);

#endif