#include "pch.h"
#include "TcpSever.h"

void TcpSever::UpdataListCtrl(MyMsg* Msg)
{
	int count = -1;
	/*转换格数*/
	CString name;
	CString position;
	CString Style;
	name.Format(_T("%s"), Msg->name);
	position.Format(_T("%s"), Msg->position);
	Style.Format(_T("%s"), Msg->Style);
	//把数据写到List 控件
	count = mList1->GetItemCount();
	mList1->InsertItem(count, name);
	mList1->SetItemText(count, 1, position);
	mList1->SetItemText(count, 2, Style);
	
}

void TcpSever::setListCtrl(CListCtrl* mList)
{
	this->mList1 = mList;
}

TcpSever::TcpSever()
{

}

/*OnAccept(int nErrorCode)由框架调用，通知监听套接字现在可以调用Accept成员函数
来接收悬挂的（pending）连接请求。
*/
void TcpSever::OnAccept(int nErrorCode)
{
	//newTcp = new TcpSever();
	TcpSever* newTcp = new TcpSever();
	if (this->Accept(*newTcp)) {
		newTcp->setListCtrl(this->mList1);//将this->mList1传给newTcp
		CString str;
		UINT port;
		newTcp->GetPeerName(str, port);//获得与套接字连接的对等套接字的地址 
		newTcp->GetSockName(str, port);//获得套接字的本地名 
	}
	CAsyncSocket::OnAccept(nErrorCode);

}

/*本函数由框架调用，通知套接字缓冲中有数据，
可以调用Receive成员函数取出。*/
void TcpSever::OnReceive(int nErrorCode)
{

	MyMsg Msg = {"","",""};
	this->Receive(&Msg,sizeof(Msg));
	UpdataListCtrl(&Msg);
	//this->Close();
}

CString TcpSever::LastError_tostr(int LastError)
{
	char* Error=NULL;
	switch (LastError)
	{
	case WSANOTINITIALISED:
		Error="WSANOTINITIALISED";
		break;
	case WSAENETDOWN:
		Error = "WSAENETDOWN";
		break;
	case WSAEAFNOSUPPORT:
		Error = "WSAEAFNOSUPPORT";
		break;
	case WSAEINPROGRESS:
		Error = "WSAEINPROGRESS";
		break;
	case WSAEMFILE:
		Error = "WSAEMFILE";
		break;
	case WSAENOBUFS:
		Error = "WSAENOBUFS";
		break;
	case WSAEPROTONOSUPPORT:
		Error = "WSAEPROTONOSUPPORT";
		break;
	case WSAEPROTOTYPE:
		Error = "WSAEPROTOTYPE";
		break;
	case WSAESOCKTNOSUPPORT:
		Error = "WSAESOCKTNOSUPPORT";
		break;
	default:
		break;
	}
	return CString(Error);
}


