#pragma once
#include <iostream>
#include "afxwin.h"

// RenameDLG dialog

class RenameDLG : public CDialogEx
{
	DECLARE_DYNAMIC(RenameDLG)

public:
	RenameDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~RenameDLG();

// Dialog Data
	enum { IDD = IDD_RENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString getFileDirectory(CString text);
	CEdit renameEdit1;
	CEdit renameEdit2;
};
