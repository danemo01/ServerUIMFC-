#pragma once

#include "resource.h"
#include "afxwin.h"

// ChangeDirectoryDLG dialog

class ChangeDirectoryDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeDirectoryDLG)

public:
	ChangeDirectoryDLG(CString * directory, CWnd* pParent = NULL);   // standard constructor
	virtual ~ChangeDirectoryDLG();

// Dialog Data
	enum { IDD = IDD_CHDIRDIALOG };

protected:
	CString * directory;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic CHStatic;
	CEdit CHEdit;
	afx_msg void OnBnClickedOk();
};
