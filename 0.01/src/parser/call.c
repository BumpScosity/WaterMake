#include "../headers/parser.h"
#include "../headers/function.h"

#include <string.h>
#include <stdio.h>

void callFunc(Data* data, const char *callKeyword, int i) {
    Line* lines = data->lines;
    Function* functions = data->functions;
    int numFunctions = data->numFunctions;
    int numLines = data->numLines;

    const char* closingParenthesisPos = strchr(lines[i].lineData, ')');
    if (closingParenthesisPos != NULL) {
        // Extract the function name between "$(call " and ")"
        const char* functionNameStart = lines[i].lineData + strlen(callKeyword);
        size_t functionNameLength = closingParenthesisPos - functionNameStart;
        char functionName[functionNameLength + 1];
        strncpy(functionName, functionNameStart, functionNameLength);
        functionName[functionNameLength] = '\0';
        strcat(functionName, "\n"); // Add newline character

        executeFunction(functions, numFunctions, lines, functionName);
    } else {
        printf("Invalid line format.\n");
    }
}