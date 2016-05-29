#pragma once

#include "resource.h"
#include "afxwin.h"
#include <string>
using std::wstring;
// PrintDLG dialog

class PrintDLG : public CDialogEx
{
	DECLARE_DYNAMIC(PrintDLG)

public:
	PrintDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~PrintDLG();

// Dialog Data
	enum { IDD = IDD_PRINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit printFile;
	CEdit printInput;
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangePrintoption();
	CComboBox printerOptionCBox;
	CComboBox amountOfCopies;
	afx_msg void OnBnClickedPrint();
	wstring text;
};
