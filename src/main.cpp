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

// corresponding button lists for those button types
    buttonManager numericButtons;
    buttonManager operationButtons;
    buttonManager functionButtons;

int main(int argc, char* argv[]) {
    
    Main mainClass;

    Window programWindow;

    programWindow.initializeProgram();

    TTF_Font *mainFont = TTF_OpenFont("./res/fonts/Amiko-Regular.ttf", 25);

    textButton num1(20, 100, 30, 30, defaultButtonColor, std::string("1"), SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    numericButtons.addButton(num1);


    numericButtons.loadAllText(mainRenderer);
    functionButtons.loadAllText(mainRenderer);
    operationButtons.loadAllText(mainRenderer);

    bool isRunning = true;

    while (isRunning) {
        SDL_Event event;
		while (SDL_PollEvent(&event)) {
			mainClass.processEvent(event, isRunning, numericButtons, operationButtons, functionButtons);			
		}
        numericButtons.renderAll(mainRenderer);
		operationButtons.renderAll(mainRenderer);
		functionButtons.renderAll(mainRenderer);
        programWindow.renderWindow();
    }
    
    mainClass.onQuit();

    return 0;
}