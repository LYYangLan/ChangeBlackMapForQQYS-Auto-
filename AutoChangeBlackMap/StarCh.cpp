// StarCh.cpp: 实现文件
//

#include "stdafx.h"
#include "AutoChangeBlackMap.h"
#include "StarCh.h"
#include "afxdialogex.h"


// StarCh 对话框

IMPLEMENT_DYNAMIC(StarCh, CDialogEx)

StarCh::StarCh(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

StarCh::~StarCh()
{
}

void StarCh::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STA3, m_text2);
	DDX_Control(pDX, IDC_COMBO1, m_MapBox1);
}


BEGIN_MESSAGE_MAP(StarCh, CDialogEx)
	ON_BN_CLICKED(IDOK, &StarCh::OnBnClickedOk)
END_MESSAGE_MAP()


// StarCh 消息处理程序


BOOL StarCh::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//初始化黑图菜单栏及提示
	m_Font2.CreatePointFont(95, _T("SimSun"), NULL);
	m_text2.SetFont(&m_Font2, true);
	m_text2.SetWindowTextW(_T("选择钉子文件"));
	m_MapBox1.AddString(_T("星星换钉子"));
	m_MapBox1.AddString(_T("钉子换星星"));
	m_MapBox1.AddString(_T("玩伴红心改原始"));
	m_MapBox1.AddString(_T("还原为原始版本"));
	//m_MapBox1.AddString(_T("半透明黑图"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void StarCh::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	int nIndex = m_MapBox1.GetCurSel();

	CString strCBText;

	m_MapBox1.GetLBText(nIndex, strCBText);

	CString m_pass1;
	//MessageBox(_T("111"));
	m_pass1 = m_pass;

	m_pass1.Replace(_T("\\"), _T("\\\\"));
	CString pass = m_pass1 + _T("\\rnr_bg\\object.pak");
	CString strFileType = _T("pak");
	//MessageBox(_T("222"));
	if (strCBText == _T("星星换钉子"))
	{
		if (StarCh::Release(pass, IDR_PAK3, strFileType))
		{
			MessageBox(_T("成功！"));
		}
		else
		{
			MessageBox(_T("失败！请尝试半自动更换！"));
		}
	}

	else if (strCBText == _T("钉子换星星"))
	{
		MessageBox(_T("此项与星星换钉子不能同时共存，如果您之前使用过星星换钉子，请先选择还原，再选择此项！"));
		pass = m_pass1 + _T("\\rnr_bg\\钉子变星back11.pak");
		if (StarCh::Release(pass, IDR_PAK6, strFileType))
		{
			MessageBox(_T("成功！"));
		}
		else
		{
			MessageBox(_T("失败！请尝试半自动更换！"));
		}
	}

	else if (strCBText == _T("玩伴红心改原始"))
	{
		pass = m_pass1 + _T("\\rnr_bg\\玩伴红心改原始.pak");
		if (StarCh::Release(pass, IDR_PAK7, strFileType))
		{
			MessageBox(_T("成功！"));
		}
		else
		{
			MessageBox(_T("失败！请尝试半自动更换！"));
		}
	}

	else if (strCBText == _T("还原为原始版本"))
	{
		if (StarCh::Release(pass, IDR_PAK5, strFileType))
		{
			MessageBox(_T("成功！"));
		}
		else
		{
			MessageBox(_T("失败！请尝试半自动更换！"));
		}
	}

	else
	{
		MessageBox(_T("请选择黑图文件！"));
		return;
	}
}


bool StarCh::Release(CString strFileName, WORD wResID, CString strFileType)  //释放资源文件
{
	// TODO: 在此处添加实现代码.
	DWORD   dwWrite = 0;

	// 创建文件  
	//MessageBox(_T("111"));
	HANDLE  hFile = CreateFileW(strFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//MessageBox(_T("222")); , GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
	//GetLastError();
	//TCHAR str[20];
	//wsprintf(str, L"%d", GetLastError());
	//MessageBox(str);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	//MessageBox(_T("333"));
	// 查找资源文件中、加载资源到内存、得到资源大小   
	HRSRC   hrsc = FindResource(NULL, MAKEINTRESOURCE(wResID), strFileType);
	HGLOBAL hG = LoadResource(NULL, hrsc);
	DWORD   dwSize = SizeofResource(NULL, hrsc);
	if (!(hrsc&&hG&&dwSize))
	{
		return FALSE;
	}
	// 写入文件  
	//MessageBox(_T("444"));
	WriteFile(hFile, hG, dwSize, &dwWrite, NULL);
	CloseHandle(hFile);
	return TRUE;
}
