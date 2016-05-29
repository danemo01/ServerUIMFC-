#pragma once
#include "afxwin.h"
#include "resource.h"

// SplashDLG dialog

class SplashDLG : public CDialogEx
{
	DECLARE_DYNAMIC(SplashDLG)

public:
	SplashDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~SplashDLG();

// Dialog Data
	enum { IDD = IDD_SPLASH };


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	static SplashDLG * splashDlg;
	static void ShowSplashScreen(CWnd*);
	void HideSplashScreen();
	static BOOL PreTranslateAppMessage(MSG*);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	CBitmap splashMap;
};
