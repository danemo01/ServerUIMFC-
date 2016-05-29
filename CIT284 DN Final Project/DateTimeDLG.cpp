// DateTimeDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "DateTimeDLG.h"
#include "afxdialogex.h"


// DateTimeDLG dialog

IMPLEMENT_DYNAMIC(DateTimeDLG, CDialogEx)

DateTimeDLG::DateTimeDLG(UINT * mode, CWnd* pParent /*=NULL*/)
	: CDialogEx(DateTimeDLG::IDD, pParent)
{
	this->mode = mode;
}

DateTimeDLG::~DateTimeDLG()
{
}

void DateTimeDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMESTATIC, DateTimeStatic);

	this->setMode();
	this->executeStatic();


}

void DateTimeDLG::setMode()
{
	if (*mode == 1)
	{
		this->SetWindowTextW(_T("Time"));
	}
	else if (*mode == 2)
	{
		this->SetWindowTextW(_T("Date"));
	}
}

void DateTimeDLG::executeStatic()
{
	SYSTEMTIME beg;
	CString dateTime;
	GetLocalTime(&beg);
	if (*mode == 1)
	{
		dateTime.Format(_T("The time is %02d:%02d:%02d"), beg.wHour, beg.wMinute, beg.wSecond);
	}
	else if (*mode == 2)
		dateTime.Format(_T("Today is %02d\\%02d\\%02d"), beg.wMonth, beg.wDay, beg.wYear);

	DateTimeStatic.SetWindowTextW(dateTime);
}


BEGIN_MESSAGE_MAP(DateTimeDLG, CDialogEx)
END_MESSAGE_MAP()


// DateTimeDLG message handlers
