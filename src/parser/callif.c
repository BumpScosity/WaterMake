
#include "../headers/parser.h"
#include "../headers/variable.h"
#include "../headers/function.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void callIf(const char *callif[5], const char *line, Data *data) {
    Line* lines = data->lines;
    Function* functions = data->functions;
    int numFunctions = data->numFunctions;

    free(data);

    const char* ifStart = strstr(line, callif[0]);
    const char* callStart = strstr(line, callif[1]);
    const char* equalsSignPos = strchr(line, *callif[2]);
    const char* commaPos = strchr(line, *callif[3]);
    const char* closingParenPos = strchr(line, *callif[4]);

    size_t variableNameLength = equalsSignPos - (ifStart + strlen(callif[0]));
    char variableName[variableNameLength++];
    strncpy(variableName, ifStart + strlen(callif[0]), variableNameLength);
    variableName[variableNameLength] = '\0';

    char valueStr[256];
    size_t valueLength = commaPos - (equalsSignPos + 1);
    strncpy(valueStr, equalsSignPos + 1, valueLength);
    valueStr[valueLength] = '\0';
    int value;

    if (strcmp(valueStr, "true") || strcmp(valueStr, "True")) {
        value = 1;
    }
    else if (strcmp(valueStr, "false") || strcmp(valueStr, "False")) {
        value = 1;
    }
    else {
        value = atoi(valueStr);
    }

    const char* functionNameStart = callStart + strlen(callif[1]);
    size_t functionNameLength = closingParenPos - functionNameStart;
    char functionName[functionNameLength];
    strncpy(functionName, functionNameStart, functionNameLength);
    functionName[functionNameLength] = '\0';
    strcat(functionName, "\n"); // Add newline character

    if (strncmp(variableName, "int", strlen("int")) == 0) {
        int_t var = *getInt(variableName);
        if (value == var.value) {
            executeFunction(functions, numFunctions, lines, functionName);
        } 
    }
    else if (strncmp(variableName, "bool", strlen("bool")) == 0) {
        bool_t var = *getBool(variableName);
        if (value == var.value) {
            executeFunction(functions, numFunctions, lines, functionName);
        }
    }
    else {
        printf("Error: Variable not valid");
    }
}