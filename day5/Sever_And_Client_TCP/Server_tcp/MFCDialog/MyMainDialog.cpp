// MyMainDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCDialog.h"
#include "MyMainDialog.h"
#include "afxdialogex.h"


// MyMainDialog 对话框

IMPLEMENT_DYNAMIC(MyMainDialog, CDialogEx)

MyMainDialog::MyMainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDIALOG_DIALOG, pParent)
{

}

MyMainDialog::~MyMainDialog()
{
}



void MyMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyMainDialog, CDialogEx)
END_MESSAGE_MAP()


// MyMainDialog 消息处理程序
