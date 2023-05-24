#include "../headers/parser.h"
#include "../headers/variable.h"
#include "../headers/lexer.h"

#include <stdio.h>
#include <string.h>

void incVar(Line *line, const char *startDelimiter, const char *endDelimiter, const char *variableNameStart) {
    variableNameStart += strlen(startDelimiter);
    const char* variableNameEnd = strchr(variableNameStart, *endDelimiter);

    if (variableNameEnd != NULL) {
        size_t length = variableNameEnd - variableNameStart;
        if (length > 0) {
            char variableName[length + 1];
            strncpy(variableName, variableNameStart, length);
            variableName[length] = '\0';

            int_t *var = getInt(variableName);
            var->value++;
        } else {
            printf("Variable name is missing.\n");
        }
    } else {
        printf("Invalid input format.\n");
    }
} 