#pragma once

#include "resource.h"
#include "afxwin.h"
// CopyDialog dialog

class CopyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CopyDialog)

public:
	CopyDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CopyDialog();

// Dialog Data
	enum { IDD = IDD_COPYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit copyEdit1;
	CEdit copyEdit2;
	afx_msg void OnBnClickedOk();
};
