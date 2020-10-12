#include "_player.h"

_textureLoader *T= new _textureLoader();
_timer *tmr = new _timer();


_player::_player()
{
    //ctor
    verticies[0].x=0.0; verticies[0].y=0.0;verticies[0].z=-1.0;
    verticies[1].x=1.0; verticies[1].y=0.0;verticies[1].z=-1.0;
    verticies[2].x=1.0; verticies[2].y=1.0;verticies[2].z=-1.0;
    verticies[3].x=0.0; verticies[3].y=1.0;verticies[3].z=-1.0;

    runSpeed =0;
    jumpSpeed =.20;
    ascending = false;
    jumpActive = false;
    alive = true;
    xPos=-2.0;   //x position of the Player
    yPos=-1.4;   //y position of the Player
    zPos=-5.0;   //z position of the Player

    xSize =1;
    ySize =1;

    xRotation=0.0;
    yRotation=0.0;
    zRotation=0.0;
    levelHeight =(float)-1.4;
    action =4;
    prevDirection = 1;
    frames = 9;
    xMin=0;
     yMin= (float)1/yFrames;
     yFrames = 6;

                yMax= (float)1/6 ;
    xMax=(float)1/frames;

}

_player::~_player()
{
    //dtor
}

void _player::placePlayer()
{

}

void _player::drawPlayer()
{
    glColor3f(1.0,0.0,0.0);
   // glPushMatrix();  //ouping the Quad
    T->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotation,1.0,0.0,0.0);
    glRotatef(yRotation,0.0,1.0,0.0);
    glRotatef(zRotation,0.0,0.0,1.0);
    glScalef(xSize,ySize,1);

    glBegin(GL_QUADS);
      glTexCoord2f(xMin,yMax);
      glVertex3f(verticies[0].x, verticies[0].y,verticies[0].z);
      glTexCoord2f(xMax,yMax);
      glVertex3f(verticies[1].x, verticies[1].y,verticies[1].z);
      glTexCoord2f(xMax,yMin);
      glVertex3f(verticies[2].x, verticies[2].y,verticies[2].z);
      glTexCoord2f(xMin, yMin);
      glVertex3f(verticies[3].x, verticies[3].y,verticies[3].z);
    glEnd();
  //  glPopMatrix();

}

void _player::initPlayer(char *fileName, int frms)
{
   // T->TextureBinder();

frames = frms;
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->loadTexture(fileName);
    tmr->start();
}

void _player::actions()
{
    if(action ==5){

            yPos = -1.4;
            xPos = -200;


    }else{
    switch(action)
    {

        case 0: //walk left

                 if(yPos>levelHeight){
                             jumpActive = true;
                        }else{

                        }

                frames= 9.0;

                if(tmr->getTicks()>60)
                {

                xMin-=(float)1/frames;
                xMax-=(float)1/frames;
                yMin= 0.0;
                yMax= (float)1/yFrames ;
                prevDirection = 0;
                if(xMin<= (float)1/frames){xMin=(float)3/frames; xMax=(float)4/frames;}

                tmr->reset();
                }

         break;

        case 1: //walk right


                     if(yPos>levelHeight){
                             jumpActive = true;
                        }else{

                        }


                frames = 9;
                if(tmr->getTicks()>60)
                {
                 xMin-=(float)1/frames;
                xMax-=float(1/frames);
                yMin= 0;
                yMax= (float)1/yFrames ;
                prevDirection = 1;
                if(xMax<=(float)1/frames){xMin=(float)4/frames; xMax=(float)3/frames ;}

                tmr->reset();
                }

            break;

        case 3: //jump


            if(tmr->getTicks()>60){

                    if((jumpActive && yPos <= levelHeight)&& (jumpActive && !ascending)){ //returning to ground
                            cout <<"levelH:" <<levelHeight;
                        jumpActive = false;
                        ascending = false;


                     action = 4;

                    }

                    if(jumpActive && yPos>= -.3){
                        ascending   = false;
                    }
                    if(jumpActive && !ascending){ //descending

                if(prevDirection == 0){
                  yMin= (float)0/yFrames;
                yMax= (float)1/yFrames ;
                xMin = (float)7/frames;
                xMax  =(float)8/frames;
                }else{
                     yMin= (float)1/yFrames;
                yMax= (float)2/yFrames ;
               xMin = (float)7/frames;
                xMax  =(float)8/frames;
                }
                        if(yPos>=levelHeight){
                             yPos -= jumpSpeed;
                        }else{

                        }
                    }
            if(jumpActive&& ascending ){   //ascending case
                yMin= (float)0/yFrames;
                yMax= (float)1/yFrames;
            if(prevDirection == 0){
                xMin = (float)4/frames;
                xMax  =(float)5/frames;
                }else{
                 xMax = (float)4/frames;
                xMin  =(float)5/frames;
                }
                yPos += jumpSpeed;

            }

                tmr->reset();

            }

            break;
        case 4:
                if(yPos>levelHeight){
                             jumpActive = true;
                        }else{

                        }

                        //default stance
            frames = 9;
            yMin= 0;
                yMax= (float)1/yFrames ;
            if(prevDirection == 1){

            xMax=(float)0/frames;
              xMin=(float)1/frames;
            }else{

              xMin=(float)0/frames;
              xMax=(float)1/frames;
            }
            break;

        case 5: //death

            yPos = -1.4;
            xPos = -200;
            break;


    }
    }

}
