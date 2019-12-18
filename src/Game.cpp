#include "Game.h"

Game::Game(GameStage* startingStage)
: m_CurrentStage(startingStage)
{}

Game::~Game()
{
    delete this->m_CurrentStage;
}

void Game::Run()
{
    this->m_CurrentStage->Show();
}

void Game::SetCurrentStage(GameStage* stage)
{
    this->m_CurrentStage->Hide();
    this->m_CurrentStage = stage;
    this->m_CurrentStage->Show();
}
