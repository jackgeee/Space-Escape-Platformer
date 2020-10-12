#include "_parallaxLvl2.h"



_parallaxLvl2::_parallaxLvl2()
{
    //ctor
    //initialize the texture coordinates
    xMax =0.0;
    yMax =0.0;
    xMin =.5;
    yMin =.5;
    action = -1;
    speed = .0005;
}

_parallaxLvl2::~_parallaxLvl2()
{
    //dtor
}
void _parallaxLvl2::drawSquare(float width, float height)
{

    glColor3f(1.0,1.0,1.0);
    bTex->TextureBinder();
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, -1, -10.0);
    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, -1, -10.0);
    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, 1, -10.0);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, 1, -10.0);

    glEnd();


}

void _parallaxLvl2::parallaxInit(char* fileName)
{
    bTex->loadTexture(fileName);
}
/*void _parallax::scroll(bool Auto, string dir, float speed)
{
   if(Auto)     // To Address Automatic movement of the background
   {
       if(dir=="up")  // keyword "up"
       {
           yMin -=speed;
           yMax -=speed;
       }

        if(dir=="down")  // keyword "down"
       {
           yMin +=speed;
           yMax +=speed;
       }
        if(dir=="left")  // keyword "left"
       {
           xMin -=speed;
           xMax -=speed;
       }
        if(dir=="right")  // keyword "right"
       {
           xMin +=speed;
           xMax +=speed;
       }
   }
}
*/
void _parallaxLvl2::actions(){

switch(action){
case -1:
     yMin-=speed;
           yMax -=speed;
    break;

}

}
