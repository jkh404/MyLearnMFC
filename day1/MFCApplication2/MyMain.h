
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
	DECLARE_MESSAGE_MAP()//�����꣬�ṩ��Ϣӳ�����
	//��Ϣӳ�� ��Ϣ������ԭ��
	afx_msg void OnLButtonDown(UINT, CPoint);//����������
	afx_msg void OnChar(UINT, UINT, UINT);//���̰���
	afx_msg void OnPaint();//��ͼ
private:

};



