#ifndef _FIRE_H
#define _FIRE_H
#include <_textureLoader.h>


class _fire
{
    public:
        _fire();
        virtual ~_fire();

        void drawSquare(float, float); // to draw a quad for the background
        void fireInit(char *);     // Load images to the background
        void fireMovement();// bool for Auto, string for direction
                                       // speed of the movement

       _textureLoader *FTex = new _textureLoader();


        float xMax,yMax,xMin,yMin,speed;  //  For texture coordinates
        int action;


    protected:



    private:
};

#endif // _FIRE_H
