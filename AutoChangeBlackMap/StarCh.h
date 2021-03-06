#pragma once


// StarCh 对话框

class StarCh : public CDialogEx
{
	DECLARE_DYNAMIC(StarCh)

public:
	StarCh(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StarCh();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_text2;
	CFont m_Font2; //用于更改静态文本框字的大小及颜色
	CComboBox m_MapBox1;
	afx_msg void OnBnClickedOk();
	bool Release(CString strFileName, WORD wResID, CString strFileType);
};
