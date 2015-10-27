//
//  Lsocket.cpp
//  player
//
//  Created by 望成 廖 on 14-7-30.
//  Copyright (c) 2014年 quick.cocoachina.com. All rights reserved.
//

#include "Lsocket.h"
//#include "CCLuaEngine.h"
Lsocket* Lsocket::__m_Instance = NULL;
Lsocket* Lsocket::GetInstance()
{
    if (__m_Instance == NULL)
    {
        __m_Instance = new Lsocket();
    }
    return __m_Instance;
}

SOCKET Lsocket::GetSocket()
{
    return __m_Socket;
}

Lsocket::Lsocket()
{
#ifdef WIN32
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);//win sock start up
	if (ret != 0) {
		return false;
	}
#endif
    __m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    __m_ConnectThread = NULL;
    __m_RecvThread = NULL;
    
}

void* Lsocket::ConnectProc(void* args)
{
    Lsocket* piLsocket = (Lsocket*)args;
    timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    fd_set writeset, exceptset;
    FD_ZERO(&writeset);
    FD_ZERO(&exceptset);
    FD_SET(piLsocket->GetSocket(), &writeset);
    FD_SET(piLsocket->GetSocket(), &exceptset);
//    piLsocket->SendMessageToLua("connect", "start",strlen("start"));
    int ret = select(FD_SETSIZE, NULL, &writeset, &exceptset, &timeout);
    if (ret == 0 || ret < 0) {
//        piLsocket->SendMessageToLua("connect", "failed",strlen("failed"));
        piLsocket->CloseSocket();
        return NULL;
    }
    else	// ret > 0
    {
        ret = FD_ISSET(piLsocket->GetSocket(), &exceptset);
        if (ret)		// or (!FD_ISSET(m_sockClient, &writeset)
        {
//            piLsocket->SendMessageToLua("connect", "failed",strlen("failed"));
            piLsocket->CloseSocket();
            return NULL;
        }
    }
//    piLsocket->SendMessageToLua("connect", "success",strlen("success"));
    piLsocket->Recv();
    return NULL;
}

bool Lsocket::Connect(const char* pszServerIP, int nServerPort, int nBlockSec, bool bKeepAlive /*= FALSE*/)
{
    
   
    
	if (pszServerIP == 0 || strlen(pszServerIP) > 15) {
		return false;
	}
    

    
	if (__m_Socket == INVALID_SOCKET) {
		__m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		return false;
	}
    
	if (bKeepAlive)
	{
		int		optval = 1;
		if (setsockopt(__m_Socket, SOL_SOCKET, SO_KEEPALIVE, (char *)&optval, sizeof(optval)))
		{
			CloseSocket();
			return false;
		}
	}
    
#ifdef WIN32
	DWORD nMode = 1;
	int nRes = ioctlsocket(__m_Socket, FIONBIO, &nMode);
	if (nRes == SOCKET_ERROR) {
		closeSocket();
		return false;
	}
#else
	fcntl(__m_Socket, F_SETFL, O_NONBLOCK);
#endif
    
	unsigned long serveraddr = inet_addr(pszServerIP);
	if (serveraddr == INADDR_NONE)
	{
		CloseSocket();
		return false;
	}
    
    
    else	// WSAWOLDBLOCK
    {
        
        
        
        sockaddr_in	addr_in;
        memset((void *)&addr_in, 0, sizeof(addr_in));
        addr_in.sin_family = AF_INET;
        addr_in.sin_port = htons(nServerPort);
        addr_in.sin_addr.s_addr = inet_addr(pszServerIP);
        
        int res = connect(__m_Socket, (sockaddr *)&addr_in, sizeof(addr_in));
        if (res == SOCKET_ERROR)
        {
            if (HasError()) {
                CloseSocket();
                return false;
            }
        }
        
        __m_ConnectThread = new pthread_t();
        pthread_create(__m_ConnectThread, NULL, ConnectProc, this);
	
    }

 
m_nInbufLen = 0;
m_nInbufStart = 0;
m_nOutbufLen = 0;

struct linger so_linger;
so_linger.l_onoff = 1;
so_linger.l_linger = 500;
setsockopt(__m_Socket, SOL_SOCKET, SO_LINGER, (const char*)&so_linger, sizeof(so_linger));

return true;
}

