#include "../include/main.h"
#include "../include/button.h"
#include "../include/window.h"
#include "../include/frameEvents.h"
#include "../include/textBox.h"

using namespace mainProgram;

TTF_Font* mainFont = TTF_OpenFont("../res/fonts/Amiko-Regular.ttf", 15);
Color3 textColor = {255, 255, 255, 255};
Color3 boxColor = {188, 188, 188, 255};

textBox_t displayBox = {
    .textBox_Box = new SDL_Rect {0, 0, 200, 100},
    .textFont = mainFont,
    .boxColor = Color3ToSDLColor(boxColor),
    .text = ""
};

int main() {

    class Main mainClass;

    class Window windowClass;

    windowClass.initializeProgram();

    bool isRunning = true;

    while (isRunning) {
        mainClass.processEvent();
        windowClass.renderWindow();
    }

    mainClass.onQuit();

    return 0;
}