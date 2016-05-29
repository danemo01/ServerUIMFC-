#pragma once
#include "resource.h"
#include "afxwin.h"

// RemoveDirDLG dialog

class RemoveDirDLG : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveDirDLG)

public:
	RemoveDirDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~RemoveDirDLG();

// Dialog Data
	enum { IDD = IDD_REMOVEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void DeleteDirectory(CString dir);
	CEdit directory;
	afx_msg void OnBnClickedOk();
};
