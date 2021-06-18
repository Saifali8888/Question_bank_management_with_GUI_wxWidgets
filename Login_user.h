#ifndef LOGIN_USER_H
#define LOGIN_USER_H

#include "FrameBasedQuestionBankApp.h"

//(*Headers(Login_user)
#include <wx/bmpcbox.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Login_user: public wxFrame
{
	public:

		Login_user(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Login_user();

		FrameBasedQuestionBankApp * MainFrame;
		//(*Declarations(Login_user)
		wxBitmapComboBox* BitmapComboBox1;
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(Login_user)
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BITMAPCOMBOBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(Login_user)
		void OnClose(wxCloseEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
