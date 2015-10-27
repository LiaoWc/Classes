//
//  Lsocket.h
//  player
//
//  Created by 望成 廖 on 14-7-30.
//  Copyright (c) 2014年 quick.cocoachina.com. All rights reserved.
//

#ifndef __player__Lsocket__
#define __player__Lsocket__

#include <iostream>
#include "cocos2d.h"

#ifdef WIN32
#include <windows.h>
#include <WinSock.h>
#else
#include "string.h"
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif /* defined(WIN32) */
//#include "CCLuaValue.h"
#include <pthread.h>

#define SOCKET int
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1

#endif /* defined(__player__Lsocket_ccp__) */

class Lsocket
{
public:
    
    ~Lsocket();
//  服务器端
    void Bind(char* ip, int port);
    void Accept();
    void Listen(int nMaxConnect);
//  客户端
    static void* ConnectProc(void*);
    static void* RecvProc(void*);
    
    static Lsocket* GetInstance();
    bool Connect(const char* pszServerIP, int nServerPort, int nBlockSec = 10, bool bKeepAlive = false);
    bool Send(const char* content, int nSize);
    
//    void SetCallFunc(int handle);
//    void SendMessageToLua(const char* type,const char* content,int contentSize);
    bool Recv();
    
    bool HasError();
    void CloseSocket();
    SOCKET GetSocket();
    bool Check();
    
private:
    
    int m_nInbufLen;
    int m_nInbufStart;
    int m_nOutbufLen;
    SOCKET __m_Socket;
    static Lsocket* __m_Instance;
    Lsocket();
//    int __m_LuaFuncHandle;
    pthread_t *__m_ConnectThread;
    pthread_t *__m_RecvThread;
};