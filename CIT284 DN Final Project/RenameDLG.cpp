// RenameDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "RenameDLG.h"
#include "afxdialogex.h"


// RenameDLG dialog

IMPLEMENT_DYNAMIC(RenameDLG, CDialogEx)

RenameDLG::RenameDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(RenameDLG::IDD, pParent)
{

}

RenameDLG::~RenameDLG()
{
}

void RenameDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RENAMEEDIT1, renameEdit1);
	DDX_Control(pDX, IDC_RENAMEEDIT2, renameEdit2);
}


BEGIN_MESSAGE_MAP(RenameDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &RenameDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// RenameDLG message handlers


void RenameDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString file;
	CString renameFile;
	renameEdit1.GetWindowText(file);
	renameEdit2.GetWindowText(renameFile);

	
	CString fileDir = getFileDirectory(file);

	fileDir.Append(_T("\\"));
	fileDir.Append(renameFile);

	try {
		CFile::Rename(file, fileDir);

		
	}
	catch (CFileException* pEx)
	{
		CString error;
		error.Format(_T("File %20s not found, cause = %d\n"), file, pEx->m_cause);
		MessageBox(error, _T("Error"), MB_OK);
		return;
	}

	MessageBox(_T("You successfully rename your file!"), _T("Job's done"), MB_OK);
	CDialogEx::OnOK();
}


#include <sstream>
using std::wstringstream;
using std::wstring;

CString RenameDLG::getFileDirectory(CString text)
{
	wstringstream s;
	wstring string;
	wstring string2(L"\\");
	s << text.GetString();

	string = s.str();

	int curPos = 0;
	int pos;
	for (size_t i = string.size(); i > 0; i--)
	{
		if (string[i] == string2[0])
		{
			curPos = i;
			break;
		}

	}
	return text.Mid(0, curPos);
}
