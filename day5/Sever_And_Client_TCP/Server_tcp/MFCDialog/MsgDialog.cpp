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
	DDX_Control(pDX, IDC_EDIT4, *TEXT4);
	DDX_Control(pDX, IDC_EDIT1, *TEXT1);
	DDX_Control(pDX, IDC_COMBO1,*ComboBox);
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
		this->UpdataList(*mList1);
		CDialogEx::OnOK();
	}

}

void MsgDialog::setListCtrl(CListCtrl *mList1)
{
	this->mList1 = mList1;
}

void MsgDialog::UpdataList(CListCtrl& mList1)
{
	CString str1;
	CString str2;
	CString str3;
	CString str4;
	this->TEXT1->GetWindowTextW(str1);
	this->TEXT4->GetWindowTextW(str3);
	//str3 = this->MsgDlg->ComBoxStr;
	this->ComboBox->GetLBText(this->ComboBox->GetCurSel(), str2);
	str4.Format(TEXT("名字：%s \r\n职务：%s \r\n自我介绍：%s \r\n"), str1, str2, str3);
	int count = mList1.GetItemCount();
	mList1.InsertItem(count, str1);
	mList1.SetItemText(count, 1, str2);
	mList1.SetItemText(count, 2, str3);
}


void MsgDialog::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	ComboBox->GetLBText(ComboBox->GetCurSel(), this->ComBoxStr);
}
