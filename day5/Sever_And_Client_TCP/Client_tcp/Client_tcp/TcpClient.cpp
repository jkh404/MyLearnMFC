#include "pch.h"
#include "TcpClient.h"

void TcpClient::OnConnect(int nErrorCode)
{
	if (nErrorCode==0) {
		//AfxMessageBox(_T("0"));
	}
	
	CAsyncSocket::OnConnect(nErrorCode);

}
typedef struct book {
	int id = -1;
	char name[128];
}BOOK;
void TcpClient::OnReceive(int nErrorCode)
{
	char buf[2048];
	//char *buf=NULL;
	int len=-1;
	CString str1;
	BOOK book1;
	Receive(&book1,sizeof(book1));
	//Receive(&str1,sizeof(str1));
	str1.Format(_T("id:%d,name:%s"), book1.id,CString(book1.name));
	AfxMessageBox(str1);
}
