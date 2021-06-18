#include "Register_user.h"
#include "FrameBasedQuestionBankMain.h"
#include "Register.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(Register_user)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(Register_user)
const long Register_user::ID_BUTTON1 = wxNewId();
const long Register_user::ID_TEXTCTRL1 = wxNewId();
const long Register_user::ID_TEXTCTRL2 = wxNewId();
const long Register_user::ID_TEXTCTRL3 = wxNewId();
const long Register_user::ID_STATICTEXT1 = wxNewId();
const long Register_user::ID_STATICTEXT2 = wxNewId();
const long Register_user::ID_STATICTEXT3 = wxNewId();
const long Register_user::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Register_user,wxFrame)
	//(*EventTable(Register_user)
	//*)
END_EVENT_TABLE()

Register_user::Register_user(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(Register_user)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,224));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(80,176), wxSize(112,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(264,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(264,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(264,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("UserName"), wxPoint(72,40), wxSize(88,16), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SCRIPT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Password"), wxPoint(72,80), wxSize(88,16), 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SCRIPT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Confirm Password"), wxPoint(72,120), wxSize(104,16), 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_SCRIPT,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxPoint(248,176), wxSize(112,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Register_user::OnButton1Click);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Register_user::OnTextCtrl3Text);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Register_user::OnButton2Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Register_user::OnClose);
	//*)
}

Register_user::~Register_user()
{
	//(*Destroy(Register_user)
	//*)
}


void Register_user::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void Register_user::OnButton1Click(wxCommandEvent& event)
{
    wxString username = TextCtrl1->GetValue();
     wxString password = TextCtrl2->GetValue();
     wxString Confpassword = TextCtrl3->GetValue();
     if(username.empty() || password.empty() || Confpassword.empty())
     {
          wxMessageBox("Please Enter UserName and Password", _("Pressed OK"));
          return;
     }
     if(password!=Confpassword)
     {
         wxMessageBox("Please Enter Equal password", _("Pressed OK"));
         return;
     }

     Register user_registration;
     if(user_registration.CompleteRegistration(username.ToStdString(),password.ToStdString()))
     {
         wxMessageBox("Registration Successfull");
     }

    this->Hide();
    FrameBasedQuestionBankFrame *KK = new FrameBasedQuestionBankFrame(0);
    KK->Show();

}

void Register_user::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void Register_user::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    FrameBasedQuestionBankFrame *KK = new FrameBasedQuestionBankFrame(0);
    KK->Show();
}
