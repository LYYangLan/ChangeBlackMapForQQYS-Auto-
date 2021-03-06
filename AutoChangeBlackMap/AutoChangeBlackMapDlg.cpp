
// AutoChangeBlackMapDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "AutoChangeBlackMap.h"
#include "AutoChangeBlackMapDlg.h"
#include "afxdialogex.h"
#include "shlobj.h"
#include "shlwapi.h"
#pragma comment(lib, "shlwapi.lib")
#include "BlackMap.h"
#include "StarCh.h"
#include "showTime.h"
#include "stdlib.h"
//#include "string"

//using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CAutoChangeBlackMapDlg *CAutoChangeBlackMapDlg::l1;
//CString CAutoChangeBlackMapDlg::CFindFile(const TCHAR *szPath, const TCHAR *szFileName, CStringArray *paStrResult);
CString CAutoChangeBlackMapDlg::load1;


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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAutoChangeBlackMapDlg 对话框



CAutoChangeBlackMapDlg::CAutoChangeBlackMapDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTOCHANGEBLACKMAP_DIALOG, pParent)
	, m_pass1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoChangeBlackMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STA, m_text);
	DDX_Text(pDX, IDC_EDIT2, m_pass1);
	DDX_Control(pDX, IDC_COMBO1, m_path);
}

BEGIN_MESSAGE_MAP(CAutoChangeBlackMapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CAutoChangeBlackMapDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CAutoChangeBlackMapDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CAutoChangeBlackMapDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAutoChangeBlackMapDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CAutoChangeBlackMapDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAutoChangeBlackMapDlg 消息处理程序

BOOL CAutoChangeBlackMapDlg::OnInitDialog()
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

	//初始化欢迎界面
	m_Font.CreatePointFont(200, _T("Arial"), NULL);
	m_text.SetFont(&m_Font, true);
	m_text.SetWindowTextW(_T("欢迎使用自动换黑图\n星星换钉子小工具"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAutoChangeBlackMapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoChangeBlackMapDlg::OnPaint()
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
HCURSOR CAutoChangeBlackMapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CAutoChangeBlackMapDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	IShowTime1 = 0;
	MessageBox(_T("请耐心等待一会，中途不要关闭程序，如果您不想等待，请到任务管理器强制关闭。"));
	AfxBeginThread(FindFileBotton, this);
	AfxBeginThread(ChangeProcessBox, this);
	showTime dlg2;
	dlg2.DoModal();
	//CString load2;
	//load2 = load1;
	if (load1 == _T("1"))
	{
		MessageBox(_T("您的电脑没有安装QQ音速！"));
		return;
	}
	else if (load1 == _T("2"))
	{
		GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);  //显示隐藏的按钮
		GetDlgItem(IDC_COMBO1)->ShowWindow(TRUE);   //显示隐藏的列表控件
		int num1 = paStrResult.GetSize();
		for (int i = 0; i < num1; i++)
		{
			m_path.AddString(paStrResult.GetAt(i).Left(paStrResult.GetAt(i).GetLength() - 11));
		}
		MessageBox(_T("您的电脑中安装多个QQ音速，请点击选择路径按钮，确认为哪个QQ音速安装插件！"));
		m_path.ShowDropDown(TRUE);   //弹出组合列表框
		return;
	}
	else
	{
		MessageBox(_T("已获得路径，按确定继续！"));
	}

	//得到打开文件的路径
	int len = load1.GetLength();
	m_pass1 = load1.Left(len - 11);
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(m_pass1);     //在窗口标题上显示路径
	m_pass = m_pass1;
}


void CAutoChangeBlackMapDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (load1 == _T("2"))
	{
		if (m_path.GetCurSel() == CB_ERR)
		{
			MessageBox(_T("您的电脑中安装多个QQ音速，请点击选择路径按钮，确认为哪个QQ音速安装插件！"));
			m_path.ShowDropDown(TRUE);   //弹出组合列表框
			return;
		}
		int NI = m_path.GetCurSel();   //获得选择的列表框中的内容
		m_path.GetLBText(NI, m_pass1);
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(m_pass1);     //在窗口标题上显示路径
		m_pass = m_pass1;
		CString Pan = _T("您选择了安装在“") + m_pass1.Left(1) + _T("”盘中的QQ音速，请继续");
		MessageBox(Pan);
	}

	int len = m_pass1.GetLength();
	if (len == 0)
	{
		MessageBox(_T("请搜索游戏安装路径！"));
		return;
	}
	BlackMap dlg;
	dlg.DoModal();
}


