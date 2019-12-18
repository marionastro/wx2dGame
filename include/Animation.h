#ifndef ANIMATION_H
#define ANIMATION_H

#include "Framesheet.h"
#include "Sprite.h"

class Animation
{
    public:
        Animation(Sprite sprite, int framesCount, Framesheet* framesheet, int* framesIndexes, int delay, bool loop = false);
        Animation(Sprite sprite, int framesCount, Frame* frames, int delay, bool loop = false);
        virtual ~Animation();

        Sprite GetSprite() const    { return m_Sprite; }
        int GetFramesCount() const  { return m_FramesCount; }
        Frame GetFrame(int i) const { return m_Frames[i]; }
        int GetDelay() const        { return m_Delay; }
        bool IsLooping() const      { return m_Loop; }

    private:
        Sprite m_Sprite;
        int m_FramesCount;
        Frame* m_Frames;
        int m_Delay;
        bool m_Loop;
};

#endif // ANIMATION_H
