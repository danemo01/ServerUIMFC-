
// CIT284 DN Final ProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "CIT284 DN Final ProjectDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include "CreateDirectoryDLG.h"
#include "DateTimeDLG.h"
#include "RemoveDirDLG.h"
#include "ChangeDirectoryDLG.h"
#include "AttributeDLG.h"
#include "CopyDialog.h"
#include "RenameDLG.h"
#include "MoveDLG.h"
#include "TypeDLG.h"
#include "EditDLG.h"
#include "PrintDLG.h"
#include "SplashDLG.h"
#include <direct.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SplashDLG* SplashDLG::splashDlg;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCIT284DNFinalProjectDlg dialog



CCIT284DNFinalProjectDlg::CCIT284DNFinalProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCIT284DNFinalProjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCIT284DNFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATICDIR, dirStatic);
	DDX_Control(pDX, IDC_LIST1, ListView);

	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = _T("File Name");
	ListView.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 75;
	lvColumn.pszText = _T("Date Modify");
	ListView.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Time Modify");
	ListView.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 75;
	lvColumn.pszText = _T("Size");
	ListView.InsertColumn(3, &lvColumn);



	char path[_MAX_DIR];
	_getcwd(path, _MAX_DIR);

	directory = new CString(path);
	directory->Append(_T("\\*.*"));

	vecDir = new vector < fileInfo > ;
	menu = new CMenu();
	menu->LoadMenuW(IDR_MENU1);  // Loads the Menu
	this->SetMenu(menu);
	this->setDirectories();
	dirStatic.SetWindowTextW(*directory);
}

BEGIN_MESSAGE_MAP(CCIT284DNFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_GAMES_BATTLEOFFICE, &CCIT284DNFinalProjectDlg::OnGamesBattleoffice)
	ON_COMMAND(ID_GAMES_BRAINIAC2, &CCIT284DNFinalProjectDlg::OnGamesBrainiac2)
	ON_COMMAND(ID_GAMES_HENWAY2, &CCIT284DNFinalProjectDlg::OnGamesHenway2)
	ON_COMMAND(ID_DIRECTORY_MKDIR, &CCIT284DNFinalProjectDlg::OnDirectoryMkdir)
	ON_COMMAND(ID_DIRECTORY_DIR, &CCIT284DNFinalProjectDlg::OnDirectoryDir)
	ON_COMMAND(ID_OTHER_DATE, &CCIT284DNFinalProjectDlg::OnOtherDate)
	ON_COMMAND(ID_OTHER_TIME, &CCIT284DNFinalProjectDlg::OnOtherTime)
	ON_COMMAND(ID_DIRECTORY_RMDIR, &CCIT284DNFinalProjectDlg::OnDirectoryRmdir)
	ON_COMMAND(ID_DIRECTORY_CHDIR, &CCIT284DNFinalProjectDlg::OnDirectoryChdir)
	ON_COMMAND(ID_DIRECTORY_CLS, &CCIT284DNFinalProjectDlg::OnDirectoryCls)
	ON_COMMAND(ID_DIRECTORY_ATTRIB, &CCIT284DNFinalProjectDlg::OnDirectoryAttrib)
	ON_COMMAND(ID_DIRECTORY_COPY, &CCIT284DNFinalProjectDlg::OnDirectoryCopy)
	ON_COMMAND(ID_DIRECTORY_RENAME, &CCIT284DNFinalProjectDlg::OnDirectoryRename)
	ON_COMMAND(ID_DIRECTORY_MOVE, &CCIT284DNFinalProjectDlg::OnDirectoryMove)
	ON_COMMAND(ID_DIRECTORY_TYPE, &CCIT284DNFinalProjectDlg::OnDirectoryType)
	ON_COMMAND(ID_DIRECTORY_EDIT, &CCIT284DNFinalProjectDlg::OnDirectoryEdit)
	ON_COMMAND(ID_OTHER_PRINT, &CCIT284DNFinalProjectDlg::OnOtherPrint)
	ON_COMMAND(ID_DIRECTORY_QUIT, &CCIT284DNFinalProjectDlg::OnDirectoryQuit)
END_MESSAGE_MAP()


// CCIT284DNFinalProjectDlg message handlers

