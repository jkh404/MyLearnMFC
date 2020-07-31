
#include"pch.h"
#include<afxwin.h>
class MyMFCApp:public CWinApp
{
public:
	virtual BOOL InitInstance();

private:

};
class MyFrame:public CFrameWnd
{
public:
	MyFrame();
	DECLARE_MESSAGE_MAP()//声明宏，提供消息映射机制
	//消息映射 消息处理函数原型
	afx_msg void OnLButtonDown(UINT, CPoint);//鼠标左键按下
	afx_msg void OnChar(UINT, UINT, UINT);//键盘按下
	afx_msg void OnPaint();//绘图
private:

};



