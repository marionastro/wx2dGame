#ifndef FRAMESHEET_H
#define FRAMESHEET_H

#include "Frame.h"

class Framesheet
{
    public:
        Framesheet(){}
        Framesheet(wxBitmap bitmap, int frames, wxSize fSize);

        virtual ~Framesheet();

        Frame GetFrame(int index);

    private:
        Frame* m_Frames;
};

#endif // FRAMESHEET_H
