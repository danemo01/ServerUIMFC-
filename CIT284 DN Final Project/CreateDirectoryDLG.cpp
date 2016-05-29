// CreateDirectoryDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "CreateDirectoryDLG.h"
#include "afxdialogex.h"


// CreateDirectoryDLG dialog

IMPLEMENT_DYNAMIC(CreateDirectoryDLG, CDialogEx)

CreateDirectoryDLG::CreateDirectoryDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(CreateDirectoryDLG::IDD, pParent)
{

}

CreateDirectoryDLG::~CreateDirectoryDLG()
{
}

void CreateDirectoryDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mkDirEdit);
}


BEGIN_MESSAGE_MAP(CreateDirectoryDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &CreateDirectoryDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// CreateDirectoryDLG message handlers


void CreateDirectoryDLG::OnBnClickedOk()
{
	CString directory;
	mkDirEdit.GetWindowText(directory);
	BOOL check = CreateDirectory(directory.GetString(), NULL);
	if (check == 1)
	{
		PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
		MessageBox(_T("Directory has been created!"), _T("Job's done"), MB_OK);
	}
	else
	{
		DWORD error = ::GetLastError();

		if (error == ERROR_ALREADY_EXISTS)
		{
			MessageBox(_T("Directory already exist"), _T("Error"), MB_OK);
		}
		else if (error == ERROR_PATH_NOT_FOUND)
		{
			MessageBox(_T("Directory path not found"), _T("Error"), MB_OK);
		}

		return;
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
