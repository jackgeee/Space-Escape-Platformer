#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include<GL/glut.h>

#include<iostream>

using namespace std;

class _glScene
{
    public:
        _glScene();               // constructor
        virtual ~_glScene();      // Deconstructor
        GLint initGL(bool *);           // initialize OpenGL
        GLint drawScene();        // Renderer
        GLvoid reSizeScene(GLsizei, GLsizei); // screen size changes
        GLint idleGLScene();        // Renderer
        int winMsg(HWND, UINT, WPARAM, LPARAM);	// Callback of inputs
        int level = 0;
        //WPARAM wParm;
        bool * closeGame;
        float screenHeight, screenWidth; // to map background images
        int floorFlag;
        int startedTime;
    protected:

    private:
};

#endif // _GLSCENE_H
