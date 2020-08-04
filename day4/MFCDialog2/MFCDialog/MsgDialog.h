#pragma once


// MsgDialog 对话框
#include"RightDialog.h"
//#include"MFCDialogDlg.h"

class CMFCDialogDlg;
class MsgDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MsgDialog)

public:
	MsgDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MsgDialog();
	void setListCtrl(CListCtrl* mList1);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	
	void UpdataList(CListCtrl& mList1);
	RightDialog *RightDlg = new RightDialog();
public:
	CEdit *TEXT4 = new CEdit();
	CEdit *TEXT1=new CEdit();
	CString ComBoxStr = CString("");
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox *ComboBox=new CComboBox();
	CListCtrl *mList1;
};
