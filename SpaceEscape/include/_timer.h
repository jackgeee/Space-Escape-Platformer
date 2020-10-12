#ifndef _TIMER_H
#define _TIMER_H
#include <time.h>
#include <iostream>

class _timer
{
    public:
        _timer();
        virtual ~_timer();

        bool started;


        bool isStarted();
        bool isStopped();
        static bool isPaused();

        static bool pause();
        bool resume();
        void start();
        void stop();
        void reset();
         static bool unpause();



        clock_t getTicks();

    protected:
           static clock_t offset;
           clock_t startingOffset;
            static clock_t pausedAt;
            clock_t startAt;

            static bool paused;

    private:
};

#endif // _TIMER_H


/*#ifndef _TIMER_H
#define _TIMER_H
#include<time.h>

class _timer
{
    public:
        _timer();
        virtual ~_timer();

        //clock_t startAt;
        clock_t pauseAt;

        bool started;
        //bool paused;

        bool isStarted();


        bool isStoped();
        bool isSpaused();

        static bool pause();
        void resume();
        void start();
        void stop();
        void reset();
         static bool unpause();

        clock_t getTicks();


    protected:
    static clock_t offset;
           clock_t startingOffset;
            static clock_t pausedAt;
            clock_t startAt;

            static bool paused;

    private:
};

#endif // _TIMER_H

*/
