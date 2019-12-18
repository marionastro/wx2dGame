#ifndef FRAME_H
#define FRAME_H

#include <wx/bitmap.h>

class Frame
{
    public:
        Frame();

        Frame(const wxBitmap& bitmap);

        wxBitmap GetBitmap() const { return m_Bitmap; }

    private:
        wxBitmap m_Bitmap;
};

#endif // FRAME_H
