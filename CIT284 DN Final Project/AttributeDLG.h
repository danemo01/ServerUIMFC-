#pragma once
#include "afxwin.h"


// AttributeDLG dialog

class AttributeDLG : public CDialogEx
{
	DECLARE_DYNAMIC(AttributeDLG)

public:
	AttributeDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~AttributeDLG();

// Dialog Data
	enum { IDD = IDD_ATTRIB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit AttEdit;
	CStatic AttInfoStatic;
	afx_msg void OnBnClickedOk();
};
