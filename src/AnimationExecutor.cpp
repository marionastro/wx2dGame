#include "AnimationExecutor.h"

AnimationExecutor::AnimationExecutor(Animation& animation, int delay)
: m_Animation(animation)
, m_Delay(delay)
{}

void AnimationExecutor::tick()
{
    if (GetElapsedTicks() < m_Delay * TICKS_PER_SECOND) return;
    if (GetElapsedTicks() == 0 || GetElapsedTicks()%m_Animation.GetDelay() == 0)
    {
        m_Animation.GetSprite().SetFrame(m_Animation.GetFrame(m_CurrentFrame));
        m_CurrentFrame++;

        if (m_CurrentFrame == m_Animation.GetFramesCount())
        {
            m_CurrentFrame = 0;
            m_Animation.GetSprite().SetFrame(m_Animation.GetFrame(m_CurrentFrame));

            if (!m_Animation.IsLooping())
            {
                this->ForceKill();
            }
        }
    }
}


void AnimationExecutor::ForceKill()
{
    this->Kill();
}
