// MoveDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "MoveDLG.h"
#include "afxdialogex.h"


// MoveDLG dialog

IMPLEMENT_DYNAMIC(MoveDLG, CDialogEx)

MoveDLG::MoveDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(MoveDLG::IDD, pParent)
{

}

MoveDLG::~MoveDLG()
{
}

void MoveDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MDEDIT1, MDEdit1);
	DDX_Control(pDX, IDC_MDEDIT2, MDEdit2);

	
}


BEGIN_MESSAGE_MAP(MoveDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &MoveDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// MoveDLG message handlers


void MoveDLG::OnBnClickedOk()
{
	CString oldPath;
	CString newPath;

	MDEdit1.GetWindowTextW(oldPath);
	MDEdit2.GetWindowTextW(newPath);

	if (MoveFile(oldPath, newPath)){
		PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
		MessageBox(_T("You successfully move your file!"), _T("Job's done"), MB_OK);
	}
	else
	{
		MessageBox(_T("It didn't work"), _T("Error"), MB_OK);
		return;
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