BOOL CCIT284DNFinalProjectDlg::OnInitDialog()
{
	SplashDLG::ShowSplashScreen(NULL);
	CDialogEx::OnInitDialog();


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CCIT284DNFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCIT284DNFinalProjectDlg::OnPaint()
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
HCURSOR CCIT284DNFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCIT284DNFinalProjectDlg::OnGamesBattleoffice()
{
	// TODO: Add your command handler code here
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("BattleOffice.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void CCIT284DNFinalProjectDlg::OnGamesBrainiac2()
{
	// TODO: Add your command handler code here
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("Brainiac 2.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void CCIT284DNFinalProjectDlg::OnGamesHenway2()
{
	// TODO: Add your command handler code here
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;

	sui.cb = sizeof(STARTUPINFO);
	sui.lpReserved = 0;
	sui.lpDesktop = NULL;
	sui.lpTitle = NULL;
	sui.dwX = 0;
	sui.dwY = 0;
	sui.dwXSize = 0;
	sui.dwXCountChars = 0;
	sui.dwYCountChars = 0;
	sui.dwFillAttribute = 0;
	sui.dwFlags = 0;
	sui.wShowWindow = 0;
	sui.cbReserved2 = 0;
	sui.lpReserved2 = 0;

	wchar_t LszCommandLine[512] = _T("Henway 2.exe");
	wchar_t* pCommandLine = LszCommandLine;
	::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		NULL, NULL, &sui, &pi);
}


void CCIT284DNFinalProjectDlg::OnDirectoryMkdir()
{
	CreateDirectoryDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryDir()
{
	// TODO: Add your command handler code here
	ListView.DeleteAllItems();
	vecDir->clear();
	this->setDirectories();
}


void CCIT284DNFinalProjectDlg::OnOtherDate()
{
	UINT * mode = new UINT(2);

	DateTimeDLG dlg(mode);
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnOtherTime()
{
	UINT * mode = new UINT(1);
	DateTimeDLG dlg(mode);
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryRmdir()
{
	RemoveDirDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}

void CCIT284DNFinalProjectDlg::setDirectories()
{
	CFileFind ff;
	fileInfo temp;
	CString tempf;

	BOOL pathExist = ff.FindFile(*directory);

	while (pathExist)
	{
		pathExist = ff.FindNextFileW();

		temp.fileName = ff.GetFileName();
		temp.fileDirectory = ff.GetFilePath();
		CFile::GetStatus(temp.fileDirectory, temp.status);

		vecDir->push_back(temp);
	}

	int nItem;
	for (size_t i = 0; i < vecDir->size(); i++)
	{
		LVITEM lvItem;
		CString byteSize;

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = i;
		lvItem.iSubItem = 0;
		lvItem.pszText =  (LPWSTR)vecDir->at(i).fileName.GetString();

		nItem = ListView.InsertItem(&lvItem);

		ListView.SetItemText(nItem, 1, vecDir->at(i).status.m_mtime.Format(_T("%m/%d/%Y")));
		ListView.SetItemText(nItem, 2, vecDir->at(i).status.m_mtime.Format(_T("%H:%M:%S")));
		byteSize.Format(_T("%.3fKB"), (float)vecDir->at(i).status.m_size / 1024);
		ListView.SetItemText(nItem, 3, byteSize );
	}



}


void CCIT284DNFinalProjectDlg::OnDirectoryChdir()
{
	ChangeDirectoryDLG dlg(directory);
	dlg.DoModal();

	vecDir->clear();
	ListView.DeleteAllItems();

	this->setDirectories();
	dirStatic.SetWindowTextW(*directory);
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryCls()
{
	ListView.DeleteAllItems();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryAttrib()
{
	AttributeDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryCopy()
{
	CopyDialog dlg;
	dlg.DoModal();

	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryRename()
{
	RenameDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryMove()
{
	MoveDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryType()
{
	TypeDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryEdit()
{
	EditDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnOtherPrint()
{
	PrintDLG dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
}


void CCIT284DNFinalProjectDlg::OnDirectoryQuit()
{
	int result = MessageBox(_T("Are you sure\nyou want to quit(Y/N)? "), _T("EXITING!"),
		MB_ICONQUESTION | MB_YESNO);
	if (result == IDYES)
	{
		Beep(1000, 100);
		DestroyWindow();
	}
	else
		Beep(200, 100);
}


