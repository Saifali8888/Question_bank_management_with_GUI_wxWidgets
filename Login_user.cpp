#include "Login_user.h"
#include "Login.h"

#include "FrameBasedQuestionBankMain.h"
#include "adminGuihandle.h"
#include "ReadPaper.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(Login_user)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(Login_user)
const long Login_user::ID_BUTTON2 = wxNewId();
const long Login_user::ID_TEXTCTRL1 = wxNewId();
const long Login_user::ID_TEXTCTRL2 = wxNewId();
const long Login_user::ID_BITMAPCOMBOBOX1 = wxNewId();
const long Login_user::ID_STATICTEXT1 = wxNewId();
const long Login_user::ID_STATICTEXT2 = wxNewId();
const long Login_user::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Login_user,wxFrame)
	//(*EventTable(Login_user)
	//*)
END_EVENT_TABLE()

Login_user::Login_user(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Login_user)
	Create(parent, id, _("Login"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,254));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	Button2 = new wxButton(this, ID_BUTTON2, _("OK"), wxPoint(80,176), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(224,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(224,104), wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BitmapComboBox1 = new wxBitmapComboBox(this, ID_BITMAPCOMBOBOX1, wxEmptyString, wxPoint(728,288), wxDefaultSize, 0, NULL, 0, wxDefaultValidator, _T("ID_BITMAPCOMBOBOX1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("UserName"), wxPoint(80,56), wxSize(112,16), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SCRIPT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Password"), wxPoint(80,104), wxSize(112,16), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SCRIPT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Cancel"), wxPoint(216,176), wxSize(91,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Login_user::OnButton2Click);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Login_user::OnButton1Click1);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Login_user::OnClose);
	//*)
}

Login_user::~Login_user()
{
	//(*Destroy(Login_user)
	//*)
}


void Login_user::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void Login_user::OnButton2Click(wxCommandEvent& event)
{
    wxString name = TextCtrl1->GetValue();
    wxString password = TextCtrl2->GetValue();
    Login user_login;
    if(name.empty() || password.empty())
    {
        wxMessageBox("Enter Name and password", _("Pressed OK"));
        return;
    }
    if(name.ToStdString()== "admin" && password.ToStdString()=="1234")
    {
        this->Hide();
        adminGuihandle *agh = new adminGuihandle(this);
        agh->Show();
    }
    else if(user_login.CompleteUserLogin(name.ToStdString(),password.ToStdString()))
    {
        Hide();
        ReadPaper * RR = new ReadPaper(this);
        RR->Show();
    }
    else
    {
        wxMessageBox("Oops Invalid Username & Password ",_("Info"));
    }

}

void Login_user::OnButton1Click1(wxCommandEvent& event)
{
    this->Hide();
    FrameBasedQuestionBankFrame *KK = new FrameBasedQuestionBankFrame(0);
    KK->Show();
}
