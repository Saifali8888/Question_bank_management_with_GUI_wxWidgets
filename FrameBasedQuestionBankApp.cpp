/***************************************************************
 * Name:      FrameBasedQuestionBankApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Saif Ali  (saifalim888@gmail.com)
 * Created:   2021-06-14
 * Copyright: Saif Ali  ()
 * License:
 **************************************************************/

#include "FrameBasedQuestionBankApp.h"

//(*AppHeaders
#include "FrameBasedQuestionBankMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(FrameBasedQuestionBankApp);

bool FrameBasedQuestionBankApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	FrameBasedQuestionBankFrame* Frame = new FrameBasedQuestionBankFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
