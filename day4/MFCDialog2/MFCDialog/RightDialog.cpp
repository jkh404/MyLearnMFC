// RightDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCDialog.h"
#include "RightDialog.h"
#include "afxdialogex.h"


// RightDialog 对话框

IMPLEMENT_DYNAMIC(RightDialog, CDialogEx)

RightDialog::RightDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

RightDialog::~RightDialog()
{
}

void RightDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSG, MsgText);
}


BEGIN_MESSAGE_MAP(RightDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &RightDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// RightDialog 消息处理程序


void RightDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OK = 1;
	CDialogEx::OnOK();
}
