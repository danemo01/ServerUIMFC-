// CopyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "CopyDialog.h"
#include "afxdialogex.h"


// CopyDialog dialog

IMPLEMENT_DYNAMIC(CopyDialog, CDialogEx)

CopyDialog::CopyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CopyDialog::IDD, pParent)
{

}

CopyDialog::~CopyDialog()
{
}

void CopyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CopyEdit1, copyEdit1);
	DDX_Control(pDX, IDC_COPYEDIT2, copyEdit2);
}


BEGIN_MESSAGE_MAP(CopyDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CopyDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CopyDialog message handlers


void CopyDialog::OnBnClickedOk()
{
	CString filePath;
	CString copyPath;
	copyEdit1.GetWindowTextW(filePath);
	copyEdit2.GetWindowTextW(copyPath);

	BOOL isWork = CopyFile(filePath, copyPath, FALSE);

	if (isWork){
		MessageBox(_T("File has been copied"), _T("Job's done"), MB_OK);
		PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
	}
	else
	{
		MessageBox(_T("File did not open"), _T("Error"), MB_OK);
		return;
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
