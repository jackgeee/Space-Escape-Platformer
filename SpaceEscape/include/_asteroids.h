#ifndef _ASTEROIDS_H
#define _ASTEROIDS_H

#include <GL/gl.h>
#include <_textureLoader.h>
#include <_timer.h>
#include <_playerLvl2.h>
#include <_checkCollision.h>

#include <math.h>

#define PI 3.14159

class _asteroids
{
    public:
        _asteroids();
        virtual ~_asteroids();

        float xPos;
        float yPos;
        float zPos;

        float xSize;
        float ySize;

        float xRotation;
        float yRotation;
        float zRotation;

        float speed;

        void drawAsteroids();
        void placeAsteroids(float, float, float);
        void animation();
        void initAsteroids(_playerLvl2*, _checkCollision*);

        float frames;
        float xMax,xMin,yMax,yMin;

        float theta,v,t;

        _textureLoader *T;
        _timer *tmrA;
        _playerLvl2 *ply;
        _checkCollision *col;

    protected:

    private:
};

#endif // _ASTEROIDS_H
