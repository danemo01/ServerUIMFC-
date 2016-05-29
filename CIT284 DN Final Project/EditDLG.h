#pragma once
#include "Resource.h"
#include "afxwin.h"

// EditDLG dialog

class EditDLG : public CDialogEx
{
	DECLARE_DYNAMIC(EditDLG)

public:
	EditDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~EditDLG();

// Dialog Data
	enum { IDD = IDD_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit eEdited;
	CEdit eDir;
	CString file;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSavebutton();
};
