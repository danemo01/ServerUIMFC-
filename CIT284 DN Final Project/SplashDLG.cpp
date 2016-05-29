// SplashDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "SplashDLG.h"
#include "afxdialogex.h"


// SplashDLG dialog

IMPLEMENT_DYNAMIC(SplashDLG, CDialogEx)

SplashDLG::SplashDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(SplashDLG::IDD, pParent)
{

}

SplashDLG::~SplashDLG()
{
}

void SplashDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SplashDLG, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()

void SplashDLG::ShowSplashScreen(CWnd * pParentWnd)
{
	splashDlg = new SplashDLG;
	if (!splashDlg->Create(SplashDLG::IDD, pParentWnd))
		delete splashDlg;
	else
		splashDlg->ShowWindow(SW_SHOW);
	splashDlg->UpdateWindow();
	splashDlg->SetTimer(1, 2000, NULL);

}

void SplashDLG::HideSplashScreen()
{
	splashDlg->KillTimer(1);
	DestroyWindow();
	AfxGetMainWnd()->UpdateWindow();
	delete splashDlg;
	splashDlg = NULL;
}

BOOL SplashDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CenterWindow();
	splashMap.LoadBitmap(IDB_BITMAPSPLASH);
	SetBackgroundImage(IDB_BITMAPSPLASH);

//	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;
}

BOOL SplashDLG::PreTranslateAppMessage(MSG* pMsg)
{
	if (splashDlg == NULL)
		return FALSE;

	// If you receive a keyboard or mouse message, hide the splash screen.
	if (splashDlg->m_hWnd != NULL && pMsg->message == WM_KEYDOWN ||
		pMsg->message == WM_SYSKEYDOWN ||
		pMsg->message == WM_LBUTTONDOWN ||
		pMsg->message == WM_RBUTTONDOWN ||
		pMsg->message == WM_MBUTTONDOWN ||
		pMsg->message == WM_NCLBUTTONDOWN ||
		pMsg->message == WM_NCRBUTTONDOWN ||
		pMsg->message == WM_NCMBUTTONDOWN)
	{
		splashDlg->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}

void SplashDLG::OnTimer(UINT_PTR nIDEvent)
{
	HideSplashScreen();
}
