#pragma once


// MyMainDialog 对话框

class MyMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyMainDialog)

public:
	MyMainDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MyMainDialog();
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDIALOG_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
