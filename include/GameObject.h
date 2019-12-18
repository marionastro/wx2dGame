#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <wx/panel.h>
#include <math.h>
#include "AnimationExecutor.h"
#include "Sprite.h"
#include "ObjectMaker.h"
#include "Framesheet.h"

enum Direction
{
    RIGHT   = 0,
    LEFT    = 1,
    TOP     = 2,
    BOTTOM  = 3
};

class GameObject
{
    public:
        GameObject();
        GameObject(wxPanel* panel, Framesheet* framesheet);
        virtual ~GameObject();

        virtual void Spawn(int x, int y, Direction direction = RIGHT);

        void Spawn(wxPoint point, Direction direction = RIGHT);

        virtual void Move(Direction direction, int speed);

        bool IsNear(GameObject* o);

        bool Collides(GameObject* o);

        int DistanceFrom(GameObject* o);

        int GetX() const                    { return m_X; }
        int GetY() const                    { return m_Y; }
        Sprite GetSprite() const            { return m_Sprite; }
        int GetWidth() const                { return m_Sprite.GetStaticBitmap()->GetBitmap().GetWidth(); }
        int GetHeight() const               { return m_Sprite.GetStaticBitmap()->GetBitmap().GetHeight(); }
        Framesheet* GetFramesheet() const   { return m_Framesheet; }
        wxPoint GetPosition() const         { return wxPoint(m_X, m_Y); }

        void SetPosition(wxPoint p);

    protected:
        int m_X, m_Y;
        Sprite m_Sprite;
        AnimationExecutor* m_AnimationExecutor;
        Framesheet* m_Framesheet;
};

#endif // GAMEOBJECT_H
