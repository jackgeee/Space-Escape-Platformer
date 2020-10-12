#include "_timer.h"


bool _timer::paused = true;
clock_t _timer::pausedAt = 0;
clock_t _timer::offset = 0;

_timer::_timer()
{
    //ctor
    startAt = 0;
    startingOffset = offset;
    if(paused) {
        startingOffset += clock() - pausedAt;
    }


}

_timer::~_timer()
{
    //dtor
}
bool _timer::isStarted()
{
    return started;
}



bool _timer::isStopped()
{
    return !started;
}

bool _timer::isPaused()
{
    return paused;
}


bool _timer::pause()
{
    if(paused){
        return false;
    }
    paused = true;
    //cout << "paused" << endl;
    pausedAt = clock();

    return true;
}
/* void _timer::pause()
{
    if(paused || !started)
        return;
    paused = true;
    pauseAt = clock();
} */

bool _timer::unpause()
{
    if(!pause){
        return false;
    }
    //cout << "unpaused" << endl;
    paused = false;
    offset += clock() - pausedAt; // adds pause time to total time paused

    return true;
}


bool _timer::resume()
{
  if(!paused){
        return false;
    }
    //cout << "unpaused" << endl;
    paused = false;
    offset += clock() - pausedAt; // adds pause time to total time paused

    return true;
}

void _timer::start()
{

    startingOffset = offset; // starting offset is total time pause when the timer was created
    if(paused){
        startingOffset += clock() - pausedAt;
    }
    startAt = clock();
     /*if(started) return;
    started = true;
    paused = false;
    startAt = clock(); */
}

void _timer::stop()
{
   // started = false;
}

void _timer::reset()
{
 startingOffset = offset; // same as start()
    if(paused){
        startingOffset += clock() - pausedAt;
    }
    startAt = clock();
}

clock_t _timer::getTicks()
{

    if(paused){
        return (clock() - startAt) - (offset - startingOffset + (clock() - pausedAt)); // if paused
        // returns the clock ticks since the clock was started/reset minus the amount of time pause and the current amount of time pause
    }
    return (clock() - startAt) - (offset - startingOffset);
    //returns the clock ticks since the clock was started/reset minus the amount of time pause
   /* if(!started) return 0;
    if(paused) return pauseAt - startAt;
    return clock() - startAt; */
}



























/*#include "_timer.h"

_timer::_timer()
{
    //ctor
    startAt =0;
    pauseAt =0;
    paused =false;
    started =false;
}

_timer::~_timer()
{
    //dtor
}
bool _timer::isStarted()
{
    return started;
}

bool _timer::isStoped()
{
    return !started;
}

bool _timer::isSpaused()
{
    return paused;
}
bool _timer::unpause()
{
    if(!pause){
        return false;
    }
    //cout << "unpaused" << endl;
    paused = false;
    offset += clock() - pausedAt; // adds pause time to total time paused

    return true;
}
 bool _timer::pause()
{
    if(paused || !started)
        return;
    paused = true;
    pauseAt= clock();

}

void _timer::resume()
{
    if(!paused)return;
    paused = false;
    startAt +=clock()-pauseAt;
}

void _timer::start()
{
    if(started)return;
    started= true;
    paused = false;
    startAt= clock();

}

void _timer::stop()
{
    started = false;
}

void _timer::reset()
{
    paused = false;
    startAt = clock();
}

clock_t _timer::getTicks()
{
    if(!started)return 0;
    if(paused)return pauseAt - startAt;
    return clock()-startAt;
}*/
