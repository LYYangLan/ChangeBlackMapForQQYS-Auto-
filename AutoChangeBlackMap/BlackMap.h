#pragma once


// BlackMap 对话框

class BlackMap : public CDialogEx
{
	DECLARE_DYNAMIC(BlackMap)

public:
	BlackMap(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BlackMap();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_text1;
	virtual BOOL OnInitDialog();
	CFont m_Font1; //用于更改静态文本框字的大小及颜色
	CComboBox m_MapBox;
	afx_msg void OnBnClickedOk2();
	bool Release(CString strFileName, WORD wResID, CString strFileType);
};
