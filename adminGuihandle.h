#ifndef ADMINGUIHANDLE_H
#define ADMINGUIHANDLE_H

//(*Headers(adminGuihandle)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class adminGuihandle: public wxFrame
{
	public:

		adminGuihandle(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~adminGuihandle();

		//(*Declarations(adminGuihandle)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(adminGuihandle)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		//*)

	private:

		//(*Handlers(adminGuihandle)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
