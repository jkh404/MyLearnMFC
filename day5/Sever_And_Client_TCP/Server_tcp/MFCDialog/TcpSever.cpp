#include "pch.h"
#include "TcpSever.h"

void TcpSever::UpdataListCtrl(MyMsg* Msg)
{
	int count = -1;
	/*ת������*/
	CString name;
	CString position;
	CString Style;
	name.Format(_T("%s"), Msg->name);
	position.Format(_T("%s"), Msg->position);
	Style.Format(_T("%s"), Msg->Style);
	//������д��List �ؼ�
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

/*OnAccept(int nErrorCode)�ɿ�ܵ��ã�֪ͨ�����׽������ڿ��Ե���Accept��Ա����
���������ҵģ�pending����������
*/
void TcpSever::OnAccept(int nErrorCode)
{
	//newTcp = new TcpSever();
	TcpSever* newTcp = new TcpSever();
	if (this->Accept(*newTcp)) {
		newTcp->setListCtrl(this->mList1);//��this->mList1����newTcp
		CString str;
		UINT port;
		newTcp->GetPeerName(str, port);//������׽������ӵĶԵ��׽��ֵĵ�ַ 
		newTcp->GetSockName(str, port);//����׽��ֵı����� 
	}
	CAsyncSocket::OnAccept(nErrorCode);

}

/*�������ɿ�ܵ��ã�֪ͨ�׽��ֻ����������ݣ�
���Ե���Receive��Ա����ȡ����*/
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


