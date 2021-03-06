// showTime.cpp: 实现文件
//

#include "stdafx.h"
#include "AutoChangeBlackMap.h"
#include "showTime.h"
#include "afxdialogex.h"


// showTime 对话框

IMPLEMENT_DYNAMIC(showTime, CDialogEx)

showTime::showTime(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

showTime::~showTime()
{
}

void showTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_process);
}


BEGIN_MESSAGE_MAP(showTime, CDialogEx)
	ON_WM_TIMER()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// showTime 消息处理程序


BOOL showTime::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_process.SetRange(0, 26); //初始化进度条范围

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}





void showTime::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	m_process.SetPos(IShowTime1);
	if (IShowTime1 == 26)
	{
		OnOK();
	}
}


void showTime::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 在此处添加消息处理程序代码
	this->KillTimer(1);
	this->SetTimer(1, 20, NULL);
}
