#ifndef FUNCTION_H
#define FUNCTION_H

#include "lexer.h"

Function* findFunctionByName(Function* functions, int numFunctions, const char* functionName);
void executeFunction(Function *functions, int numFunctions, Line *lines, char *name);

#endif // FUNCTION_H
