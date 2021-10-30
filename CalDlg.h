// CalDlg.h : header file
//

#if !defined(AFX_CALDLG_H__4EA716F4_3B63_4F4A_946C_33BAAD10EFC8__INCLUDED_)
#define AFX_CALDLG_H__4EA716F4_3B63_4F4A_946C_33BAAD10EFC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

class CCalDlg : public CDialog
{
// Construction
public:
	CCalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalDlg)
	enum { IDD = IDD_CAL_DIALOG };
	double	m_X;
	double	m_Y;
	double	m_R;
	//}}AFX_DATA
    double x;
	double y;
	double result;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALDLG_H__4EA716F4_3B63_4F4A_946C_33BAAD10EFC8__INCLUDED_)
