#include "../headers/lexer.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Function* findFunctionByName(Function* functions, int numFunctions, const char* functionName) {
    for (int i = 0; i < numFunctions; i++) {
        printf("Name1: %s", functions[i].functionName);
        printf("Name2: %s", functionName);
        printf("Num: %d\n", strcmp(functions[i].functionName, functionName));
        if (strcmp(functions[i].functionName, functionName) == 0) {
            return &functions[i];
        }
    }
    return NULL; // Function not found
}

void executeFunction(Function *functions, int numFunctions, Line *lines, char *name) {
    Function *function = findFunctionByName(functions, numFunctions, name);
    if (function != NULL) {
        for (int i = 0; i < function->numLines-1; i++) {
        if (i < function->functionStart || i > function->functionEnd) {
            system(lines[i+function->functionStart-3].lineData);
        }
    }
    }
}