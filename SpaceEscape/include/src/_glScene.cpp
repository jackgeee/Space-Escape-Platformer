#include "_glScene.h"
#include <_glLight.h>
#include <_Model.h>
#include <_inputs.h>
#include <_parallax.h>
#include <_player.h>

_Model *myModel = new _Model();
_inputs *kBMs = new _inputs();
_parallax *plxSky = new _parallax();
_parallax *plxFloor = new _parallax();
_player *ply = new _player();

_glScene::_glScene()
{
    //ctor
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{

   glShadeModel(GL_SMOOTH);    // to make graphics nicer
   glClearColor(1.0f,0.5f,0.0f,1.0f); // background color R,G,B,Alpha
   glClearDepth(1.0f);          // Depth Clearance
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);


   _glLight Light(GL_LIGHT0);

   myModel->initModel();
   plxSky->parallaxInit("images/sky.png");
   plxFloor->parallaxInit("images/floor.png");
   ply->initPlayer("images/ply.png");
   ply->yPos = -0.4;
   ply->zPos = -3.0;
  //glEnable(GL_COLOR_MATERIAL);

   return true;
}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();


   // glColor3f(1.0,0.0,0.0);              // setting colors

    glPushMatrix();
     glTranslated(0,0,-4.0);              //placing objects
     glScalef(6.3,6.3,1);
     plxSky->drawSquare(screenWidth,screenHeight); // draw background
     plxSky->scroll(false,"right",0.0005);            // Automatic background movement

     plxFloor->drawSquare(screenWidth,screenHeight); // draw background
     plxFloor->scroll(false,"right",0.005);            // Automatic background movement
    glPopMatrix();


	glPushMatrix();                      // grouping starts
  //  glutSolidTeapot(1.5);                // inbuilt model
    glTranslated(0,0,-8.0);              //placing objects
    myModel->drawModel();

    glPopMatrix();                       // grouping ends
    glPushMatrix();
     ply->actions();
     ply->drawPlayer();

    glPopMatrix();
}

GLvoid _glScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat) height; // ratio for window mode
    glViewport(0,0,width,height);                          // setting view port
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int _glScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_KEYDOWN:

             kBMs->wParam = wParam;
             kBMs->keyPressed(myModel); //handling Model Movements
             kBMs->keyEnv(plxSky,0.0005);   //handling Env
             kBMs->keyEnv(plxFloor,0.005);   //handling Env
             kBMs->keyPressed(ply);     // handling player movement
             break;

        case WM_KEYUP:
             kBMs->keyUp(ply);
             break;

        case WM_LBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;
        case WM_RBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;
        case WM_MBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            kBMs->mouseEventUp();
            break;

        case WM_MOUSEMOVE:
              kBMs->mouseMove(myModel,LOWORD(lParam),HIWORD(lParam));
             break;
        case WM_MOUSEWHEEL:
             kBMs->mouseWheel(myModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
    }
}
