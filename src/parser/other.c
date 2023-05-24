#include "../headers/parser.h"
#include "../headers/lexer.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void other(Data *data, int i) {
    Line line = data->lines[i];
    int _start = data->_start;
    int _end = data->_end;
    if (strcmp(line.lineData, "_end") != 0 &&
        strncmp(line.lineData, "define", strlen("define")) != 0 &&
        strncmp(line.lineData, "endef", strlen("endef")) != 0 &&
        strncmp(line.lineData, "_start", strlen("_start")) != 0) {
            if (line.lineNumber > _start && line.lineNumber < _end) {
                system(line.lineData);
            }
        }
}