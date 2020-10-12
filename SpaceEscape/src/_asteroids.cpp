#include "_asteroids.h"

_asteroids::_asteroids()
{
    xPos=0.0;
    yPos=0.0;
    zPos=0.0;

    xSize =1.0;
    ySize =1.0;

    xRotation=0.0;
    yRotation=0.0;
    zRotation=0.0;

    speed = 0.00001;

    frames = 4;

    xMin=0.0;
    xMax=0.25;

    yMin=0.0;
    yMax=0.25;

    v = .9;
    t = 0.0;
}

_asteroids::~_asteroids()
{
    //dtor
}

void _asteroids::drawAsteroids()
{
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    T->TextureBinder();

    glTranslatef(xPos,yPos,zPos);
    glRotatef(xRotation,1.0,0.0,0.0);
    glRotatef(yRotation,0.0,1.0,0.0);
    glRotatef(zRotation,0.0,0.0,1.0);
    glScalef(xSize,ySize,1);

    glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMin);
        glVertex3f(1.0, 1.0, 1.0);
        glTexCoord2f(xMax,yMin);
        glVertex3f(-1.0, 1.0, 1.0);
        glTexCoord2f(xMax,yMax);
        glVertex3f(-1.0, -1.0, 1.0);
        glTexCoord2f(xMin,yMax);
        glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    animation();
    glPopMatrix();
}

void _asteroids::initAsteroids(_playerLvl2 *player, _checkCollision *collision)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    T = new _textureLoader();
    T->loadTexture("images/asteroids.png");

    tmrA = new _timer();
    tmrA->start();

    ply = player;
    col = collision;
}

void _asteroids::placeAsteroids(float x, float y, float s)
{
    xPos = x;
    yPos = y;
    speed = s;
    t = 0;
    theta = 0;
}

void _asteroids::animation()
{
    if(col->isRadialCollision(ply->xPos, ply->yPos, xPos, yPos, ply->xSize, xSize))
    {
        ply->alive = false;
        if (ply->xPos < xPos)
            theta = (tanh((ply->yPos - yPos)/(ply->xPos - xPos)));
        else
            theta = (45+tanh((ply->yPos - yPos)/(xPos - ply->xPos)));
    }

    t+=0.03;
    yPos += (v*t*sin(theta)-0.5*speed*t*t)/1500;
    if(theta != 0)
        xPos += (v*t*cos(theta))/2000;

    if(tmrA->getTicks()>200)
    {
        xMin+=1.0/frames;
        xMax+=1.0/frames;

        yMin=0.0;
        yMax=0.25;

        if(xMax>1.0){xMin=0.0; xMax=1.0/frames;}

        tmrA->reset();
    }
}
