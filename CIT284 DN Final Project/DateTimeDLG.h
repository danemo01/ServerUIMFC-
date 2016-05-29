#pragma once
#include "resource.h"
#include "afxwin.h"

// DateTimeDLG dialog


class DateTimeDLG : public CDialogEx
{
	DECLARE_DYNAMIC(DateTimeDLG)

public:
	DateTimeDLG(UINT * mode, CWnd* pParent = NULL);   // standard constructor
	virtual ~DateTimeDLG();

// Dialog Data
	enum { IDD = IDD_DATETIMEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	UINT * mode;
	void setMode();
	void executeStatic();
	DECLARE_MESSAGE_MAP()
public:
	CStatic DateTimeStatic;
};
