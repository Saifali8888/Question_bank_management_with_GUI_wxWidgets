#ifndef READPAPER_H
#define READPAPER_H

//(*Headers(ReadPaper)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ReadPaper: public wxFrame
{
	public:

		ReadPaper(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ReadPaper();
        void sendvector(void);
		//(*Declarations(ReadPaper)
		wxButton* Button2;
		wxChoice* Choice1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(ReadPaper)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON2;
		static const long ID_CHOICE1;
		//*)

	private:

		//(*Handlers(ReadPaper)
		void OnMenuItem1Selected(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
