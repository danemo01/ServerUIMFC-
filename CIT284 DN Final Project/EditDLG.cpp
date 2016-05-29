// EditDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "EditDLG.h"
#include "afxdialogex.h"


// EditDLG dialog

IMPLEMENT_DYNAMIC(EditDLG, CDialogEx)

EditDLG::EditDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(EditDLG::IDD, pParent)
	, file(_T(""))
{

}

EditDLG::~EditDLG()
{
}

void EditDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EEDIT1, eEdited);
	DDX_Control(pDX, IDC_EEDIT2, eDir);
}


BEGIN_MESSAGE_MAP(EditDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &EditDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SAVEBUTTON, &EditDLG::OnBnClickedSavebutton)
END_MESSAGE_MAP()


// EditDLG message handlers
#include <sstream>
#include <fstream>
using std::wifstream;
using std::wstring;

void EditDLG::OnBnClickedOk()
{
	eDir.GetWindowText(file);

	wifstream  ifs(file);
	wstring text;
	wstring line;
	//wostringstream wsout;

	if (!ifs)
	{
		MessageBox(_T("Couldn't open file, try again"), _T("Error"), MB_OK);
		ifs.close();
		return;
	}

	PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
	MessageBox(_T("File exist!"), _T("Job's done"), MB_OK);


	//	wsout << ofs.rdbuf();

	while (std::getline(ifs, line))
	{
		line += L"\r\n";
		text += line;
	}

	eEdited.SetWindowText(text.c_str());

	//wcout << wsout.str();

	ifs.close();
	// TODO: Add your control notification handler code here
}

#include <fstream>
using std::wofstream;
void EditDLG::OnBnClickedSavebutton()
{
	CString fs;
	wofstream ofs(file);
	if (!ofs)
	{
		MessageBox(_T("Error"), _T("Error"), MB_OK);
		ofs.close();
		return;
	}

	eEdited.GetWindowText(fs);

	ofs << (LPCTSTR)fs;
	ofs.close();

	MessageBox(_T("You've saved"), _T("Job's done"), MB_OK);

	CDialogEx::OnOK();
}
