// AttributeDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "AttributeDLG.h"
#include "afxdialogex.h"
#include "Resource.h"
#include <sstream>
using std::wstringstream;


// AttributeDLG dialog

IMPLEMENT_DYNAMIC(AttributeDLG, CDialogEx)

AttributeDLG::AttributeDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(AttributeDLG::IDD, pParent)
{

}

AttributeDLG::~AttributeDLG()
{

}

void AttributeDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ATTEDIT, AttEdit);
	DDX_Control(pDX, IDC_ATTSTATIC, AttInfoStatic);
}


BEGIN_MESSAGE_MAP(AttributeDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &AttributeDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// AttributeDLG message handlers


void AttributeDLG::OnBnClickedOk()
{
	CString dir;
	CFileStatus status;

	this->AttEdit.GetWindowText(dir);

	if (CFile::GetStatus(dir, status))
	{
		wstringstream textS;

		textS << _T("File Name Directory & Attribute") << std::endl
			<< _T("File Name Directory : ") << dir.GetString() << std::endl
			<< _T("Attribute of the File: ") << status.m_attribute << std::endl;

		CString info(textS.str().c_str());

		this->AttInfoStatic.SetWindowTextW(info);
	}
	else{
		MessageBox(_T("Cannot find file, please try again"), _T("Error"), MB_OK);
	}
	// TODO: Add your control notification handler code here
	



}
