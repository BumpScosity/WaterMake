#include "../headers/parser.h"
#include "../headers/lexer.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void parser (Data* data) {
    const char *callKeyword = "$(call ";

    Line* lines = data->lines;
    Function* functions = data->functions;
    int numFunctions = data->numFunctions;
    int numLines = data->numLines;

    for (int i = 0; i < numLines; i++) {
        if (strncmp(lines[i].lineData, callKeyword, strlen(callKeyword)) == 0) {
            callFunc(data, callKeyword, i);
        }
        else {
            other(data, i);
        }
    }

    free(data);
}