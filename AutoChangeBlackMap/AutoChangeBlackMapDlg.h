
// AutoChangeBlackMapDlg.h: 头文件
//

#pragma once


// CAutoChangeBlackMapDlg 对话框
class CAutoChangeBlackMapDlg : public CDialogEx
{
// 构造
public:
	CAutoChangeBlackMapDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOCHANGEBLACKMAP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_text;
	CFont m_Font; //用于更改静态文本框字的大小及颜色
	afx_msg void OnBnClickedButton2();
	CString m_pass1;
	afx_msg void OnBnClickedOk();
	static CString CFindFile(const TCHAR *szPath, const TCHAR *szFileName, CStringArray *paStrResult);
	afx_msg void OnBnClickedOk2();
	//UINT ChangeProcessBox(LPVOID pParam);
	//UINT FindFileBotton(LPVOID pParam);
	static CString load1;
	static UINT ChangeProcessBox(LPVOID pParam);
	static UINT FindFileBotton(LPVOID pParam);
	//static CAutoChangeBlackMapDlg *l1;
	//void MemberToStatic();
	CComboBox m_path;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
};
