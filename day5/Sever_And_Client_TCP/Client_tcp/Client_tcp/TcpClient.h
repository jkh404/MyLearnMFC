#pragma once
#include <afxsock.h>
class TcpClient :
    public CAsyncSocket
{
public:
    virtual void OnConnect(int nErrorCode);
    virtual void OnReceive(int nErrorCode);

};

