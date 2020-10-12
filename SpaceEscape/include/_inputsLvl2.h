#ifndef _INPUTSLVL2_H
#define _INPUTSLVL2_H

#include<windows.h>
#include<_Model.h>
#include<_parallaxLvl2.h>
#include<_playerLvl2.h>
#include<_objects.h>
//#include <Menus.h>

class _inputsLvl2
{
    public:
        _inputsLvl2();
        virtual ~_inputsLvl2();

        //void keyPressed(_Model *);   // model handling
        void keyPressed(_playerLvl2*);   // model handling
        void keyUp(_playerLvl2 *);   // model handling
        void keyEnv(_parallaxLvl2 *,float); // handles the background movement
        void keyObj(_objects *, int n);
        void keyUp(_objects *, int );
        void keyUp(_parallaxLvl2*);
        void keyUp();


        void mouseEventDown(_Model *,double ,double);
        void mouseEventUp();
        void mouseWheel(_Model *,double);
        void mouseMove(_Model *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Rotate;
        bool isKeyPressed(int keyCode);
        void keyPressedMenu();
        WPARAM wParam;


    protected:

    private:
        bool* keys;
};

#endif // _INPUTS_H
