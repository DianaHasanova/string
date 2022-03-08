//
// Created by Дианочка on 27.02.2022.
//

#include "string_.h"
#include <stdio.h>
#include <memory.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && *begin == ' ')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && *begin != ' ')
        begin++;

    return begin;
}

char *findNonSpaceReverse_(char *str) {
    return findNonSpaceReverse(str + strlen_(str) - 1, str - 1);
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin == ' ')
        rbegin--;

    return rbegin;
}

char *findSpaceReverse_(char *str) {
    return findSpaceReverse(str + strlen_(str) - 1, str - 1);
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin != ' ')
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(char)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

int isNotAGap(int i) {
    return i != ' ';
}

char *getEndOfString(char *str) {
    return str + strlen_(str) ;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}
