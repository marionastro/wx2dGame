#include "Sprite.h"

Sprite::Sprite()
{}

Sprite::Sprite(wxStaticBitmap* staticBitmap)
: m_StaticBitmap(staticBitmap)
{
    m_StaticBitmap->SetAutoLayout(false);
}

void Sprite::SetFrame(Frame frame)
{
    m_StaticBitmap->SetBitmap(frame.GetBitmap());
}

void Sprite::SetPosition(const wxPoint& point)
{
    m_StaticBitmap->SetPosition(point);
}
