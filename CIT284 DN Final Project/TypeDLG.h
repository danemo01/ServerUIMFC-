#pragma once
#include "afxwin.h"
#include "resource.h"

// TypeDLG dialog

class TypeDLG : public CDialogEx
{
	DECLARE_DYNAMIC(TypeDLG)

public:
	TypeDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~TypeDLG();

// Dialog Data
	enum { IDD = IDD_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit typeInput;
	CEdit typeDir;
	afx_msg void OnBnClickedOk();
};
