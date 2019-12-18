#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(wxPanel* panel, Framesheet* framesheet)
: m_Framesheet(framesheet)
{
    this->m_X = 0;
    this->m_Y = 0;
    this->m_Sprite = Sprite(new wxStaticBitmap(panel, panel->GetId(), wxBitmap(), wxDefaultPosition));
    this->m_AnimationExecutor = nullptr;
}

GameObject::~GameObject()
{
    delete this->m_AnimationExecutor;
}

void GameObject::Spawn(int x, int y, Direction direction)
{
    m_X = x;
    m_Y = y;
    m_Sprite.SetPosition(wxPoint(m_X, m_Y));
}

void GameObject::Spawn(wxPoint point, Direction direction)
{
    this->Spawn(point.x, point.y, direction);
}

int GameObject::DistanceFrom(GameObject* o)
{
    return sqrt(
                 pow((o->m_X + o->GetWidth())  - (m_X + GetWidth()), 2) +
                 pow((o->m_Y + o->GetHeight()) - (m_Y + GetHeight()), 2)
    );
}

bool GameObject::Collides(GameObject* o)
{
    return DistanceFrom(o) <= o->GetWidth();
}

bool GameObject::IsNear(GameObject* o)
{
    return DistanceFrom(o) <= (o->GetWidth() * 1.5);
}

void GameObject::SetPosition(wxPoint p)
{
    m_Sprite.SetPosition(p);
    m_X = p.x;
    m_Y = p.y;
}

void GameObject::Move(Direction direction, int speed)
{}
