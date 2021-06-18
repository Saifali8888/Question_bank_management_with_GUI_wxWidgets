/***************************************************************
 * Name:      FrameBasedQuestionBankMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Saif Ali  (saifalim888@gmail.com)
 * Created:   2021-06-14
 * Copyright: Saif Ali  ()
 * License:
 **************************************************************/

#include "FrameBasedQuestionBankMain.h"
#include <wx/msgdlg.h>
#include "Register_user.h"
#include "Login_user.h"
//(*InternalHeaders(FrameBasedQuestionBankFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(FrameBasedQuestionBankFrame)
const long FrameBasedQuestionBankFrame::ID_STATICTEXT1 = wxNewId();
const long FrameBasedQuestionBankFrame::ID_BUTTON1 = wxNewId();
const long FrameBasedQuestionBankFrame::ID_BUTTON2 = wxNewId();
const long FrameBasedQuestionBankFrame::ID_BUTTON3 = wxNewId();
const long FrameBasedQuestionBankFrame::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FrameBasedQuestionBankFrame,wxFrame)
    //(*EventTable(FrameBasedQuestionBankFrame)
    //*)
END_EVENT_TABLE()

FrameBasedQuestionBankFrame::FrameBasedQuestionBankFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(FrameBasedQuestionBankFrame)
    Create(parent, wxID_ANY, _("QuestionBank management"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(368,191));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to Question bank management "), wxPoint(48,32), wxSize(288,24), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(0,0,128));
    wxFont StaticText1Font(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Impact"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("Register"), wxPoint(56,88), wxSize(91,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !Button1Font.Ok() ) Button1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    Button1Font.SetFaceName(_T("Times New Roman"));
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("Login"), wxPoint(56,128), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !Button2Font.Ok() ) Button2Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    Button2Font.SetFaceName(_T("Times New Roman"));
    Button2->SetFont(Button2Font);
    Button3 = new wxButton(this, ID_BUTTON3, _("About"), wxPoint(192,88), wxSize(96,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Button4 = new wxButton(this, ID_BUTTON4, _("Quit"), wxPoint(192,128), wxSize(96,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    wxFont Button4Font(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FrameBasedQuestionBankFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FrameBasedQuestionBankFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FrameBasedQuestionBankFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FrameBasedQuestionBankFrame::OnButton4Click);
    //*)
}

FrameBasedQuestionBankFrame::~FrameBasedQuestionBankFrame()
{
    //(*Destroy(FrameBasedQuestionBankFrame)
    //*)
}

void FrameBasedQuestionBankFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void FrameBasedQuestionBankFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void FrameBasedQuestionBankFrame::OnButton4Click(wxCommandEvent& event)
{
     exit(0);
}

void FrameBasedQuestionBankFrame::OnButton1Click(wxCommandEvent& event)
{
    this->Hide();
    Register_user * Ruser = new Register_user(this);
    Ruser->Show();

}

void FrameBasedQuestionBankFrame::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void FrameBasedQuestionBankFrame::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    Login_user *Luser = new Login_user(this);
    Luser->Show();
}

void FrameBasedQuestionBankFrame::OnButton3Click(wxCommandEvent& event)
{
    wxMessageBox("Manages All Question papers", _("Welcome to Question Bank"));
}
