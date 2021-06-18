#include "ReadPaper.h"
#include "adminfilehandle.h"
#include "Login_user.h"
//(*InternalHeaders(ReadPaper)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)
#include <vector>
#include <string>
#include <wx/msgdlg.h>
//(*IdInit(ReadPaper)
const long ReadPaper::ID_TEXTCTRL1 = wxNewId();
const long ReadPaper::ID_STATICTEXT1 = wxNewId();
const long ReadPaper::ID_BUTTON2 = wxNewId();
const long ReadPaper::ID_CHOICE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ReadPaper,wxFrame)
	//(*EventTable(ReadPaper)
	//*)
END_EVENT_TABLE()

ReadPaper::ReadPaper(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ReadPaper)
	Create(parent, wxID_ANY, _("User Read Paper"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(617,304));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(24,64), wxSize(400,200), wxTE_MULTILINE|wxTE_RICH|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Please Select the subject"), wxPoint(72,24), wxSize(128,16), 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(64,0,0));
	wxFont StaticText1Font(14,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Lucida Console"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxPoint(464,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(448,104), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Center();

    sendvector();
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ReadPaper::OnTextCtrl1Text);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ReadPaper::OnButton2Click);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ReadPaper::OnChoice1Select);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&ReadPaper::OnClose);
	//*)
}

ReadPaper::~ReadPaper()
{
	//(*Destroy(ReadPaper)
	//*)
}


void ReadPaper::OnTextCtrl1Text(wxCommandEvent& event)
{

}

void ReadPaper::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void ReadPaper::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void ReadPaper::OnChoice1Select(wxCommandEvent& event)
{
    using namespace std;
    vector<string>FileText;
    //TextCtrl1->Clear();
    wxString subject = Choice1->GetStringSelection();
    wxMessageBox(subject, _("Please Enter UserName and Password"));
    adminfilehandle afh;
    if(afh.readFile(subject.ToStdString(),FileText))
    {
        TextCtrl1->SetValue("All Questions\n");
        for(std::string & line : FileText)
        {
            TextCtrl1->AppendText(line);
            TextCtrl1->AppendText(" \n");
        }
        return;
    }
    else
    {
        TextCtrl1->SetValue("Invalid Filename or File doesnt exits");
    }
    return;
}

void ReadPaper::sendvector(void)
{
    vector<string> filenames;
    adminfilehandle afh;
    afh.getfilePresentinDir(filenames);
    for(std::string & line : filenames)
    {
        Choice1->Append(_(line));
    }
}

void ReadPaper::OnButton2Click(wxCommandEvent& event)
{
    Hide();
    Login_user * Luser = new Login_user(this);
    Luser->Show();
}
