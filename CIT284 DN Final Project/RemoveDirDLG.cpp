// RemoveDirDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "RemoveDirDLG.h"
#include "afxdialogex.h"


// RemoveDirDLG dialog

IMPLEMENT_DYNAMIC(RemoveDirDLG, CDialogEx)

RemoveDirDLG::RemoveDirDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveDirDLG::IDD, pParent)
{

}

RemoveDirDLG::~RemoveDirDLG()
{
}

void RemoveDirDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, directory);
}


BEGIN_MESSAGE_MAP(RemoveDirDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &RemoveDirDLG::OnBnClickedOk)
END_MESSAGE_MAP()

void RemoveDirDLG::DeleteDirectory(CString dir)
{
	CFileFind finder;
	CString strWildcard(dir);
	strWildcard += _T("\\*.*");
	CString str = L"";

	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		if (finder.IsDots())
		{
			CString sFile = finder.GetFileName();
			if (sFile != "." && sFile != "..")
			{
				CString sFile = finder.GetFileName();
				str = finder.GetFilePath();
				BOOL bDel = DeleteFile(str);
			}
		}
		else if (finder.IsDirectory())
		{
			CString sDir = finder.GetFileName();
			str = finder.GetFilePath();
			if (str != "." && str != "..")
			{
				this->DeleteDirectory(str);
				BOOL bDel = RemoveDirectory(str);
			}
		}
		else
		{
			CString sFile = finder.GetFileName();
			str = finder.GetFilePath();
			BOOL bDel = DeleteFile(str);
		}
	}
	BOOL bDel = RemoveDirectory(dir);
	finder.Close();
}

// RemoveDirDLG message handlers


void RemoveDirDLG::OnBnClickedOk()
{
	CString dir;
	CFileFind finder;
	directory.GetWindowText(dir);

	CString strWildcard(dir);
	strWildcard += _T("\\*.*");
	CString str = L"";

	BOOL bWorking = finder.FindFile(strWildcard);

	if (bWorking){

		this->DeleteDirectory(dir);
	}
	else
	{
		MessageBox(_T("Directory could not be found"), _T("Error"), MB_OK);
		return;
	}

	MessageBox(_T("File has been deleted"), _T("Job's done"), MB_OK);
	PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
