
#include <_inputs.h>

_inputs::_inputs()
{
    //ctor
    Mouse_Rotate=false;
    Mouse_Translate=false;
    keys = new bool[221];
}

_inputs::~_inputs()
{
    //dtor
    delete keys;
}

void _inputs::keyEnv(_parallax* plx, float speed, int level)
{
    switch(wParam){
            case VK_LEFT:
                if(level == 1){

                }else{
                  plx->action = 0;
                }




            break;
        case VK_RIGHT:
            plx->action = 1;
             break;
        case VK_DOWN:

            break;
        case VK_UP:

            break;
    }
}

void _inputs::keyPressed(_objects* obj,int n, int lvl)
{
    switch(wParam)
    {
        case VK_LEFT:
if(lvl == 1){


                }else{
                   for(int i = 0; i < n; i++){

                 obj[i].action =0;
            }
                }

            break;
        case VK_RIGHT:
             for(int i = 0; i < n; i++){

                 obj[i].action =1;
            }

             break;



    }
}

bool _inputs::isKeyPressed(int keyCode)
{
    return keys[keyCode];
}
void _inputs::keyPressed(_player* ply, int level)
{

    if(ply->action == 5){   //action 5 was supposed to represent end of the game
    ply->action = 5;
    }else{

        switch(wParam)
    {
        case VK_LEFT:
            if (level == 1){}else{
            if(ply->jumpActive == true){
            ply->action=3;

            }else{
                ply->action = 0;

            }
            }


            break;
        case VK_RIGHT:
           if(ply->jumpActive == true){
            ply->action=3;


            }else{
            ply->action = 1;

            }

             break;
        case VK_DOWN:
            ply->action = ply->action;
            break;
        case VK_UP:

            if(ply->jumpActive == true){
            ply->action=3;
            }else{
            ply->jumpActive = true;
            ply->ascending = true;
            }

            break;

    }
    }
}
void _inputs::keyUp(_player* ply)
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

/*void _inputs::keyObj(_objects *obj, int n)
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

void _inputs::keyUp(_objects* obj, int n)
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
*/
void _inputs::keyUp(_parallax* px)
{
     switch(wParam)
    {
        default:
            px->action = -1;
    break;
    }
}
void _inputs::keyUp(_objects* obj, int n)
{
     switch(wParam)
    {
        default:
             for(int i = 0; i < n; i++){

                 obj[i].action =-1;
            }

    break;
    }
}


void _inputs::keyUp()   // Fill this depending on your game actions
{
    switch(wParam)
    {
        default: break;
    }
}

void _inputs::mouseEventDown(_Model* Mdl, double x, double y)
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

void _inputs::mouseEventUp()
{
    Mouse_Rotate=false;
    Mouse_Translate=false;
}

void _inputs::mouseWheel(_Model* Mdl, double Delta)
{
    Mdl->posZ +=Delta/100;
}

void _inputs::mouseMove(_Model* Mdl, double x, double y)
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


