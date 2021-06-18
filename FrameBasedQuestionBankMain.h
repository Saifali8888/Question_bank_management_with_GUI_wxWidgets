/***************************************************************
 * Name:      FrameBasedQuestionBankMain.h
 * Purpose:   Defines Application Frame
 * Author:    Saif Ali  (saifalim888@gmail.com)
 * Created:   2021-06-14
 * Copyright: Saif Ali  ()
 * License:
 **************************************************************/

#ifndef FRAMEBASEDQUESTIONBANKMAIN_H
#define FRAMEBASEDQUESTIONBANKMAIN_H

//(*Headers(FrameBasedQuestionBankFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class FrameBasedQuestionBankFrame: public wxFrame
{
    public:

        FrameBasedQuestionBankFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~FrameBasedQuestionBankFrame();

    private:

        //(*Handlers(FrameBasedQuestionBankFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(FrameBasedQuestionBankFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        //*)

        //(*Declarations(FrameBasedQuestionBankFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FRAMEBASEDQUESTIONBANKMAIN_H
