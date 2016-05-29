#pragma once
#include "resource.h"
#include "afxwin.h"

// MoveDLG dialog

class MoveDLG : public CDialogEx
{
	DECLARE_DYNAMIC(MoveDLG)

public:
	MoveDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~MoveDLG();

// Dialog Data
	enum { IDD = IDD_MOVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit MDEdit1;
	CEdit MDEdit2;
	afx_msg void OnBnClickedOk();
};
