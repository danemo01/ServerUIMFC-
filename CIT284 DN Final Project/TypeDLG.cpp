// TypeDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "TypeDLG.h"
#include "afxdialogex.h"


// TypeDLG dialog

IMPLEMENT_DYNAMIC(TypeDLG, CDialogEx)

TypeDLG::TypeDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(TypeDLG::IDD, pParent)
{

}

TypeDLG::~TypeDLG()
{
}

void TypeDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TYPEINPUT, typeInput);
	DDX_Control(pDX, IDC_TYPEDIR, typeDir);
}


BEGIN_MESSAGE_MAP(TypeDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &TypeDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// TypeDLG message handlers

#include <sstream>
#include <fstream>
using std::wifstream;
using std::wstring;
void TypeDLG::OnBnClickedOk()
{
	CString file;
	typeDir.GetWindowText(file);

	wifstream  ofs(file);
	wstring text;
	wstring line;
	//wostringstream wsout;

	if (!ofs)
	{
		MessageBox(_T("Couldn't open file, try again"), _T("Error"), MB_OK);
		ofs.close();
		return;
	}


	MessageBox(_T("File exist!"), _T("Job's done"), MB_OK);

//	wsout << ofs.rdbuf();
	
	while (std::getline(ofs, line))
	{
		line += L"\r\n";
		text += line;
	}

	typeInput.SetWindowText(text.c_str());

	//wcout << wsout.str();

	ofs.close();


	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
}
