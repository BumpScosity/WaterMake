#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdbool.h>

typedef struct {
    const char *name;
    bool value;
} bool_t;

typedef struct {
    const char *name;
    int value;
} int_t;

bool_t *getBool(const char *name);
int_t *getInt(const char *name);
int compareInt(const char *name, int value);
int compareBool(const char *name, int value);

#endif // VARIABLE_H