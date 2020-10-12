#ifndef _PARALLAXLVL2_H
#define _PARALLAXLVL2_H

#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<_textureLoader.h>

using namespace std;

class _parallaxLvl2
{
    public:
        _parallaxLvl2();
        virtual ~_parallaxLvl2();

        void drawSquare(float, float); // to draw a quad for the background
        void parallaxInit(char *);     // Load images to the background
        void scroll(bool,string,float);// bool for Auto, string for direction
                                       // speed of the movement
        void actions();
       _textureLoader *bTex = new _textureLoader();


        float xMax,yMax,xMin,yMin,speed;  //  For texture coordinates
        int action;

    protected:

    private:
};

#endif // _PARALLAX_H
