
// MFCDialogDlg.h: 头文件
//

#pragma once
#include "resource.h"
#include "MsgDialog.h"


class CMFCDialogDlg : public CDialogEx
{
// 构造
public:
	CMFCDialogDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void Updata();
	CString GetExcelDriver();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持



// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 信息汇总

	afx_msg void OnBnClickedButton1();
	MsgDialog *MsgDlg = new MsgDialog();
private:
	
public:
	afx_msg void OnBnClickedButton2();

private:
	
	CListCtrl mList1;
public:
	afx_msg void OnBnClickedButton4();
};
