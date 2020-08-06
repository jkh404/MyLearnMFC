#pragma once


// RightDialog 对话框

class RightDialog : public CDialogEx
{
	DECLARE_DYNAMIC(RightDialog)

public:
	RightDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RightDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic MsgText;
public:
	afx_msg void OnBnClickedOk();
	int OK = -1;
};
