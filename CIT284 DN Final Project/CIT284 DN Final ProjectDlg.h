
// CIT284 DN Final ProjectDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <vector>
#include "afxcmn.h"
using std::vector;

struct fileInfo
{
	CFileStatus status;
	CString fileName;
	CString fileDirectory;
};


// CCIT284DNFinalProjectDlg dialog
class CCIT284DNFinalProjectDlg : public CDialogEx
{
// Construction
public:
	CCIT284DNFinalProjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CIT284DNFINALPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CMenu * menu;
	vector<fileInfo> * vecDir;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGamesBattleoffice();
	afx_msg void OnGamesBrainiac2();
	afx_msg void OnGamesHenway2();
	afx_msg void OnDirectoryMkdir();
	afx_msg void OnDirectoryDir();
	afx_msg void OnOtherDate();
	afx_msg void OnOtherTime();
	afx_msg void OnDirectoryRmdir();
	afx_msg void OnDirectoryChdir();
	afx_msg void OnDirectoryCls();
	afx_msg void OnDirectoryAttrib();
	afx_msg void OnDirectoryCopy();
	afx_msg void OnDirectoryRename();
	afx_msg void OnDirectoryMove();
	afx_msg void OnDirectoryType();
	afx_msg void OnDirectoryEdit();
	afx_msg void OnOtherPrint();
	afx_msg void OnDirectoryQuit();

	void setDirectories();

	CString * directory;
	CStatic dirStatic;
	CListCtrl ListView;
};
