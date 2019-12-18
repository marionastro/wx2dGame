#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <wx/thread.h>
#include <wx/msgdlg.h>
#include <wx/app.h>

#define TICKS_PER_SECOND 60

class GameLoop : public wxThread
{
    public:
        GameLoop();

        virtual void tick() = 0;

        void* Entry() override;

        bool IsStarted() const      { return m_Started; }
        int GetElapsedTicks() const { return m_ElapsedTicks; }

    protected:
        wxApp& m_App = wxGetApp();
        bool m_Started = false;
        int m_ElapsedTicks = 0;
};

#endif // GAMELOOP_H
