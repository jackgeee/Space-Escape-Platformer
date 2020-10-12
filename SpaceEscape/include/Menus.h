#ifndef MENUS_H
#define MENUS_H
#include <_textureloader.h>
#include <windows.h>
#include <_inputs.h>
#include <_timer.h>



class Menus
{
    public:
        Menus();
        virtual ~Menus();

        void mainMenuInit(char*);
        void landingMenuInit(char*);
        void pauseMenuInit(char*);
        void helpMenuInit(char*);
        void creditMenuInit(char*);
        void gameOverMenuInit(char*);
        void victoryMenuInit(char*);
        void drawMenus(float, float);
        void drawButtons();
        void menuInputs(_inputs*, bool*, int&);



        _textureLoader *butTexture = new _textureLoader();
        _textureLoader *pauseTexture = new _textureLoader();
        _textureLoader *landTexture = new _textureLoader();
       _textureLoader *helpTexture = new _textureLoader();
        _textureLoader *creditTexture = new _textureLoader();
        _textureLoader *gameOverTexture = new _textureLoader();
        _textureLoader *victoryTexture = new _textureLoader();
         WPARAM wParam;
        bool inMenu;
        string menuName;

    protected:

    private:
        _textureLoader *mainTexture;
};

#endif // MENUS_H
