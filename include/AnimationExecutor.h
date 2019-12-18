#ifndef ANIMATIONEXECUTOR_H
#define ANIMATIONEXECUTOR_H

#include "GameLoop.h"
#include "Animation.h"

class AnimationExecutor : public GameLoop
{
    public:
        ///*** Delay in seconds
        AnimationExecutor(Animation& animation, int delay = 0);

        void tick();

        void ForceKill();

        bool IsLooping() const          { return m_Animation.IsLooping(); }
        Animation& GetAnimation() const { return m_Animation; }

    private:
        Animation& m_Animation;
        int m_CurrentFrame = 0;
        int m_Delay;
};

#endif // ANIMATIONEXECUTOR_H
