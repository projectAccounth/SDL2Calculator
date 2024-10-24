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


int main(int argc, char* argv[]) {

    std::cout << std::defaultfloat;
    std::cout << std::setprecision(8);

    long double temporaryValue1 = NULL, temporaryValue2 = NULL;

    CURRENT_FUNCTION currentFunction = NONE;
    CURRENT_OPERATION currentOperation = NOOP;
    
    Main mainClass;

    Window programWindow;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    TTF_Font *mainFont = TTF_OpenFont("./res/fonts/micross.ttf", 30);

    std::cout << TTF_GetError() << "\n";

    mainWindow = programWindow.createWindow("Program", WINDOW_WIDTH, WINDOW_HEIGHT);

    mainRenderer = programWindow.createRenderer(mainWindow);

    textBox displayBox(SDL_Rect{20, 20, 315, 70}, SDL_Color{188, 188, 188, 255}, "", SDL_Color{0, 0, 0, 255}, mainFont);
    textBox currentOpBox(SDL_Rect{315 - 12, 20 + 10, 20, 20}, SDL_Color{188, 188, 188, 0}, "N", SDL_Color{0, 0, 0, 255}, mainFont);
    //textBox prevInputBox(SDL_Rect{WINDOW_WIDTH - 20 - 80, 20, 80, 70}, SDL_Color{188, 188, 188, 255}, "", SDL_Color{0, 0, 0, 255}, mainFont);

    if (mainFont == nullptr) {
        std::cout << SDL_GetError();
        return -1;
    }

    // functions for binding
    std::function<void(std::string)> numericButtonHandling = [&](std::string str) {
        std::string placeholderString = displayBox.text;
        placeholderString.append(str);
        displayBox.text = strdup(placeholderString.c_str());
    };

    std::function<void(CURRENT_OPERATION)> operationButtonHandling = [&](CURRENT_OPERATION op) {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            try {
                std::stold(placeholderString);
            }
            catch (const std::invalid_argument &e) {
                displayBox.text = "SYNTAX ERROR";
                numericButtons.toggleAllActive(false);
                functionButtons.toggleAllActive(false);
                operationButtons.toggleAllActive(false);
                return;
            }

            if (temporaryValue1 != NULL) {
                switch(op) {
                    case NOOP:
                        break;
                    case ADD: {
                        temporaryValue2 = temporaryValue1 + std::stold(placeholderString);
                        currentOperation = NOOP;
                        displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                        temporaryValue1 = NULL;
                        temporaryValue2 = NULL;
                        return;
                    }
                    case SUB: {
                        temporaryValue2 = temporaryValue1 - std::stold(placeholderString);
                        currentOperation = NOOP;
                        displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                        temporaryValue1 = NULL;
                        temporaryValue2 = NULL;
                        return;
                    }
                    case MUL: {
                        temporaryValue2 = temporaryValue1 * std::stold(placeholderString);
                        currentOperation = NOOP;
                        displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                        temporaryValue1 = NULL;
                        temporaryValue2 = NULL;
                        return;
                    }
                    case DIV: {
                        temporaryValue2 = temporaryValue1 / std::stold(placeholderString);
                        currentOperation = NOOP;
                        displayBox.text = strdup(std::to_string(temporaryValue2).c_str());
                        temporaryValue1 = NULL;
                        temporaryValue2 = NULL;
                        return;
                    }
                }
                currentOpBox.text = "N";
            }
            currentOperation = op;
            
            switch (op) {
                case NOOP:
                    currentOpBox.text = "N";
                    break;
                case ADD:
                    currentOpBox.text = "+";
                    break;
                case SUB:
                    currentOpBox.text = "-";
                    break;
                case MUL:
                    currentOpBox.text = "*";
                    break;
                case DIV:
                    currentOpBox.text = "/";
                    break;
            }

            if (temporaryValue1 == NULL) {
                temporaryValue1 = std::stold(placeholderString);
                std::cout << "Assigned " << temporaryValue1 << "\n";
            }
        }
        displayBox.text = "";
    };

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

    // Additional buttons

    textButton point(3 * 20 + 45 * 2 + 60, 120 + (45 + 20) * 2, 60, 45,
                    defaultButtonColor, ".", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

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
    
    textButton equal(3 * 20 + 45 * 2 + 60, 120 + (45 + 20) * 3, 60, 45,
                    defaultButtonColor, "=", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    // CLEAR && ALL_CLEAR (C && AC)

    textButton clear(3 * 20 + 45 * 2 + 60, 120, 60, 45,
                    defaultButtonColor, "C", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    textButton allClear(3 * 20 + 45 * 2 + 60, 120 + 45 + 20, 60, 45,
                    defaultButtonColor, "AC", SDL_Color {0, 0, 0, 255}, mainFont, CENTER, hoveredButtonColor);

    num1.setAction([&]() { numericButtonHandling("1"); });
    num2.setAction([&]() { numericButtonHandling("2"); });
    num3.setAction([&]() { numericButtonHandling("3"); });
    num4.setAction([&]() { numericButtonHandling("4"); });
    num5.setAction([&]() { numericButtonHandling("5"); });
    num6.setAction([&]() { numericButtonHandling("6"); });
    num7.setAction([&]() { numericButtonHandling("7"); });
    num8.setAction([&]() { numericButtonHandling("8"); });
    num9.setAction([&]() { numericButtonHandling("9"); });
    point.setAction([&]() { numericButtonHandling("."); });

    backSpace.setAction([&]() {
        std::string placeholderString = displayBox.text;
        if (!placeholderString.empty()) {
            placeholderString.pop_back();
            displayBox.text = strdup(placeholderString.c_str());
        }
    });

    allClear.setAction([&]() {
        displayBox.text = "";
        temporaryValue1 = NULL;
        temporaryValue2 = NULL;
        numericButtons.toggleAllActive(true);
        functionButtons.toggleAllActive(true);
        operationButtons.toggleAllActive(true);
        specialButtons.toggleAllActive(true);
    });

    clear.setAction([&]() {
        displayBox.text = "";
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

    add.buttonAction = std::bind(operationButtonHandling, ADD);
    sub.buttonAction = std::bind(operationButtonHandling, SUB);
    mul.buttonAction = std::bind(operationButtonHandling, MUL);
    div.buttonAction = std::bind(operationButtonHandling, DIV);

    equal.setAction([&]() {
        std::string placeholderString = displayBox.text;       
        if (temporaryValue1 == NULL || placeholderString == "") {
            std::cout << "Temp == NULL || BlankStr\n";
            return;
        }
        long double placeholderNum;
        try {
            placeholderNum = std::stold(placeholderString);
        } catch (const std::invalid_argument &e) {
            displayBox.text = "SYNTAX ERROR";
            numericButtons.toggleAllActive(false);
            functionButtons.toggleAllActive(false);
            operationButtons.toggleAllActive(false);
            return;
        }
        switch (currentOperation) {
            case NOOP:
                break;
            case ADD: {
                currentOperation = NOOP;
                temporaryValue1 += placeholderNum;
                break;
            }
            case SUB: {
                currentOperation = NOOP;
                temporaryValue1 -= placeholderNum;
                break;
            }
            case MUL: {
                currentOperation = NOOP;
                temporaryValue1 *= placeholderNum;
                break;
            }
            case DIV: {
                currentOperation = NOOP;
                temporaryValue1 /= placeholderNum ;
                break;
            }
        }
        switch (currentFunction) {
            case NONE:
                break;
        }
        displayBox.text = std::to_string(temporaryValue1);
        currentOpBox.text = "N";
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
    numericButtons.addButton(point);

    functionButtons.addButton(backSpace);
    functionButtons.addButton(clear);
    functionButtons.addButton(equal);

    specialButtons.addButton(allClear);

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
			isRunning = mainClass.processEvent(event);
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
        currentOpBox.render(mainRenderer);
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