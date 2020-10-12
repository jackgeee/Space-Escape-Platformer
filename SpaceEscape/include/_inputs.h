#ifndef _INPUTS_H
#define _INPUTS_H

#include<windows.h>
#include<_Model.h>
#include<_parallax.h>
#include<_player.h>
#include<_objects.h>

class _inputs
{
    public:
        _inputs();
        virtual ~_inputs();

        void keyPressed(_objects *, int,int);   // model handling
        void keyPressed(_player *, int);   // model handling
        void keyUp(_player *);   // model handling
        void keyEnv(_parallax *,float, int); // handles the background movement
        void keyObj(_objects *, int );
        void keyUp(_objects *, int );
        void keyUp(_parallax*);
        void keyUp(_objects*);
        void keyUp();

 bool isKeyPressed(int);
        void mouseEventDown(_Model *,double ,double);
        void mouseEventUp();
        void mouseWheel(_Model *,double);
        void mouseMove(_Model *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Rotate;

        WPARAM wParam;


    protected:

    private:
        bool* keys;

};

#endif // _INPUTS_H




