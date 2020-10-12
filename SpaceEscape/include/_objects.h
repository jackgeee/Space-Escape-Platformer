#ifndef _OBJECTS_H
#define _OBJECTS_H

#include <GL/gl.h>
#include <_textureLoader.h>
#include <_timer.h>
#include <_player.h>
#include <math.h>

class _objects          //header file for objects
{
    public:
        _objects();
        virtual ~_objects();
        void drawObject();
        void placeObject(float, float, float);
        void initObj(GLuint, int);
        void animateFire();
        bool checkCollision(_player*);
        void animateFloor();



       void actions();

        bool isCollected;
        bool isEnemy;
        GLuint objTex;      //obj texture;

        float xPos, yPos, zPos;
        int action;
        float xSize, ySize;
        int frames;

        float rotateX, rotateY, rotateZ;


        _timer *TE = new _timer();
    protected:

    private:

        float xMin,xMax,yMin,yMax;


};

#endif // _OBJECTS_H
