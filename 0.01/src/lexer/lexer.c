#include "../headers/lexer.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef __linux__
#define strdupf strdup
#elif _WIN32
#define strdupf _strdup
#elif _WIN64
#define strdupf _strdup
#else
#define strdupf strdup
#endif

Data *readLines(const char* filename, int* lineCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    Line* lines = NULL;
    Function* functions = NULL;
    char buffer[256];
    int count = 0;
    int functionLineCount = 0;
    int lineNumber = 1;
    int currentFunction = 0;
    int numFunctions = 0;
    int _startLine = 0;
    int _endLine = 0;
    bool inFunction = false;

    const char* defineKeyword = "define";
    const char* endefKeyword = "endef";
    const char* equalsPos =  strchr(buffer, '=');

    while (fgets(buffer, sizeof(buffer), file)) {
        // Ignore lines starting with //
        if (buffer[0] == '/' && buffer[1] == '/')
            continue;

        if (strcmp(buffer, "_start:\n") == 0) {
            _startLine = lineNumber;
            lineNumber++;
            continue;
        }

        if (strcmp(buffer, "_end\n") == 0) {
            _endLine = lineNumber;
            lineNumber++;
            continue;
        }

        if (strncmp(buffer, defineKeyword, strlen(defineKeyword)) == 0) {
            // Find the position of the space character after "define"
            const char* spacePos = strchr(buffer, ' ');
            if (spacePos != NULL) {
                // Extract the second part after "define"
                const char* secondPart = spacePos + 1;
                inFunction = true;
                functions = (Function*)realloc(functions, (numFunctions + 1) * sizeof(Function));
                functions[currentFunction].functionStart = lineNumber + 1;
                functions[currentFunction].functionName = strdupf(secondPart);
            } else {
                printf("Invalid line format.\n");
            }
        }

        if (inFunction && strncmp(buffer, endefKeyword, strlen(endefKeyword)) == 0) {
            inFunction = false;
            functions[currentFunction].functionEnd = lineNumber - 2;
            functions[currentFunction].numLines = functionLineCount;
            functionLineCount = 0;
            currentFunction++;
            numFunctions++;
        }

        Line* newLine = (Line*)realloc(lines, (count + 1) * sizeof(Line));
        if (newLine == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            free(lines);
            free(functions);
            return NULL;
        }
        lines = newLine;

        lines[count].lineData = strdupf(buffer); // Store the line data
        lines[count].lineNumber = lineNumber; // Store the line number

        count++;
        lineNumber++;

        if (inFunction == true && strcmp(buffer, "endef\n") != 0) {
            functionLineCount++;
        }
    }

    fclose(file);
    *lineCount = count;
    Data* returnData = malloc(sizeof(Data));
    returnData->lines = lines;
    returnData->functions = functions;
    returnData->numFunctions = numFunctions;
    returnData->numLines = count;
    returnData->_start = _startLine;
    returnData->_end = _endLine;
    return returnData;
}
