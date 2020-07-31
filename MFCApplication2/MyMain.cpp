#include "pch.h"
#include "MyMain.h"

MyMFCApp app;//全局应用程序对象，有且仅有一个

BOOL MyMFCApp::InitInstance()//
{
    //创建窗口 
    MyFrame* frame = new MyFrame();

    //显示和更新
    frame->ShowWindow(SW_NORMAL);
    frame->UpdateData();
        
    m_pMainWnd = frame;//保存指向应用程序的主窗口的指针//m_pMainWnd在axfwin.h中已经声明；
    return TRUE;//返回正常初始化
}
//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
    //消息宏
    ON_WM_LBUTTONDOWN()//鼠标左键按下
    ON_WM_CHAR()//键盘键按下
    ON_WM_PAINT()//绘图
END_MESSAGE_MAP()
MyFrame::MyFrame()
{
    Create(NULL, TEXT("MyMFCApp1"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{

    CString str;
    str.Format(TEXT("点击坐标\(%d,%d\)"), point.x, point.y);
    MessageBoxEx(this->m_hWnd, str, TEXT("消息"), MB_OK, NULL);
}

void MyFrame::OnChar(UINT key, UINT nRepCnt, UINT nFlags)
{
    CString str;
    str.Format(TEXT("按下%c键,键值%d"), key,key);
    MessageBox(str);
}

void MyFrame::OnPaint()
{
    CPaintDC dc(this);//设备上下文对象,通俗点就是绘画对象
    //dc.FillSolidRect(10, 10, 100, 100,RGB(150,255,0));
    char* p1 = "ok";
    //char* 转 CString
    CString str1=CString(p1);
    //CString 转char*
    CStringA str1A=static_cast<CStringA>(str1);//先转成CStringA//static_cast<CStringA>(str1)相当于C语言中的(CStringA)str1
    char* p2 = str1A.GetBuffer();//再通过GetBuffer()转成char*
    //TEXE()做了自适应编码的转换
    dc.TextOutW(10, 50, CString(p2));
}