bool Lsocket::Send(const char* content, int nSize)
{
    if (__m_Socket) {
        if (send(__m_Socket, content, nSize, 0) == SOCKET_ERROR)
        {
           
//            SendMessageToLua("send", "failed",strlen("failed"));
            return false;
        }
    }
    else
    {
//        SendMessageToLua("send", "failed",strlen("failed"));
        return false;
    }

//    SendMessageToLua("send", "success",strlen("success"));
    return true;
}

void* Lsocket::RecvProc(void *args)
{
    Lsocket* piLsocket = (Lsocket*)args;
    SOCKET clinetSocket = piLsocket->GetSocket();
    char buff[1024] = "";
    int nRecvSize = 0;
    while (true)
    {
        nRecvSize = (int)recv(clinetSocket, buff, 1024, 0);
        if(!piLsocket->Check())
            break;
        if (nRecvSize > 0 ) {
            CCLOG("nRecvSize %d",nRecvSize);
            char* content = (char*)malloc(nRecvSize);
            memccpy(content, buff, 1, nRecvSize);
//            piLsocket->SendMessageToLua("message", content,nRecvSize);
        }
    }
//    piLsocket->SendMessageToLua("recv", "failed",strlen("failed"));
    piLsocket->CloseSocket();
    return NULL;
}

//void Lsocket::SendMessageToLua(const char *type,const char *content,int contentSize)
//{
//    //cocos2d::CCLuaValueDict dict;
//
//    cocos2d::CCLuaStack *stack = cocos2d::CCLuaEngine::defaultEngine()->getLuaStack();
//    stack->clean();
//    //stack->pushCCLuaValueDict(dict);
//    stack->pushString(type,(int)strlen(type));
//    stack->pushString(content,contentSize);
//    stack->executeFunctionByHandler(__m_LuaFuncHandle, 2);
//}

bool Lsocket::Recv()
{
    __m_RecvThread = new pthread_t();
    pthread_create(__m_RecvThread, NULL, RecvProc, this);
    return true;
}

Lsocket::~Lsocket()
{
    
}


bool Lsocket::Check()
{
    
    
	char buf[1];
	int	ret = (int)recv(__m_Socket, buf, 1, MSG_PEEK);
	if (ret == 0) {
		CloseSocket();
		return false;
	}
	else if (ret < 0) {
		if (HasError()) {
			CloseSocket();
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
    
	return true;
}



//void Lsocket::SetCallFunc(int handle)
//{
//    this->__m_LuaFuncHandle = handle;
//}

bool Lsocket::HasError()
{
#ifdef WIN32
	int err = WSAGetLastError();
	if (err != WSAEWOULDBLOCK) {
#else
        int err = errno;
        if (err != EINPROGRESS && err != EAGAIN) {
#endif
            return true;
        }
        
        return false;
}
    

    
void Lsocket::CloseSocket()
{
//    struct linger so_linger;
//	so_linger.l_onoff = 1;
//	so_linger.l_linger = 500;
//	setsockopt(__m_Socket, SOL_SOCKET, SO_LINGER, (const char*)&so_linger, sizeof(so_linger));
    
	

#ifdef WIN32
    closesocket(__m_Socket);
    WSACleanup();
#else
    close(__m_Socket);
#endif
    
    __m_Socket = INVALID_SOCKET;
//    SendMessageToLua("socket", "closed",strlen("closed"));
}


void Lsocket::Bind(char* ip, int port)
{
        
}

void Lsocket::Listen(int nMaxConnect)
{
        
}
    
void Lsocket::Accept()
{
        
}
    
    
    



