#ifndef GAME_H
#define GAME_H

#include "GameStage.h"

class Game
{
    public:
        Game(GameStage* startingStage);
        virtual ~Game();

        void Run();

        GameStage* GetCurrentStage() const { return m_CurrentStage; }

        void SetCurrentStage(GameStage* stage);

    private:
        GameStage* m_CurrentStage;
};

#endif // GAME_H
