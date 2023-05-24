#include "../headers/free.h"

#include <stdlib.h>

void freeLines(Line* lines, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        free(lines[i].lineData);
    }
    free(lines);
}

void freeFunctions(Function* functions, int numFunctions) {
    for (int i = 0; i < numFunctions; i++) {
        free(functions[i].functionName);
    }
    free(functions);
}