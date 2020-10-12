#include "_glScene.h"
#include <_glLight.h>
#include <_Model.h>
#include <_inputs.h>
#include <_parallax.h>
#include <_player.h>
#include <Menus.h>
#include <_objects.h>
#include <_parallaxLvl2.h>
#include <_playerLvl2.h>
#include <_inputsLvl2.h>
#include <_checkCollision.h>
#include <_asteroids.h>
#include <sounds.h>
#include <ctime>

_parallax *plxSky = new _parallax();
_parallax *plxFloor = new _parallax();

_parallaxLvl2 *plx2 = new _parallaxLvl2();
_parallax *plx3 =new _parallax();
_parallax *lose = new _parallax();
_parallax *win = new _parallax();
_player *ply = new _player();
_playerLvl2 *ply2 = new _playerLvl2();
Menus *menu = new Menus();
_textureLoader *objTex = new _textureLoader();
_textureLoader *floorTex = new _textureLoader();
_textureLoader *virusTex = new _textureLoader();
_timer *tmr2 = new _timer();
_inputs *kBMs = new _inputs();
_inputsLvl2 *kBMs2 = new _inputsLvl2();
_asteroids ast[5];
_checkCollision *col = new _checkCollision();
_objects fire[8];
_objects pfloor[6];
_objects firewall[8];
time_t startTimeSeconds;
sounds *music = new sounds();
/*
_objects tp[8];
_objects virus[4];
int tps = 0;
*/

_glScene::_glScene()
{
    //ctor
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    startedTime = 0;

}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL(bool * quit)
{
    closeGame = quit;


   glShadeModel(GL_SMOOTH);    // to make graphics nicer
   glClearColor(1.0f,0.5f,0.0f,1.0f); // background color R,G,B,Alpha
   glClearDepth(1.0f);          // Depth Clearance
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);


   _glLight Light(GL_LIGHT0);




    objTex->loadTexture("images/firewall.png");
    floorTex->loadTexture("images/platform.png");
    win->parallaxInit("images/winFlipped.png");
   lose->parallaxInit("images/loseFlipped.png");
   plxSky->parallaxInit("images/sky.png");
   plxFloor->parallaxInit("images/space.png");
   ply->initPlayer("images/astr.png", 4);
   ply2->initPlayer("images/astr.png", 9);
   plx2->parallaxInit("images/spacer.jpg");
   plx3->parallaxInit("images/bg.png");

