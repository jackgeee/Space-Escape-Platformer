#include "_checkCollision.h"

_checkCollision::_checkCollision()
{
    //ctor
}

_checkCollision::~_checkCollision()
{
    //dtor
}
bool _checkCollision::isLinearCollision(float x1, float x2)
{
    if (fabs(x1 - x2) < 0.05)
        return true;
    else
        return false;
}

bool _checkCollision::isRadialCollision(float x1, float y1, float x2, float y2, float r1, float r2)
{
    if(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) < r1 + r2)
        return true;
    else
        return false;
}

bool _checkCollision::isCircleRayCollision(float, float, float, float, float)
{

}

bool _checkCollision::isCollisionFloor(float, float, float)
{

}
