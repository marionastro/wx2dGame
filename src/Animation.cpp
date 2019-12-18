#include "Animation.h"

Animation::Animation(Sprite sprite, int framesCount, Frame* frames, int delay, bool loop)
: m_Sprite(sprite)
, m_FramesCount(framesCount)
, m_Frames(frames)
, m_Delay(delay)
, m_Loop(loop)
{}

Animation::~Animation()
{
    delete this->m_Frames;
}