music->initSounds();
 music->playMusic("adastra.wav");


   ply->yPos = -1.4 ;
   ply->zPos = -3.0;
   ply2->yPos = -1.5 ;
   ply2->zPos = -3.0;
    menu->landingMenuInit("images/landPage2.png");
    menu->mainMenuInit("images/main.png");
    menu->helpMenuInit("images/helpMenu2.png");
    menu->pauseMenuInit("images/pauseMenu.png");
    menu->creditMenuInit("images/credits.png");
    menu->gameOverMenuInit("images/gameOverMenu.png");
    menu->victoryMenuInit("images/victoryMenu.png");

    for (int i = 0; i < 5; i++)
    {
        ast[i].initAsteroids(ply2, col);
        ast[i].xSize = 0.3;
        ast[i].ySize = 0.3;
        ast[i].zPos = -5.0;
        float x = -3.0 + (float)(rand()) /((float)(RAND_MAX/(6)));
        ast[i].placeAsteroids(x,2.5, 0.05);
    }

  //glEnable(GL_COLOR_MATERIAL);

 for(int i=0; i <5; i++){

     pfloor[i].initObj(floorTex->tex,1);
    pfloor[i].xSize = .65;
    pfloor[i].ySize = .3;
   // pfloor[i].placeObject(-.4,-.4,-2);


 }
  pfloor[0].placeObject(-2.5,-1.65,-4);
   pfloor[1].placeObject(-1.5,-1.65,-4);
    pfloor[2].placeObject(-.5,-1.65,-4);
     pfloor[3].placeObject(1.5,-1.65,-4);
      pfloor[4].placeObject(2.5,-1.65,-4);


  for(int i=0; i <8; i++){

        fire[i].initObj(objTex->tex,8);


        firewall[i].initObj(objTex->tex,8);



      firewall[i].rotateZ = -90;

  }
  firewall[2].placeObject(-2,1,-4.0);
   firewall[0].placeObject(-2,0,-4.0);
    firewall[1].placeObject(-2,-.5,-4.0);

      firewall[3].placeObject(-2,-1.5,-4.0);
      firewall[4].placeObject(-2,1.5,-4.0);
   firewall[5].placeObject(-2,.5,-3.0);
    firewall[6].placeObject(-2,-.3,5.0);

      firewall[7].placeObject(-2,-1.5,-2.0);

  fire[0].placeObject(-2,-.98,-4.0);
    fire[1].placeObject(-.75,-.98,-4.0);
      fire[2].placeObject(0,-.98,-4.0);
        fire[3].placeObject(2,-.98,-4.0);
          fire[4].placeObject(-2,-.98,-5.0);
    fire[5].placeObject(-1,-.98,5.0);
      fire[6].placeObject(0,-.98,-5.0);
        fire[7].placeObject(1,-.98,-2.0);
    cout <<firewall[3].xPos  << " ";
      cout <<firewall[3].yPos  << " ";

}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();


	 if(menu->inMenu)
    {
        if(menu->menuName == "main menu"){

            ply->alive = true;
            ply2->alive = true;
            ply->levelHeight = -1.4;
            level = 1;
            ply->jumpActive =false;
            ply->yPos = -1.4;
            ply->actions();
             pfloor[0].placeObject(-2.5,-1.65,-4);
   pfloor[1].placeObject(-1.5,-1.65,-4);
    pfloor[2].placeObject(-.5,-1.65,-4);
     pfloor[3].placeObject(1.5,-1.65,-4);
      pfloor[4].placeObject(2.5,-1.65,-4);


        }
        glPushMatrix();
       // menu->menuInputs(kBMs,closeGame);
       // cout << kBMs->keys;
       menu->menuInputs(kBMs,closeGame, level);


        menu->drawMenus(screenWidth, screenHeight);




        glPopMatrix();
         startTimeSeconds = time(NULL);

    }

   // glColor3f(1.0,0.0,0.0);              // setting colors

    else{




//(time(NULL)-startTimeSeconds) <= 3
 if((level ==1 && (time(NULL)-startTimeSeconds) <= 10 )&&(ply->alive  && level ==1)){// level 1


 if(ply->yPos < -3.9){

    ply->alive = false;
    ply->jumpActive = false;
   // ply->ascending =false;
    lose->drawSquare(screenWidth, screenHeight);


    menu->inMenu = true;
    menu->menuName = "credit menu";


 }

 menu->menuInputs(kBMs,closeGame, level);



    glPushMatrix();
     glTranslated(0,0,-4.0);              //placing objects
     glScalef(6,6,1);


    plxFloor->actions();

     plxFloor->drawSquare(screenWidth,screenHeight); // draw background


    glPopMatrix();
if(ply2->alive == false){
 lose->drawSquare(screenWidth, screenHeight);

        }else{

        }


    glPushMatrix();
     ply->actions();
     ply->drawPlayer();



      glPopMatrix();
 glPushMatrix();
    for(int i = 0; i < 5; i++){
            pfloor[i].drawObject();
        pfloor[i].animateFloor();

    }
glPopMatrix();

      for(int i = 0; i <6; i++){

        if((!col->isLinearCollision(ply->xPos/1.375,pfloor[i].xPos))){/*&&
            ((!col->isLinearCollision(ply->yPos,pfloor[0].yPos))|| (!col->isLinearCollision(ply->yPos,pfloor[1].yPos))|| (!col->isLinearCollision(ply->yPos,pfloor[2].yPos))
|| (!col->isLinearCollision(ply->yPos,pfloor[3].yPos)) || (!col->isLinearCollision(ply->yPos,pfloor[4].yPos)) ||(!col->isLinearCollision(ply->yPos,pfloor[5].yPos))){*/



        floorFlag = 0;


        }else{
          //  cout << pfloor[i].xPos;

       // cout << "Floor: " << i;;
       // cout << endl;
        floorFlag =1;break;
       // cout <<"hello";
  }

      }
      if(floorFlag == 1){

        ply->levelHeight = -1.4;
      }else{
        ply->levelHeight = -4;

      }
      floorFlag =1;

    glPushMatrix();
      for (int i = 0; i < 8; i++)
    {
           firewall[i].animateFire();
        firewall[i].drawObject();

    }

    glPopMatrix();

if((time(NULL)-startTimeSeconds) == 10 && ply->alive) {
level = 2;

}



 }
if( level ==2  && (time(NULL)-startTimeSeconds) <= 20){ //level 2


  glPushMatrix();
     glTranslated(0,0,-4.0);              //placing objects
     glScalef(6,6,1);


    plx2->actions();
     plx2->drawSquare(screenWidth,screenHeight); // draw background


    glPopMatrix();
    glPushMatrix();
      if(ply2->alive){

        }else{
        lose->drawSquare(screenWidth, screenHeight);
        ply->action = 5;
        }
glPopMatrix();


    glPushMatrix();
     ply2->actions();

     ply2->drawPlayer();
      glPopMatrix();


 for (int i = 0; i < 5; i++)
    {
        ast[i].drawAsteroids();
        if(ast[i].yPos < -2.5)
        {
            float x = -3.0 + (float)(rand()) /((float)(RAND_MAX/(6)));
            ast[i].placeAsteroids(x,2.5, 0.05);
        }
    }
    if(ply2->alive == false){

        menu->inMenu = true;
    menu->menuName = "credit menu";

    }


    for (int i = 0; i < 8; i++)
    {

        fire[i].drawObject();
        fire[i].animateFire();

    }

    if((time(NULL)-startTimeSeconds) == 20 && ply->alive) {
level = 3;
  ply->yPos =-1.6;

}

} //level 2 end
if(level  == 3 && (time(NULL)-startTimeSeconds)<= 30){

        if(ply->alive){

        }else{
        ply->action = 5;
        }
        ply->levelHeight = -1.5;

glPushMatrix();
     glTranslated(0,0,-4.0);              //placing objects
     glScalef(6,6,1);


    plx3->actions();
     plx3->drawSquare(screenWidth,screenHeight); // draw background
    glPopMatrix();


     glPushMatrix();
     ply->actions();
     ply->drawPlayer();


      glPopMatrix();
         if((time(NULL)-startTimeSeconds) == 30 && ply->alive) {
level = 0;
  ply->yPos =-1.4;
menu->inMenu = true;
menu->menuName = "credit menu";

}


}





 }



}
GLint _glScene::idleGLScene()
{

    menu->menuInputs(kBMs, closeGame, level);


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
    switch (uMsg){

        case WM_KEYDOWN:

        if(ply->action==5 ||ply2->action==5 ){
        ply->action=5;
        ply2->action = 5;
            }else{
                 kBMs->wParam = wParam;
                 kBMs2->wParam = wParam;

             kBMs->keyEnv(plxFloor,0.01,1);   //handling Env
             kBMs->keyEnv(plx3,.01,3);
              //handling Env
            /*
             kBMs->keyObj(tp,8);    //move tp
             kBMs->keyObj(virus, 4);//move virus
             */
             kBMs->keyPressed(ply,1);     // handling player movement
            kBMs2->keyPressed(ply2);

                 kBMs->keyPressed(pfloor, 5,1 );




            }


             break;


        case WM_KEYUP:                  //key released
             if(ply->action==5 || ply2->action == 5){
                ply->action=5;
                ply2->action = 5;

            }else{
            kBMs->keyUp(plxFloor);  //release of parallax
             kBMs->keyUp(ply);      //key release action for player
            kBMs->keyUp(pfloor, 5);
            kBMs2->keyUp(plx2);
             kBMs2->keyUp(ply2);
             kBMs->keyUp(plx3);
             /*
             kBMs->keyUp(tp,8);        //key release action for toilet paper
             kBMs->keyUp(virus,4);      //key release action for virus enemies
            */

            }

             break;


        case WM_LBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs2->wParam = wParam;

        case WM_RBUTTONDOWN:
            kBMs->wParam = wParam;
             kBMs2->wParam = wParam;

            break;
        case WM_MBUTTONDOWN:
            kBMs->wParam = wParam;
             kBMs2->wParam = wParam;

            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            kBMs->mouseEventUp();
             kBMs2->mouseEventUp();
            break;

        case WM_MOUSEMOVE:

             break;
        case WM_MOUSEWHEEL:

            break;
    }
}
