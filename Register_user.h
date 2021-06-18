#ifndef REGISTER_USER_H
#define REGISTER_USER_H

//(*Headers(Register_user)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Register_user: public wxFrame
{
	public:

		Register_user(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Register_user();

		//(*Declarations(Register_user)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(Register_user)
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Register_user)
		void OnClose(wxCloseEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
