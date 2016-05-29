#pragma once
#include "resource.h"
#include "afxwin.h"

// CreateDirectoryDLG dialog

class CreateDirectoryDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CreateDirectoryDLG)

public:
	CreateDirectoryDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CreateDirectoryDLG();

// Dialog Data
	enum { IDD = IDD_CREATEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit mkDirEdit;
	afx_msg void OnBnClickedOk();
};
