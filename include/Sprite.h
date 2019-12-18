#ifndef SPRITE_H
#define SPRITE_H

#include <wx/statbmp.h>
#include "Frame.h"

class Sprite
{
    public:
        Sprite();
        Sprite(wxStaticBitmap* staticBitmap);

        wxStaticBitmap* GetStaticBitmap() const { return m_StaticBitmap; }
        Frame GetFrame() const { return Frame(m_StaticBitmap->GetBitmap()); }

        void SetFrame(Frame frame);

        void SetPosition(const wxPoint& point);

    private:
        wxStaticBitmap* m_StaticBitmap;
};

#endif // SPRITE_H
