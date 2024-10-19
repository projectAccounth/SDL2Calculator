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

const char* emptyStr = "";

int main(int argc, char* argv[]) {
    
    Main mainClass;

    Window programWindow;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    TTF_Font *mainFont = TTF_OpenFont("./res/fonts/micross.ttf", 30);

    std::cout << TTF_GetError() << "\n";

    mainWindow = programWindow.createWindow("Program", WINDOW_WIDTH, WINDOW_HEIGHT);

    mainRenderer = programWindow.createRenderer(mainWindow);

    textBox displayBox(SDL_Rect{20, 20, 360, 70}, SDL_Color{188, 188, 188, 255}, "", SDL_Color{0, 0, 0, 255}, mainFont);
    //textBox prevInputBox(SDL_Rect{WINDOW_WIDTH - 20 - 80, 20, 80, 70}, SDL_Color{188, 188, 188, 255}, "", SDL_Color{0, 0, 0, 255}, mainFont);

    if (mainFont == nullptr) {
        std::cout << SDL_GetError();
        return -1;
    }

    std::cout << SDL_GetError() << "\n";

    // First row numeric buttons
    textButton num1(20, 120, 45, 45,
                    defaultButtonColor, "1", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num2(2 * 20 + 45, 120, 45, 45,
                    defaultButtonColor, "2", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num3(3 * 20 + 45 * 2, 120, 45, 45,
                    defaultButtonColor, "3", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // Second row

    textButton num4(20, 120 + 45 + 20, 45, 45,
                    defaultButtonColor, "4", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num5(2 * 20 + 45, 120 + 45 + 20, 45, 45,
                    defaultButtonColor, "5", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num6(3 * 20 + 45 * 2, 120 + 45 + 20, 45, 45,
                    defaultButtonColor, "6", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // Third row

    textButton num7(20, 120 + 45 * 2 + 20 * 2, 45, 45,
                    defaultButtonColor, "7", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num8(2 * 20 + 45, 120 + 45 * 2 + 20 * 2, 45, 45,
                    defaultButtonColor, "8", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton num9(3 * 20 + 45 * 2, 120 + 45 * 2 + 20 * 2, 45, 45,
                    defaultButtonColor, "9", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // Fourth row function + operation buttons

    textButton backSpace(20, 120 + (45 + 20) * 3, 77, 45,
                         defaultButtonColor, "Del", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton negate(20 * 2 + 77, 120 + (45 + 20) * 3, 78, 45,
                         defaultButtonColor, "+/-", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // Numeric operation buttons

    textButton add(WINDOW_WIDTH - 20 - 45, 120, 45, 45,
                    defaultButtonColor, "+", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton sub(WINDOW_WIDTH - 20 - 45, 120 + (45 + 20), 45, 45,
                    defaultButtonColor, "-", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton mul(WINDOW_WIDTH - 20 - 45, 120 + (45 + 20) * 2, 45, 45,
                    defaultButtonColor, "x", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);
    textButton div(WINDOW_WIDTH - 20 - 45, 120 + (45 + 20) * 3, 45, 45,
                    defaultButtonColor, "/", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    num1.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("1");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num2.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("2");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num3.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("3");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num4.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("4");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num5.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("5");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num6.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("6");
        displayBox.text = strdup(placeholderString.c_str());
    });   

    num7.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("7");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num8.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("8");
        displayBox.text = strdup(placeholderString.c_str());
    });

    num9.setAction([&]() {
        std::string placeholderString = displayBox.text;
        placeholderString.append("9");
        displayBox.text = strdup(placeholderString.c_str());
    });

    backSpace.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            placeholderString.pop_back();
            displayBox.text = strdup(placeholderString.c_str());
        }
    });


    numericButtons.addButton(num1);
    numericButtons.addButton(num2);
    numericButtons.addButton(num3);
    numericButtons.addButton(num4);
    numericButtons.addButton(num5);
    numericButtons.addButton(num6);
    numericButtons.addButton(num7);
    numericButtons.addButton(num8);
    numericButtons.addButton(num9);

    functionButtons.addButton(backSpace);


    operationButtons.addButton(add);
    operationButtons.addButton(sub);
    operationButtons.addButton(mul);
    operationButtons.addButton(div);
    operationButtons.addButton(negate);

    numericButtons.loadAllText(mainRenderer);
    functionButtons.loadAllText(mainRenderer);
    operationButtons.loadAllText(mainRenderer);

    std::cout << SDL_GetError() << "\n";

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
		while (SDL_PollEvent(&event)) {
			mainClass.processEvent(mainRenderer, mainWindow, event, isRunning, mainFont);
            numericButtons.handleEvents(event);
			operationButtons.handleEvents(event);
			functionButtons.handleEvents(event);
		}
        // main color of the screen   
        SDL_SetRenderDrawColor(mainRenderer, 128, 128, 128, 255);

        SDL_RenderClear(mainRenderer);
        // whatever that needs to be rendered go between RenderClear and RenderPresent

        displayBox.render(mainRenderer);
        //prevInputBox.render(mainRenderer);

        numericButtons.renderAll(mainRenderer);
        functionButtons.renderAll(mainRenderer);
        operationButtons.renderAll(mainRenderer);

        SDL_RenderPresent(mainRenderer);
    }
    
    mainClass.onQuit(mainRenderer, mainWindow, mainFont);

    return 0;
}