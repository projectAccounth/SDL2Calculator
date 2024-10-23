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
buttonManager specialButtons;

const char* emptyStr = "";

int main(int argc, char* argv[]) {
    
    Main mainClass;

    Window programWindow;

    long double temporaryValue1 = NULL, temporaryValue2 = NULL;

    CURRENT_FUNCTION currentFunction = NONE;

    CURRENT_OPERATION currentOperation = NOOP;

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

    // EQUAL
    
    textButton equal(WINDOW_WIDTH - 20 - 70, 120 + (45 + 20) * 4, 70, 45,
                        defaultButtonColor, "=", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // CLEAR && ALL_CLEAR (C && AC)

    textButton clear();

    textButton allClear();

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

    negate.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty() && currentFunction == NONE) {
            try {
                if (placeholderString.at(0) == '-') {
                    placeholderString.erase(0,1);
                } else {
                    placeholderString.insert(0, 1, '-');
                }
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Out of range error: " << e.what() << std::endl;
            }
            displayBox.text = strdup(placeholderString.c_str());
        }
    });

    sub.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            try {
                std::stold(placeholderString);
            }
            catch (const std::exception &e) {
                return;
            }
            
            if (currentOperation == SUB && temporaryValue1 != 0) {
                temporaryValue2 = temporaryValue1 + std::stold(placeholderString);
                currentOperation = NOOP;
                displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                temporaryValue1 = temporaryValue2;
                temporaryValue2 = 0;
                return;
            }

            currentOperation = SUB;

            if (temporaryValue1 == 0)
                temporaryValue1 = std::stold(placeholderString);
        }
        displayBox.text = "";
    });

    mul.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            try {
                std::stold(placeholderString);
            }
            catch (const std::exception &e) {
                return;
            }
            
            if (currentOperation == MUL && temporaryValue1 != 0) {
                temporaryValue2 = temporaryValue1 + std::stold(placeholderString);
                currentOperation = NOOP;
                displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                temporaryValue1 = temporaryValue2;
                temporaryValue2 = 0;
                return;
            }

            currentOperation = MUL;

            if (temporaryValue1 == 0)
                temporaryValue1 = std::stold(placeholderString);
        }
        displayBox.text = "";
    });

    div.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            try {
                std::stold(placeholderString);
            }
            catch (const std::exception &e) {
                return;
            }
            
            if (currentOperation == DIV && temporaryValue1 != 0) {
                temporaryValue2 = temporaryValue1 + std::stold(placeholderString);
                currentOperation = NOOP;
                displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                temporaryValue1 = temporaryValue2;
                temporaryValue2 = 0;
                return;
            }

            currentOperation = DIV;

            if (temporaryValue1 == 0)
                temporaryValue1 = std::stold(placeholderString);
        }
        displayBox.text = "";
    });

    add.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            try {
                std::stold(placeholderString);
            }
            catch (const std::exception &e) {
                return;
            }
            
            if (currentOperation == ADD && temporaryValue1 != 0) {
                temporaryValue2 = temporaryValue1 + std::stold(placeholderString);
                currentOperation = NOOP;
                displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                temporaryValue1 = temporaryValue2;
                temporaryValue2 = 0;
                return;
            }

            currentOperation = ADD;

            if (temporaryValue1 == 0)
                temporaryValue1 = std::stold(placeholderString);
        }
        displayBox.text = "";
    });

    equal.setAction([&]() {
        std::string placeholderString = displayBox.text;
        long double placeholderNum = std::stold(placeholderString);
        if (temporaryValue1 == NULL) {
            return;
        }
        switch (currentOperation) {
            case NOOP:
                break;
            case ADD: {
                currentOperation = NOOP;
                placeholderNum += temporaryValue1;
                break;
            }
            case SUB: {
                currentOperation = NOOP;
                placeholderNum -= temporaryValue1;
                break;
            }
            case MUL: {
                currentOperation = NOOP;
                placeholderNum *= temporaryValue1;
                break;
            }
            case DIV: {
                currentOperation = NOOP;
                placeholderNum /= temporaryValue1;
                break;
            }
        }
        switch (currentFunction) {
            case NONE:
                break;
        }
        displayBox.text = std::to_string(placeholderNum);
        temporaryValue1 = NULL;
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

    specialButtons.addButton(equal);

    operationButtons.addButton(add);
    operationButtons.addButton(sub);
    operationButtons.addButton(mul);
    operationButtons.addButton(div);
    operationButtons.addButton(negate);

    numericButtons.loadAllText(mainRenderer);
    functionButtons.loadAllText(mainRenderer);
    operationButtons.loadAllText(mainRenderer);
    specialButtons.loadAllText(mainRenderer);

    std::cout << SDL_GetError() << "\n";

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
		while (SDL_PollEvent(&event)) {
			mainClass.processEvent(mainRenderer, mainWindow, event, isRunning, mainFont);
            numericButtons.handleEvents(event);
			operationButtons.handleEvents(event);
			functionButtons.handleEvents(event);
            specialButtons.handleEvents(event);
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
        specialButtons.renderAll(mainRenderer);

        SDL_RenderPresent(mainRenderer);
    }
    
    mainClass.onQuit(mainRenderer, mainWindow, mainFont);

    return 0;
}