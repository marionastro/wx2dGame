#include "GameStage.h"

GameStage::GameStage(wxPanel* container)
: m_Container(container)
{
    this->m_Objects = new GameObject[MAX_OBJECTS];
    container->Hide();
}

GameStage::~GameStage()
{
    delete[] this->m_Objects;
}

void GameStage::tick()
{
    Draw(m_ElapsedTicks);
}

void GameStage::Show()
{
    this->m_Container->Show();
    this->Run();
}

void GameStage::Hide()
{
    this->m_Container->Hide();
    this->Kill();
}

void GameStage::AddGameObject(GameObject& o)
{
    if (m_ObjectsCount < MAX_OBJECTS)
        m_Objects[m_ObjectsCount++] = o;
}
