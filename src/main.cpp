#include "MarlinCore.h"

int main() {
    marlin.setup();
    while (true) {
        marlin.loop();
    }
}