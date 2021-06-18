#include "adminGuihandle.h"
#include "adminfilehandle.h"
#include "Login_user.h"
#include "ReadPaper.h"

//(*InternalHeaders(adminGuihandle)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(adminGuihandle)
const long adminGuihandle::ID_TEXTCTRL1 = wxNewId();
const long adminGuihandle::ID_STATICTEXT1 = wxNewId();
const long adminGuihandle::ID_BUTTON1 = wxNewId();
const long adminGuihandle::ID_BUTTON2 = wxNewId();
const long adminGuihandle::ID_BUTTON3 = wxNewId();
const long adminGuihandle::ID_BUTTON4 = wxNewId();
const long adminGuihandle::ID_STATICTEXT2 = wxNewId();
const long adminGuihandle::ID_TEXTCTRL2 = wxNewId();
const long adminGuihandle::ID_BUTTON5 = wxNewId();
const long adminGuihandle::ID_STATICTEXT3 = wxNewId();
const long adminGuihandle::ID_TEXTCTRL3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(adminGuihandle,wxFrame)
	//(*EventTable(adminGuihandle)
	//*)
END_EVENT_TABLE()

adminGuihandle::adminGuihandle(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(adminGuihandle)
	Create(parent, id, _("Admin Access Privilages"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(488,367));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(208,32), wxSize(200,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Subject"), wxPoint(96,32), wxSize(88,16), 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(128,0,0));
	wxFont StaticText1Font(14,wxFONTFAMILY_MODERN,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Lucida Console"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Add Question"), wxPoint(56,216), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont Button1Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Read Paper"), wxPoint(248,216), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont Button2Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);
	Button3 = new wxButton(this, ID_BUTTON3, _("Modify Question"), wxPoint(56,264), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	wxFont Button3Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button3->SetFont(Button3Font);
	Button4 = new wxButton(this, ID_BUTTON4, _("Delete Question"), wxPoint(248,264), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	wxFont Button4Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button4->SetFont(Button4Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Question"), wxPoint(80,80), wxSize(88,16), 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxColour(128,0,0));
	wxFont StaticText2Font(14,wxFONTFAMILY_MODERN,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Lucida Console"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(208,80), wxSize(200,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button5 = new wxButton(this, ID_BUTTON5, _("Cancel"), wxPoint(168,312), wxSize(107,31), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("New Question "), wxPoint(40,128), wxSize(112,16), 0, _T("ID_STATICTEXT3"));
	StaticText3->SetForegroundColour(wxColour(128,0,0));
	wxFont StaticText3Font(14,wxFONTFAMILY_MODERN,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Lucida Console"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(208,128), wxSize(200,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adminGuihandle::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adminGuihandle::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adminGuihandle::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adminGuihandle::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&adminGuihandle::OnButton5Click);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&adminGuihandle::OnTextCtrl3Text);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&adminGuihandle::OnClose);
	//*)
}

adminGuihandle::~adminGuihandle()
{
	//(*Destroy(adminGuihandle)
	//*)
}


void adminGuihandle::OnButton1Click(wxCommandEvent& event)
{
    adminfilehandle admin_access;
    wxString subject = TextCtrl1->GetValue();
    wxString question = TextCtrl2->GetValue();
    if(admin_access.writeFile(subject.ToStdString(),question.ToStdString()))
    {
        wxMessageBox("Added Question Successfully",_("Add Question"));
        return;
    }
    wxMessageBox("Collision Detect, Can't add same question",_("Add Question"));
        return;
}

void adminGuihandle::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    ReadPaper * Rp = new ReadPaper(this);
    Rp->Show();
}

void adminGuihandle::OnButton3Click(wxCommandEvent& event)
{
    adminfilehandle admin_access;
    wxString subject = TextCtrl1->GetValue();
    wxString question = TextCtrl2->GetValue();
    wxString newquestion = TextCtrl3->GetValue();
    admin_access.modifyFile(subject.ToStdString(),question.ToStdString(),newquestion.ToStdString());
}

void adminGuihandle::OnButton4Click(wxCommandEvent& event)
{
    adminfilehandle admin_access;
    wxString subject = TextCtrl1->GetValue();
    wxString question = TextCtrl2->GetValue();
    admin_access.deleteFile(subject.ToStdString(),question.ToStdString());

}

void adminGuihandle::OnButton5Click(wxCommandEvent& event)
{
    this->Hide();
   Login_user * KK = new Login_user(this);
   KK->Show();
}

void adminGuihandle::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void adminGuihandle::OnTextCtrl3Text(wxCommandEvent& event)
{
}
