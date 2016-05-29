// PrintDLG.cpp : implementation file
//

#include "stdafx.h"
#include "CIT284 DN Final Project.h"
#include "PrintDLG.h"
#include "afxdialogex.h"


// PrintDLG dialog

IMPLEMENT_DYNAMIC(PrintDLG, CDialogEx)

PrintDLG::PrintDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(PrintDLG::IDD, pParent)
{

}

PrintDLG::~PrintDLG()
{
}

void PrintDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINTFILEDIR, printFile);
	DDX_Control(pDX, IDC_PRINTINPUT, printInput);
	DDX_Control(pDX, IDC_PRINTOPTION, printerOptionCBox);
	DDX_Control(pDX, IDC_COPIESCOMBO, amountOfCopies);
	CString num;

	printerOptionCBox.AddString(_T("Landscape"));
	printerOptionCBox.AddString(_T("Portaint"));
	printerOptionCBox.AddString(_T("Compress"));

	for (int i = 0; i < 20; i++)
	{
		num.Format(_T("%d"), i+1);
		amountOfCopies.AddString(num);
	}
}


BEGIN_MESSAGE_MAP(PrintDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &PrintDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDC_PRINT, &PrintDLG::OnBnClickedPrint)
END_MESSAGE_MAP()


// PrintDLG message handlers

#include <sstream>
#include <fstream>
using std::wifstream;
void PrintDLG::OnBnClickedOk()
{
	CString file;
	printFile.GetWindowText(file);

	wifstream ifs(file);
	wstring line;
	text.clear();
	if (!ifs)
	{
		MessageBox(_T("Couldn't open file, try again"), _T("Error"), MB_OK);
		ifs.close();
		return;
	}
	PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
	MessageBox(_T("File exist!"), _T("Job's done"), MB_OK);
	
	while (std::getline(ifs, line))
	{
		line += L"\r\n";
		text += line;
	}

	printInput.SetWindowText(text.c_str());
	ifs.close();
	// TODO: Add your control notification handler code here
}

using std::wofstream;
#define COMPRESS "\x1b(s16.5h"
#define LANDSCAPE "\x1b&11O"
#define PORTRAIT "\x1b&10O"

void PrintDLG::OnBnClickedPrint()
{

//	printInput.GetWindowText()

	std::string * mode = nullptr;
	int copies = amountOfCopies.GetCurSel() + 1;
	switch (printerOptionCBox.GetCurSel())
	{
	case 0:
		//mode = LANDSCAPE;
		mode = new std::string(LANDSCAPE);
		break;
	case 1:
		//mode = PORTRAIT;
		mode = new std::string(PORTRAIT);
		break;
	case 2:
		mode = new std::string(COMPRESS);
		break;
	default:
		MessageBox(_T("You could not print what you wanted!"), _T("Error"), MB_OK);
		return;
	}

	wofstream printer("\\\\cts-fp.bhcc.dom\\D119");

	if (printer)
	{
		for (size_t i = 0; i < copies; i++)
		{
			PlaySound(_T("sounds\\JobsDone.wav"), NULL, SND_SYNC);
			printer << mode->c_str() << text;
			printer << '\f';
			MessageBox(_T("You've printed!"), _T("Job's done"), MB_OK);
		}
	}
	else
		MessageBox(_T("couldn't print, make sure it's printer \\\\cts-fp.bhcc.dom\\D119 "), _T("Error"), MB_OK);	

	printer.close();
	}

	// TODO: Add your control notification handler code here

