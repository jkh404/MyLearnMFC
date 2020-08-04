
// MFCDialogDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCDialog.h"
#include "MFCDialogDlg.h"
#include "afxdialogex.h"
#include<afxdb.h>  //用于建立数据库对象，包括CDatabase类
#include <odbcinst.h>
//#include<odbcinst.h>
#pragma comment(lib,"odbc32.lib")
#pragma comment(lib,"odbccp32.lib")
#pragma comment(lib,"legacy_stdio_definitions.lib")
//#pragma Contents( lib, "odbccp32.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
};

CAboutDlg::CAboutDlg()
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAboutDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CMFCDialogDlg 对话框



CMFCDialogDlg::CMFCDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDialogDlg::Updata()
{
	//this->MsgDlg
	//this->TEXT1.EnableWindow(1);
	CString str1;
	CString str2;
	CString str3;
	CString str4;
	this->MsgDlg->TEXT1->GetWindowTextW(str1);
	this->MsgDlg->TEXT4->GetWindowTextW(str3);
	//str3 = this->MsgDlg->ComBoxStr;
	this->MsgDlg->ComboBox->GetLBText(this->MsgDlg->ComboBox->GetCurSel(), str2);
	str4.Format(TEXT("名字：%s \r\n职务：%s \r\n自我介绍：%s \r\n"), str1, str2, str3);
	int count = mList1.GetItemCount();
	this->mList1.InsertItem(count, str1);
	this->mList1.SetItemText(count, 1,str2);
	this->mList1.SetItemText(count, 2,str3);
	//this->TEXT1.SetWindowTextW(str4);

}

void CMFCDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_LIST2, mList1);
}

BEGIN_MESSAGE_MAP(CMFCDialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDialogDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDialogDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCDialogDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCDialogDlg 消息处理程序

BOOL CMFCDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect mRect;
	mList1.GetWindowRect(&mRect);    //获取控件矩形区域
	int kuan = mRect.Width();
	mList1.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, kuan/3, -1);//添加标题
	mList1.InsertColumn(1, _T("职务"), LVCFMT_CENTER, kuan / 3, -1);//添加标题
	mList1.InsertColumn(2, _T("自我介绍"), LVCFMT_CENTER, kuan / 3, -1);//添加标题

	DWORD dwStyle = mList1.GetExtendedStyle(); //获取当前扩展样式
	dwStyle |= LVS_EX_FULLROWSELECT; //选中某行使整行高亮（report风格时）
	dwStyle |= LVS_EX_GRIDLINES; //网格线（report风格时）
	dwStyle |= LVS_EX_CHECKBOXES; //item前生成checkbox控件
	mList1.SetExtendedStyle(dwStyle); //设置扩展风格


	//MsgDlg->Create(IDD_DIALOG1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDialogDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MsgDlg = new MsgDialog();
	MsgDlg->Create(IDD_DIALOG1);
	MsgDlg->ShowWindow(1);//SW_NORMAL==1
	MsgDlg->setListCtrl(&(this->mList1));
	//MsgDlg->DoModal();
	//MessageBox();
	//MsgDlg->TEXT1->GetWindowTextW()
	//Updata();
}


void CAboutDlg::OnCbnSelchangeCombo1()
{

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCDialogDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Updata();
}




void CMFCDialogDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//导出数据到EXCEL
	CDatabase database;
	//CString sDriver = CString("MICROSOFT EXCEL DRIVER (*.XLS)"); // Excel安装驱动
	CString sDriver= GetExcelDriver(); // Excel安装驱动
	CString sExcelFile, sPath;
	CString sSql;
	//AfxMessageBox(GetExcelDriver());
	//获取主程序所在路径,存在sPath中
	//CString TopIndex;
	int ItemCount = this->mList1.GetItemCount();//获取列表项数量
	//TopIndex.Format(CString("%d"), this->mList1.GetItemCount());
	//AfxMessageBox(TopIndex);
	GetModuleFileName(NULL, sPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	sPath.ReleaseBuffer();
	int nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);
	sExcelFile=sPath + CString("\\test.xls");     // 要建立的Excel文件
	TRY
	{
		// 创建进行存取的字符串
		sSql.Format(CString("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s"),sDriver, sExcelFile, sExcelFile);
	// 创建数据库 (既Excel表格文件)
	if (database.OpenEx(sSql,CDatabase::noOdbcDialog))
	{
		sSql.Format(CString("CREATE TABLE Exceldemo (%s TEXT,%s TEXT,%s TEXT)"),
			CString("名字"),
			CString("职务"),
			CString("自我介绍"));
		database.ExecuteSQL(sSql);
		for (int i = 0; i <=ItemCount-1;i++) {//索引从0开始所以需要ItemCount-1

			// 插入数值
			sSql.Format(CString("INSERT INTO Exceldemo (名字,职务,自我介绍) VALUES ('%s','%s','%s')"),
				CString(mList1.GetItemText(i,0)),
				CString(mList1.GetItemText(i, 1)),
				CString(mList1.GetItemText(i, 2))
			);
			database.ExecuteSQL(sSql);
		}
		// 创建表结构(名字、职务、自我介绍)
		
	}
	// 关闭数据库
	database.Close();
	AfxMessageBox(CString("Excel文件写入成功！")+ sExcelFile);
	}
		CATCH_ALL(e)
	{
		TRACE1("Excel驱动没有安装: %s", sDriver);
	}
	END_CATCH_ALL;
}
CString CMFCDialogDlg::GetExcelDriver()//读取EXCEL文件//检索是否安装有Excel驱动
{
	CString sDriver;
	TCHAR szDrivers[4096];
	memset(szDrivers, 0, sizeof(szDrivers));
	WORD wRet = 0;
	// 获取已安装驱动的名称(函数在odbcinst.h里)
	if (SQLGetInstalledDrivers(szDrivers, _countof(szDrivers), &wRet))
	{
		LPTSTR pszDrv = szDrivers;

		
		
		while (*pszDrv)
		{
			CString str = CString(pszDrv);
			CStringA StrA = static_cast<CStringA>(str);
			char* str2 = StrA.GetBuffer();
			//LPTSTR -> char*

			//MessageBox(pszDrv);
			if (strstr(str2, "Excel") != 0) {
				
				sDriver = CString(str2);
				return sDriver;
			}
			pszDrv += _tcslen(pszDrv) + 1;
		}
	}
}