#include "pch.h"
#include "MyMain.h"

MyMFCApp app;//ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyMFCApp::InitInstance()//
{
    //�������� 
    MyFrame* frame = new MyFrame();

    //��ʾ�͸���
    frame->ShowWindow(SW_NORMAL);
    frame->UpdateData();
        
    m_pMainWnd = frame;//����ָ��Ӧ�ó���������ڵ�ָ��//m_pMainWnd��axfwin.h���Ѿ�������
    return TRUE;//����������ʼ��
}
//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
    //��Ϣ��
    ON_WM_LBUTTONDOWN()//����������
    ON_WM_CHAR()//���̼�����
    ON_WM_PAINT()//��ͼ
END_MESSAGE_MAP()
MyFrame::MyFrame()
{
    Create(NULL, TEXT("MyMFCApp1"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{

    CString str;
    str.Format(TEXT("�������\(%d,%d\)"), point.x, point.y);
    MessageBoxEx(this->m_hWnd, str, TEXT("��Ϣ"), MB_OK, NULL);
}

void MyFrame::OnChar(UINT key, UINT nRepCnt, UINT nFlags)
{
    CString str;
    str.Format(TEXT("����%c��,��ֵ%d"), key,key);
    MessageBox(str);
}

void MyFrame::OnPaint()
{
    CPaintDC dc(this);//�豸�����Ķ���,ͨ�׵���ǻ滭����
    //dc.FillSolidRect(10, 10, 100, 100,RGB(150,255,0));
    char* p1 = "ok";
    //char* ת CString
    CString str1=CString(p1);
    //CString תchar*
    CStringA str1A=static_cast<CStringA>(str1);//��ת��CStringA//static_cast<CStringA>(str1)�൱��C�����е�(CStringA)str1
    char* p2 = str1A.GetBuffer();//��ͨ��GetBuffer()ת��char*
    //TEXE()��������Ӧ�����ת��
    dc.TextOutW(10, 50, CString(p2));
}


