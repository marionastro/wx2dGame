#include "Framesheet.h"

Framesheet::Framesheet(wxBitmap bitmap, int frames, wxSize fSize)
{
    m_Frames = new Frame[frames];
    int x = 0, y = 0;

    for (int i = 0; i<frames; i++)
    {
        wxRect r(wxPoint(x, y), fSize);
        Frame f(bitmap.GetSubBitmap(r));
        m_Frames[i] = f;

        x += fSize.GetWidth();

        if (x >= bitmap.GetWidth())
        {
            x = 0;
            y += fSize.GetHeight();
        }
    }
}

Framesheet::~Framesheet()
{
    delete[] this->m_Frames;
}

Frame Framesheet::GetFrame(int index)
{
    return m_Frames[index];
}
