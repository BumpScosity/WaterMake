#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

void incVar(Line *line, const char *startDelimiter, const char *endDelimiter, const char *variableNameStart);
void callFunc(Data* data, const char *callKeyword, int i);
void other(Data *data, int i);
void callIf(const char *callif[5], const char *line, Data* data);

void parser(Data* data);

#endif // PARSER_H