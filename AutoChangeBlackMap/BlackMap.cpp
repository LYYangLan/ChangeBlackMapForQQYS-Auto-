// BlackMap.cpp: 实现文件
//

#include "stdafx.h"
#include "AutoChangeBlackMap.h"
#include "BlackMap.h"
#include "afxdialogex.h"
#include "Winbase.h"
// BlackMap 对话框

IMPLEMENT_DYNAMIC(BlackMap, CDialogEx)

BlackMap::BlackMap(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

BlackMap::~BlackMap()
{
}

void BlackMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STA1, m_text1);
	DDX_Control(pDX, IDC_COMBO1, m_MapBox);
}


BEGIN_MESSAGE_MAP(BlackMap, CDialogEx)
	ON_BN_CLICKED(IDOK2, &BlackMap::OnBnClickedOk2)
END_MESSAGE_MAP()


// BlackMap 消息处理程序


BOOL BlackMap::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//初始化黑图菜单栏及提示
	m_Font1.CreatePointFont(95, _T("SimSun"), NULL);
	m_text1.SetFont(&m_Font1, true);
	m_text1.SetWindowTextW(_T("选择黑图文件"));
	m_MapBox.AddString(_T("全黑图"));
	m_MapBox.AddString(_T("半透明黑图"));
	m_MapBox.AddString(_T("还原为原始版本"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void BlackMap::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	int nIndex = m_MapBox.GetCurSel();
	
	CString strCBText;
	
	m_MapBox.GetLBText(nIndex, strCBText);
	
	CString m_pass1;
	//MessageBox(_T("111"));
	m_pass1 = m_pass;
	
	m_pass1.Replace(_T("\\"), _T("\\\\"));
	CString pass = m_pass1 + _T("\\rnr_bg\\back11.pak");
	CString strFileType = _T("pak");
	//MessageBox(_T("222"));
	if (strCBText == _T("全黑图"))
	{
		if (BlackMap::Release(pass, IDR_PAK1, strFileType))
		{
			MessageBox(_T("成功！"));
		}
		else
		{
			MessageBox(_T("失败！请尝试半自动更换！"));
		}
	}

	else if (strCBText == _T("半透明黑图"))
	{
		if (BlackMap::Release(pass , IDR_PAK2, strFileType))
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
		if (BlackMap::Release(pass, IDR_PAK4, strFileType))
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


bool BlackMap::Release(CString strFileName, WORD wResID, CString strFileType)  //释放资源文件
{
	// TODO: 在此处添加实现代码.
	DWORD   dwWrite = 0;

	// 创建文件  
	//MessageBox(_T("111"));
	HANDLE  hFile = CreateFileW(strFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
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
	HRSRC   hrsc = FindResource (NULL, MAKEINTRESOURCE(wResID), strFileType);
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
