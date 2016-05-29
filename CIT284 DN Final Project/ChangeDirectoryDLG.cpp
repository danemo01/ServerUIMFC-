// ChangeDirectoryDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "ChangeDirectoryDLG.h"
#include "afxdialogex.h"


// ChangeDirectoryDLG dialog

IMPLEMENT_DYNAMIC(ChangeDirectoryDLG, CDialogEx)

ChangeDirectoryDLG::ChangeDirectoryDLG(CString * directory, CWnd* pParent /*=NULL*/)
	: CDialogEx(ChangeDirectoryDLG::IDD, pParent)
{
	this->directory = directory;
}

ChangeDirectoryDLG::~ChangeDirectoryDLG()
{
}

void ChangeDirectoryDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CDSTATIC, CHStatic);
	DDX_Control(pDX, IDC_CHEDIT, CHEdit);

	CHStatic.SetWindowTextW(*directory);
}


BEGIN_MESSAGE_MAP(ChangeDirectoryDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &ChangeDirectoryDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// ChangeDirectoryDLG message handlers


void ChangeDirectoryDLG::OnBnClickedOk()
{

	// TODO: Add your control notification handler code here
	CString tempDir;

	CHEdit.GetWindowTextW(tempDir);

	CFileFind ff;

	if (ff.FindFile(tempDir))
	{
		tempDir.Append(_T("\\*.*"));
		MessageBox(_T("Directory does exist!"), _T("Job's done"), MB_OK);
		*directory = tempDir;
		PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
	}
	else
	{
		MessageBox(_T("Directory cannot be found"), _T("Error"), MB_OK);
		return;
	}
	CDialogEx::OnOK();
}
