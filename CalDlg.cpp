// CalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cal.h"
#include "CalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

CCalDlg::CCalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalDlg)
	m_X = 0.0;
	m_Y = 0.0;
	m_R = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalDlg)
	DDX_Text(pDX, IDC_X, m_X);
	DDX_Text(pDX, IDC_Y, m_Y);
	DDX_Text(pDX, IDC_Y2, m_R);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalDlg, CDialog)
	//{{AFX_MSG_MAP(CCalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalDlg message handlers

BOOL CCalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalDlg::OnOK() 
{
	// TODO: Add extra validation here
	//CCalDlg Dlg;
	x=m_X;
	y=m_Y;
	
	if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO1),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮1
	{
		result=x+y;
		m_R=result;
		//CString string;
		//string.Format("%d%s",result, result); //将变量组装到字符串中

       //MessageBox(string,NULL,MB_ICONINFORMATION);
		//AfxMessageBox("24");
	//	MessageBox(_T(result),NULL,MB_ICONINFORMATION);//弹出提示
	}
	else if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO2),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮2
	{
		MessageBox(_T("选择了单选按钮2!"),NULL,MB_ICONINFORMATION);//弹出提示
	}

	CDialog::OnOK();
}

void CCalDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	x=m_X;
	y=m_Y;

	if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO1),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮1
	{
		//MessageBox(_T("选择了单选按钮1!"),NULL,MB_ICONINFORMATION);//弹出提示
			result=x+y;
			//m_R=result;
			
			UpdateData(TRUE);//读取数据
            m_R = x+y;
            UpdateData(FALSE);//显示数据在编辑框中
			//AfxMessageBox(result);
	}
	else if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO2),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮2
	{
		result=x-y;
			//m_R=result;
			
			UpdateData(TRUE);//读取数据
            m_R = x-y;
            UpdateData(FALSE);//显示数据在编辑框中
	}
	else if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO3),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮2
	{
		result=x*y;
			//m_R=result;
			
			UpdateData(TRUE);//读取数据
            m_R = x*y;
            UpdateData(FALSE);//显示数据在编辑框中
	}
	else if(::SendMessage(::GetDlgItem(m_hWnd,IDC_RADIO4),BM_GETCHECK,NULL,NULL) == BST_CHECKED)//如果选择了单选按钮2
	{
		result=x/y;
			//m_R=result;
			
			UpdateData(TRUE);//读取数据
            m_R = (double) x/(double) y;
            UpdateData(FALSE);//显示数据在编辑框中
	}



}
