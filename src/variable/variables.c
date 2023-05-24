#include "../headers/variable.h"

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool_t bools[] = {
    {"bool1", false},
    {"bool2", false},
    {"bool3", false}
};

int_t ints[] = {
    {"int1", 0},
    {"int2", 0},
    {"int3", 0}
};

bool_t *getBool(const char *name) {
    for (int i = 0; i < sizeof(bool_t) / sizeof(bools[0]); i++) {
        if (strncmp(name, bools[i].name, strlen(bools[i].name)) == 0) {
            return &bools[i];
        }
    }
    return NULL;
}

int_t *getInt(const char *name) {
    for (int i = 0; i < sizeof(int_t) / sizeof(ints[0]); i++) {
        if (strncmp(name, ints[i].name, strlen(ints[i].name)) == 0) {
            return &ints[i];
        }
    }
    return NULL;
}