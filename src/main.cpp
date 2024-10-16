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

    TTF_Font *mainFont = TTF_OpenFont("./res/fonts/Amiko-Regular.ttf", 30);

    std::cout << TTF_GetError() << "\n";

    mainWindow = programWindow.createWindow("Program", WINDOW_WIDTH, WINDOW_HEIGHT);

    mainRenderer = programWindow.createRenderer(mainWindow);

    textBox displayBox(SDL_Rect{20, 20, 275, 70}, SDL_Color{188, 188, 188, 255}, "Hello World!", SDL_Color{0, 0, 0, 255}, mainFont );
    textBox prevInputBox(SDL_Rect{WINDOW_WIDTH - 20 - 80, 20, 80, 70}, SDL_Color{188, 188, 188, 255}, "h", SDL_Color{0, 0, 0, 255}, mainFont );

    if (mainFont == nullptr) {
        std::cout << SDL_GetError();
        return -1;
    }

    std::cout << SDL_GetError() << "\n";

    textButton num1(20, 120, 45, 45, defaultButtonColor, "1", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num2(85, 120, 45, 45, defaultButtonColor, "2", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    num1.setAction([&]() {
        std::string placeholderString(displayBox.text);
        placeholderString.append("1");
        displayBox.text = placeholderString.c_str();
        std::cout << placeholderString << "\s" << displayBox.text << "\n";
    });

    numericButtons.addButton(num1);
    numericButtons.addButton(num2);


    numericButtons.loadAllText(mainRenderer);
    functionButtons.loadAllText(mainRenderer);
    operationButtons.loadAllText(mainRenderer);

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
		while (SDL_PollEvent(&event)) {
			mainClass.processEvent(mainRenderer, mainWindow, event, isRunning);
            numericButtons.handleEvents(event);
			operationButtons.handleEvents(event);
			functionButtons.handleEvents(event);
		}
        // main color of the screen   
        SDL_SetRenderDrawColor(mainRenderer, 128, 128, 128, 255);

        SDL_RenderClear(mainRenderer);
        // whatever that needs to be rendered go between RenderClear and RenderPresent

        displayBox.render(mainRenderer);
        prevInputBox.render(mainRenderer);

        numericButtons.renderAll(mainRenderer);
        functionButtons.renderAll(mainRenderer);
        operationButtons.renderAll(mainRenderer);

        SDL_RenderPresent(mainRenderer);
    }
    
    mainClass.onQuit(mainRenderer, mainWindow);

    return 0;
}