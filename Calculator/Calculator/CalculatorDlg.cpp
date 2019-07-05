
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "StringProcessor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_CLEARBUTTON, &CCalculatorDlg::OnBnClickedClearbutton)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString operation("1");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	CString operation("9");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CString operation("3");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	if (!content.GetLength()) {
		GetDlgItem(IDC_CLEARBUTTON)->EnableWindow(FALSE);
	}
	else {
		GetDlgItem(IDC_CLEARBUTTON)->EnableWindow(TRUE);
	}	
}

void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString operation("2");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CString operation("4");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	CString operation("5");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	CString operation("6");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	CString operation("7");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	CString operation("8");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	CString operation("0");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	CString operation(" + ");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	CString operation(" - ");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	CString operation(" * ");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	CString operation(" / ");
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	content.Append(operation);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	CString operation(" = ");
	CString content;
	CString value;
	GetDlgItemText(IDC_EDIT2, content);

	std::string STDStr(CW2A(content.GetString()));
	StringProcessor processor(STDStr);
	value.Format(_T("%d"), processor.Process());

	content.Append(operation);
	content.Append(value);
	SetDlgItemText(IDC_EDIT2, content);
}


void CCalculatorDlg::OnBnClickedClearbutton()
{
	// TODO: Add your control notification handler code here
	CString content;
	GetDlgItemText(IDC_EDIT2, content);

	if (isdigit(content.GetAt(content.GetLength() - 1)))
		SetDlgItemText(IDC_EDIT2, content.Left(content.GetLength() - 1));
	else {
		SetDlgItemText(IDC_EDIT2, content.Left(content.GetLength() - 3));
	}
}
