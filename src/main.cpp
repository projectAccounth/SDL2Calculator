#include "../include/main.h"
#include "../include/mainHandling.h"
#include "../include/button.h"
#include "../include/window.h"
#include "../include/frameEvents.h"
#include "../include/textBox.h"
#include "../include/button.h"
#include "../include/buttonMgr.h"

using namespace mainProgram;

SDL_Window *mainWindow = NULL;
SDL_Renderer *mainRenderer = NULL;

// Default button color and hovered button color, of course.
SDL_Color defaultButtonColor = {188, 188, 188, 255};
SDL_Color hoveredButtonColor = {155, 155, 155, 255};




// corresponding button lists for those button types
    buttonManager numericButtons;
    buttonManager operationButtons;
    buttonManager functionButtons;

int main(int argc, char* argv[]) {
    
    Main mainClass;

    Window programWindow;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    TTF_Font *mainFont = TTF_OpenFont("./res/fonts/Amiko-Regular.ttf", 25);

    mainWindow = programWindow.createWindow("Program", WINDOW_WIDTH, WINDOW_HEIGHT);

    mainRenderer = programWindow.createRenderer(mainWindow);

    textBox displayBox(SDL_Rect{20, 20, 275, 70}, SDL_Color{188, 188, 188, 255}, "Hello World!", SDL_Color{0, 0, 0, 255}, mainFont );
    textBox prevInputBox(SDL_Rect{WINDOW_WIDTH - 20 - 80, 20, 80, 70}, SDL_Color{188, 188, 188, 255}, "h", SDL_Color{0, 0, 0, 255}, mainFont );

    if (mainFont == nullptr) {
        std::cout << SDL_GetError();
        return -1;
    }

    std::cout << SDL_GetError() << "\n";

    textButton num1(20, 200, 30, 30, defaultButtonColor, std::string("1"), SDL_Color {0, 0, 0, 255}, mainFont, textAlign::CENTER, hoveredButtonColor);

    numericButtons.addButton(num1);


    numericButtons.loadAllText(mainRenderer);
    functionButtons.loadAllText(mainRenderer);
    operationButtons.loadAllText(mainRenderer);

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
		while (SDL_PollEvent(&event)) {
			mainClass.processEvent(mainRenderer, mainWindow, event, isRunning, numericButtons, operationButtons, functionButtons);			
		}
        programWindow.renderWindow(numericButtons, operationButtons, functionButtons, mainRenderer,
                                   displayBox, prevInputBox);
    }
    
    mainClass.onQuit(mainRenderer, mainWindow);

    return 0;
}