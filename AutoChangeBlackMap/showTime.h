#pragma once


// showTime 对话框

class showTime : public CDialogEx
{
	DECLARE_DYNAMIC(showTime)

public:
	showTime(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~showTime();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CProgressCtrl m_process;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
