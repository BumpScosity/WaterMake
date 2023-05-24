#ifndef LEXER_H
#define LEXER_H

typedef struct {
    char* lineData;
    int lineNumber;
} Line;

typedef struct {
    char *functionName;
    int functionStart;
    int functionEnd;
    int numLines;
} Function;

typedef struct {
    Line *lines;
    Function *functions;
    int numFunctions;
    int numLines;
    int _start;
    int _end;
} Data;

Data *readLines(const char* filename, int* lineCount);

#endif // LEXER_H