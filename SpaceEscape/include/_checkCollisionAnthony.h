#ifndef _CHECKCOLLISION_H
#define _CHECKCOLLISION_H

#include<math.h>

class _checkCollision
{
    public:
        _checkCollision();
        virtual ~_checkCollision();

        bool isLinearCollision(float, float);
        bool isRadialCollision(float, float, float, float, float, float);

        bool isCircleRayCollision(float, float, float, float, float);

        bool isCollisionFloor(float,float,float);

    protected:

    private:
};

#endif // _CHECKCOLLISION_H
