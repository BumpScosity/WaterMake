#include "../headers/parser.h"
#include "../headers/lexer.h"
#include "../headers/variable.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void parser (Data* data) {
    const char *callKeyword = "$(call ";
    const char *inc[2] = {"inc(", ")"};
    const char *callIfKeyword[5] = {"if(", "$(call ", "=", ",", ")"};

    Line* lines = data->lines;
    Function* functions = data->functions;
    int numFunctions = data->numFunctions;
    int numLines = data->numLines;

    for (int i = 0; i < numLines; i++) {
        const char* variableNameStart = strstr(lines[i].lineData, inc[0]);
        const char* equalsSignPos = strchr(lines[i].lineData, *callIfKeyword[2]);
        const char* commaPos = strchr(lines[i].lineData, *callIfKeyword[3]);
        if (strncmp(lines[i].lineData, callKeyword, strlen(callKeyword)) == 0) {
            printf("4");
            callFunc(data, callKeyword, i);
        }
        else if (variableNameStart != NULL) {
            incVar(lines, inc[0], inc[1], variableNameStart);
        }
        else if (equalsSignPos < commaPos) {
            callIf(callIfKeyword, lines[i].lineData, data);
        }
        else {
            other(data, i);
        }
    }

    free(data);
}