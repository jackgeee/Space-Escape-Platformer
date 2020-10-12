#include "Menus.h"


Menus::Menus()
{

    //ctor

    inMenu = true;
    menuName = "landing page";
    mainTexture = new _textureLoader();
}



void Menus::helpMenuInit(char* fileName)
{
    helpTexture->loadTexture(fileName);
}

void Menus::mainMenuInit(char* fileName)
{
    mainTexture->loadTexture(fileName);
}

void Menus::landingMenuInit(char* fileName)
{
    landTexture->loadTexture(fileName);
}

void Menus::pauseMenuInit(char* fileName)
{
    pauseTexture->loadTexture(fileName);
}

void Menus::creditMenuInit(char* fileName)
{
    creditTexture->loadTexture(fileName);
}

void Menus::gameOverMenuInit(char* fileName)
{
    gameOverTexture->loadTexture(fileName);
}

void Menus::victoryMenuInit(char*fileName)
{
    victoryTexture->loadTexture(fileName);
}


void Menus::drawMenus(float width, float height)
{
    if(menuName != "pause menu")
    {

        if(menuName == "landing page")
        {
            landTexture->TextureBinder();
        }
        else if(menuName == "main menu")
        {
            mainTexture->TextureBinder();

        }
        else if(menuName == "help menu")
        {
            helpTexture->TextureBinder();
        }
        else if(menuName == "credit menu")
        {
            creditTexture->TextureBinder();
        }
        else if (menuName == "game over")
        {
            gameOverTexture->TextureBinder();
        }
        else if (menuName == "victory")
        {
            victoryTexture->TextureBinder();
        }
        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0,1.0);
        glVertex3f(-width/height, -1.0, -8.0);

        glTexCoord2f(1.0,1.0);
        glVertex3f(width/height, -1.0, -8.0);

        glTexCoord2f(1.0,0.0);
        glVertex3f(width/height, 1.0, -8.0);

        glTexCoord2f(0.0,0.0);
        glVertex3f(-width/height, 1.0, -8.0);

        glEnd();
        glPopMatrix();
    }

    else
    {

        pauseTexture->TextureBinder();
        glPushMatrix();
        glScaled(3.33,3.33,1.0);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0,1.0);
        glVertex3f(-width/height, -1.0, -8.0);

        glTexCoord2f(1.0,1.0);
        glVertex3f(width/height, -1.0, -8.0);

        glTexCoord2f(1.0,0.0);
        glVertex3f(width/height, 1.0, -8.0);

        glTexCoord2f(0.0,0.0);
        glVertex3f(-width/height, 1.0, -8.0);

        glEnd();
        glPopMatrix();
    }
}

void Menus::drawButtons()
{

}
/*
void Menus::menuInputs(_inputs *kBMs, bool* exitGame){
   if(inMenu){


     if(menuName == "landing page"){

    switch(kBMs->wParam){
        case VK_RETURN:
            cout<< "hello";
            menuName = "main menu";



            break;

   }
     }
}
}

*/
void Menus::menuInputs(_inputs *kBMs, bool* exitGame, int &level)
{

    if(inMenu == false)
    {
        if(kBMs->wParam == (0x50))
        {
           _timer::pause();
            menuName = "pause menu";

            inMenu = true;

        }
    }
    if(menuName == "landing page")
    {

        if(kBMs->wParam == VK_RETURN)
        {

            menuName = "main menu";

        }
        else if(kBMs->wParam  == VK_DOWN)
        {
            *exitGame = true;
        }

    }
    else if(menuName == "main menu")
    {

        if(kBMs->wParam == 0X31){



            }

    if(kBMs->wParam == 0X32){


            }
        if(kBMs->wParam == 0x4E)
        {
            inMenu = false;

            /*_timer::resume();
            _timer tmr;
            //tmr.resume(); // unpause timers now that the game is running
           */_timer::unpause();
            menuName = "in game";



        }
        else if(kBMs->wParam == 0x48)
        {
            menuName = "help menu";
        }
        else if(kBMs->wParam == 0x43)
        {
            menuName = "credit menu";
        }
        else if(kBMs->wParam == 0x45)
        {
            *exitGame = true;
        }
    }
    else if(menuName == "credit menu" && kBMs->wParam  == VK_ESCAPE)
    {
        menuName = "main menu";
    }
    else if(menuName == "help menu" && kBMs->wParam == VK_ESCAPE)
    {
        menuName = "main menu";
    }
    else if(menuName == "game over" && kBMs->wParam == (0x45))
    {
        *exitGame = true;
    }
    else if(menuName == "victory" && kBMs->wParam == (0x45))
    {
        *exitGame = true;
    }
    else if(menuName == "pause menu")
    {
        if(kBMs->wParam == (VK_RETURN))
        {
            _timer::unpause();
            inMenu = false;
            menuName = "in game";
        }
        else if(kBMs->wParam == 0x45)
        {
            *exitGame = true;
        }
    }


}



Menus::~Menus()
{
    //dtor
}
