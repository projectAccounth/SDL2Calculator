#include "../include/main.h"
#include "../include/button.h"
#include "../include/window.h"
#include "../include/frameEvents.h"
#include "../include/textBox.h"
#include "../include/button.h"
#include "../include/buttonMgr.h"

using namespace mainProgram;

Color3 textColor = {0, 0, 0, 255};
Color3 boxColor = {188, 188, 188, 255};

// Default button color and hovered button color, of course.
SDL_Color defaultButtonColor = {188, 188, 188, 255};
SDL_Color hoveredButtonColor = {155, 155, 155, 255};

// corresponding button lists for those button types
buttonManager numericButtons;
buttonManager operationButtons;
buttonManager functionButtons;

// main display box for the results and the inputs, etc.
textBox_t displayBox = {
    .textBox_Box = new SDL_Rect {20, 20, 275, 70},
    .boxColor = Color3ToSDLColor(boxColor),
    .text = "Hello World!"
};

// the box which will show the previous inputs.
textBox_t prevInputBox = {
    .textBox_Box = new SDL_Rect {WINDOW_WIDTH - 20 - 80, 20, 80, 70},
    .boxColor = Color3ToSDLColor(boxColor),
    .text = "h"
};



int main(int argc, char* argv[]) {

    // std::cout << TTF_GetError() << " Line 10, main.cpp\n";

    Main mainClass;

    Window programWindow;

    programWindow.initializeProgram();

    bool isRunning = true;

    while (isRunning) {
        mainClass.processEvent();
        programWindow.renderWindow();
    }

    mainClass.onQuit();

    return 0;
}