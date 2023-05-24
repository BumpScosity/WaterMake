#include "headers/lexer.h"
#include "headers/free.h"
#include "headers/parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* filename = "Makefile";
    if (argc < 2) {
        printf("No file specified, defaulting to default name\n");
    }
    else {
        filename = argv[1];
    }

    const char* callKeyword = "$(call ";
    const char* startDelimiter = "inc(";
    const char* endDelimiter = ")";

    int lineCount = 0;
    Data* returnData = readLines(filename, &lineCount);
    Line* lines = returnData->lines;
    Function* functions = returnData->functions;
    int numFunctions = returnData->numFunctions;
    int numLines = returnData->numLines;

    if (lines != NULL) {
        parser(returnData);
        freeLines(lines, numLines);
        freeFunctions(functions, numFunctions);
    }

    free(returnData);

    return 0;
}
