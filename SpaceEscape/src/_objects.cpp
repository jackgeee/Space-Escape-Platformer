#include "_objects.h"

_timer *tm = new _timer();
_objects::_objects()

{
    //ctor
    xPos = yPos =0;
    zPos = -4.0;

    xSize = 1;
    ySize = 1;

    rotateX = rotateY= rotateZ=0.0;
    xMin = yMin=0.0;
    xMax = ((float)1/frames);
    yMax = ((float)1/frames);
    action  =-2;
    isCollected = false;
    isEnemy  = false;
    frames = 0;
}

_objects::~_objects()
{
    //dtor
}
void _objects::drawObject()
{
    glBindTexture(GL_TEXTURE_2D, objTex);

    glPushMatrix();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(rotateX,1.0,0.0,0.0);
    glRotatef(rotateY,0.0,1.0,0.0);
    glRotatef(rotateZ,0.0,0.0,1.0);
    glScalef(xSize,ySize,.5);


      glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMin);
        glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(xMax,yMin);
        glVertex3f(-1.0, 1.0, 0.0);
        glTexCoord2f(xMax,yMax);
        glVertex3f(-1.0, -1.0, 0.0);
        glTexCoord2f(xMin,yMax);
        glVertex3f(1.0, -1.0, 0.0);

    glEnd();

    glPopMatrix();
}

void _objects::placeObject(float x, float y, float z)
{
    xPos =x;
    yPos =y;
    zPos =z;



}

void _objects::initObj(GLuint tex, int frms)
{
     objTex = tex;
    TE->start();
    frames = frms;
    xMax = ((float)1/frames);
    yMax = ((float)1/frames);
}
void _objects::actions()
{


    if(isCollected == true){

           action = 2;
        }



    switch(action){

    case -1:
        xPos = xPos;
        break;

        case 0:

                xPos+= .005;

            break;
        case 1:

                 xPos-= .01;

                if(xPos < -4.2){
                    xPos = 4;
                }

            break;
        case 2 :
            xPos = -1;
            yPos = 500;
            break;



    }



}
bool _objects::checkCollision(_player* player){


float r1 = 0;

if(player->jumpActive){
    r1 = .2;
}else{
    r1=.4;
}

 float  r2 = .2;
if(sqrt(pow((player->xPos+.45)-xPos,2.0)+pow((player->yPos)-yPos,2))< (r1+r2)){
    isCollected = true;


    return true;
}else{
    isCollected = false;
    return false;
}




}
void _objects::animateFire(){



                xMin+=.000009;
                xMax+=.000009 ;

    if(xMax <= 7/frames){

                    xMin = 0;
                    xMax = (float)1/frames;
                }


}
void _objects::animateFloor(){
       switch(action){
    case -1:
    xPos = xPos;
        break;

        case 0:

                xPos+= .01;

            break;
        case 1:

                 xPos-= .01;

                if(xPos < -4.2){
                    xPos = 4;
                }

            break;




    }


}




