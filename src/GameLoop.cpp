#include "GameLoop.h"

GameLoop::GameLoop()
: wxThread(wxTHREAD_JOINABLE)
{}

void* GameLoop::Entry()
{
    m_Started = true;

    while(m_Started)
    {
        if (!this->TestDestroy())
        {
            if (m_ElapsedTicks + 1 > INT_MAX) m_ElapsedTicks = -1;

            m_ElapsedTicks++;
            m_App.CallAfter([this]
                {
                    this->tick();
                }
            );

            this->Sleep(1000 / TICKS_PER_SECOND);
        }
    }
}
