#pragma once

#include "Config.h"

enum PacketTypes
{
	NONE = 0,
	CS_LOGIN = 1,
	SC_LOGIN = 2,

	CS_CHATMESSAGE = 3,
	SC_CHATMESSAGE = 4
};

#pragma pack(push, 1)

struct PACKET_HEADER
{
	short nID;
	short nSize;
};

struct LoginRequest : public PACKET_HEADER
{
	LoginRequest()
	{
		nID = CS_LOGIN;
		nSize = sizeof(LoginRequest);
	}
};

struct LoginResult : public PACKET_HEADER
{
	LoginResult()
	{
		nID = SC_LOGIN;
		nSize = sizeof(LoginResult);
	}
};

struct ChatMessage : public PACKET_HEADER
{
	ChatMessage()
	{
		nID = CS_CHATMESSAGE;
		nSize = sizeof(ChatMessage);
		memset(&szMessage, 0, MAX_MESSAGE_LEN);
	}

	char szMessage[MAX_MESSAGE_LEN];
};

struct NOTICE_ChatMessage : public PACKET_HEADER
{
	NOTICE_ChatMessage()
	{
		nID = SC_CHATMESSAGE;
		nSize = sizeof(NOTICE_ChatMessage);
		memset(&szMessage, 0, MAX_MESSAGE_LEN);
	}

	char szMessage[MAX_MESSAGE_LEN];
};