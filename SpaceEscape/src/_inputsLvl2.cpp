#include "_inputsLvl2.h"


_inputsLvl2::_inputsLvl2()
{
    //ctor
    Mouse_Rotate=false;
    Mouse_Translate=false;
}

_inputsLvl2::~_inputsLvl2()
{
    //dtor
}

void _inputsLvl2::keyEnv(_parallaxLvl2* plx, float speed)
{
    switch(wParam){
            case VK_LEFT:




            break;
        case VK_RIGHT:

             break;
        case VK_DOWN:

            break;
        case VK_UP:

            break;
    }
}

/*void _inputs::keyPressed(_Model* Mdl)
{
    switch(wParam)
    {
        case VK_LEFT:
            Mdl->rotateY +=1.0;
            break;
        case VK_RIGHT:
            Mdl->rotateY -=1.0;
             break;
        case VK_DOWN:
             Mdl->rotateX -=1.0;
            break;
        case VK_UP:
            Mdl->rotateX +=1.0;
            break;
        case VK_ADD:break;
            Mdl->posZ +=1.0;
        case VK_SUBTRACT: break;
            Mdl->posZ -=1.0;
    }
}*/

void _inputsLvl2::keyPressed(_playerLvl2* ply)
{

    if(ply->action == 5){   //action 5 was supposed to represent end of the game
    ply->action = 5;
    }else{

        switch(wParam)
    {
        case VK_LEFT:


                ply->action = 0;




            break;
        case VK_RIGHT:

            ply->action = 1;



             break;
        case VK_DOWN:
            ply->action = ply->action;
            break;
        case VK_UP:


            break;

    }
    }
}
void _inputsLvl2::keyUp(_playerLvl2* ply)
{
    if(ply->action == 5){
        ply->action - 5;

    }else{
     switch(wParam)
    {
        default:
            if(ply->jumpActive == true){
                ply->action = 3;

            }else{
            ply->action = 4;
            }

    break;
    }
}
}

void _inputsLvl2::keyObj(_objects *obj, int n)
{
    switch(wParam){
            case VK_LEFT:


               for(int i = 0; i < n; i++){

                 if(obj[i].isCollected){
                    obj[i].action = 2;

                }else{
                 obj[i].action = 0;
                }
            }


            break;
        case VK_RIGHT:
              for(int i = 0; i < n; i++){
                if(obj[i].isCollected){
                    obj[i].action = 2;
                }else{
                 obj[i].action = 1;
                }
            }


             break;
        case VK_DOWN:

            break;
        case VK_UP:

            break;

    }
}

void _inputsLvl2::keyUp(_objects* obj, int n)
{
     switch(wParam)
    {
        default:
            for(int i =0; i < n; i++){

                     if(obj[i].isCollected){
                    obj[i].action = 2;
                }else{
                 obj[i].action = -1;
                }

            }

    break;
    }
}
void _inputsLvl2::keyUp(_parallaxLvl2* px)
{
     switch(wParam)
    {
        default:
            px->action = -1;
    break;
    }
}


void _inputsLvl2::keyUp()   // Fill this depending on your game actions
{
    switch(wParam)
    {
        default: break;
    }
}

void _inputsLvl2::mouseEventDown(_Model* Mdl, double x, double y)
{
    prev_Mouse_X =x;
    prev_Mouse_Y =y;

    switch(wParam)
    {

        case MK_LBUTTON:
            Mouse_Rotate=true;
           // Mouse_Translate=false;
            break;
        case MK_RBUTTON:
            Mouse_Translate=true;
          //  Mouse_Rotate =false;
            break;
        case MK_MBUTTON:break;

        default: break;
    }
}

void _inputsLvl2::mouseEventUp()
{
    Mouse_Rotate=false;
    Mouse_Translate=false;
}

void _inputsLvl2::mouseWheel(_Model* Mdl, double Delta)
{
    Mdl->posZ +=Delta/100;
}

void _inputsLvl2::mouseMove(_Model* Mdl, double x, double y)
{
    if(Mouse_Rotate)
    {
        Mdl->rotateY +=(x-prev_Mouse_X)/3;
        Mdl->rotateX +=(y-prev_Mouse_Y)/3;
    }

    if(Mouse_Translate)
    {
       Mdl->posX +=(x-prev_Mouse_X)/100;
       Mdl->posY -=(y-prev_Mouse_Y)/100;
    }
    prev_Mouse_X =x;
    prev_Mouse_Y =y;
}

