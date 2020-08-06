#pragma once
#include<afxsock.h>
#include "pch.h"
#include "resource.h"
typedef struct MyMsg
{
	char name[20]="";
	char position[10]="";
	char Style[128]="";
};
class TcpSever:public CAsyncSocket
{
public:
	CListCtrl *mList1=new CListCtrl();
	void UpdataListCtrl(MyMsg* Msg);
	void setListCtrl(CListCtrl* mList);
	TcpSever();
	CString LastError_tostr(int LastError);
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//
};

