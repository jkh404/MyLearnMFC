// MsgDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCDialog.h"
#include "MsgDialog.h"
#include "afxdialogex.h"


// MsgDialog 对话框

IMPLEMENT_DYNAMIC(MsgDialog, CDialogEx)

MsgDialog::MsgDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MsgDialog::~MsgDialog()
{
}

void MsgDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT4, TEXT4);
	DDX_Control(pDX, IDC_EDIT1, TEXT1);
	DDX_Control(pDX, IDC_COMBO1, ComboBox);
}


BEGIN_MESSAGE_MAP(MsgDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MsgDialog::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &MsgDialog::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// MsgDialog 消息处理程序


void MsgDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	RightDlg->DoModal();
	if (RightDlg->OK==1) {
		//MessageBox(TEXT("1"));
		//pParent->Updata();
		CDialogEx::OnOK();
	}

}


void MsgDialog::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	ComboBox.GetLBText(ComboBox.GetCurSel(), this->ComBoxStr);
}
