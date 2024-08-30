#include "../include/main.h"
#include "../include/button.h"
#include "../include/window.h"
#include "../include/frameEvents.h"

using namespace mainProgram;

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