CString CAutoChangeBlackMapDlg::CFindFile(const TCHAR *szPath, const TCHAR *szFileName, CStringArray *paStrResult)
//递归搜索全盘文件
//第一个参数为要搜索的路径，比如"c:\\dir\\"或"c:\\dir"则在包括此目录的所有子目录下搜索
//第二个参数为要搜索的文件,比如"qq.txt"，需要提供文件后缀，大小写不敏感  
//第三个参数用于保存搜索到的文件的全路径，请构造一个CStringArray对象并传入地址
{
	// TODO: 在此处添加实现代码.
	ASSERT(paStrResult != NULL);

	CString StrPath(szPath);

	CString StrFileName(szFileName);

	//检查路径字符串的最后一个字符是不是'\',不是则加上  

	if (StrPath[StrPath.GetLength() - 1] != _T('\\'))

		StrPath += _T('\\');


	CString StrFindPath = StrPath + _T("*.*");

	//开始查找  

	CFileFind finder;
	BOOL bWorking = finder.FindFile(StrFindPath);

	while (bWorking)

	{

		bWorking = finder.FindNextFile();

		//如果找到的是文件夹，递归进去  

		if (finder.IsDirectory() && !finder.IsDots())

		{

			CFindFile(StrPath + finder.GetFileName(), StrFileName, paStrResult);

		}

		//如果找到了文件，将绝对路径添加进字符串数组,大小写不敏感  

		if (finder.GetFileName().CompareNoCase(StrFileName) == 0)

		{

			paStrResult->Add(finder.GetFilePath());

		}
	}

	
	//将字符串数组中的内容存储到字符串中
	int iden = paStrResult->GetSize();
	CString load;
	
	if (iden == 0)
	{
		load = _T("1");
	}
	else if (iden > 1)
	{
		load = _T("2");
	}
	else
	{
		for (int i = 0; i < iden; i++)
		{
			load = load + paStrResult->GetAt(i);
		}
	}
	return load;
}


void CAutoChangeBlackMapDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (load1 == _T("2"))
	{
		if (m_path.GetCurSel() == CB_ERR)
		{
			MessageBox(_T("您的电脑中安装多个QQ音速，请点击选择路径按钮，确认为哪个QQ音速安装插件！"));
			m_path.ShowDropDown(TRUE);   //弹出组合列表框
			return;
		}
		int NI = m_path.GetCurSel();   //获得选择的列表框中的内容
		m_path.GetLBText(NI, m_pass1);
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(m_pass1);     //在窗口标题上显示路径
		m_pass = m_pass1;
		CString Pan = _T("您选择了安装在“") + m_pass1.Left(1) + _T("”盘中的QQ音速，请继续");
		MessageBox(Pan);
	}
	int len = m_pass1.GetLength();
	if (len == 0)
	{
		MessageBox(_T("请搜索游戏安装路径！"));
		return;
	}
	StarCh dlg1;
	dlg1.DoModal();
}

/*
void CAutoChangeBlackMapDlg::MemberToStatic()
{
	// TODO: 在此处添加实现代码.
	l1 = this;
}
*/

UINT CAutoChangeBlackMapDlg::ChangeProcessBox(LPVOID pParam) //控制进度条变化
{
	// TODO: 在此处添加实现代码.
	while (IShowTime1 != 26)
	{
		for (int i = 0; i < 1000; i++)
		{

			//Sleep(50);
		}
	}
	return 0;
}


UINT CAutoChangeBlackMapDlg::FindFileBotton(LPVOID pParam)   //按下搜索路径按钮后执行该函数
{
	// TODO: 在此处添加实现代码.
	TCHAR *szPath;
	TCHAR *szFileName = _T("QQ音速卸载.exe");
	//CStringArray paStrResult;

	for (char x = 'Z'; x >= 'A'; x--) //全盘搜索
	{
		CString x1(x);
		CString StrPath1 = x1 + _T(":\\");
		if (PathIsDirectory((LPCTSTR)StrPath1) == FALSE)
		{
			x=x;
		}
		else
		{
			szPath = StrPath1.GetBuffer(StrPath1.GetLength());
			StrPath1.ReleaseBuffer();
			load1 = CAutoChangeBlackMapDlg::CFindFile(szPath, szFileName, &paStrResult);
		}
		IShowTime1++;
	}
	return 0;
}




void CAutoChangeBlackMapDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_path.ShowDropDown(TRUE);   //弹出组合列表框
}


void CAutoChangeBlackMapDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	paStrResult.RemoveAll();   //释放字符串数组
}
