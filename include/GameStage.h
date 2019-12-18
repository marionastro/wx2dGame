#ifndef GAMESTAGE_H
#define GAMESTAGE_H

#include <wx/panel.h>
#include <wx/statbmp.h>
#include "GameLoop.h"
#include "GameObject.h"

#define MAX_OBJECTS 32

class GameStage : public GameLoop
{
    public:
        GameStage(wxPanel* container);

        virtual ~GameStage();

        void tick();

        void Show();

        void Hide();

        void AddGameObject(GameObject& o);

        virtual void Setup()        = 0;
        virtual void Draw(int time) = 0;

        wxPanel* GetContainer() const   { return m_Container; }
        GameObject* GetObjects() const  { return m_Objects; }
        int GetObjectsCount() const     { return m_ObjectsCount; }

    private:
        wxPanel*    m_Container;
        GameObject* m_Objects;

        int m_ObjectsCount = 0;
};

#endif // GAMESTAGE_H
