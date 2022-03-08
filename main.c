#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string/tasks/string_.h"
#include <ctype.h>

void test_strlen_emptyLine() {
    char *str = "";
    assert(strlen_(str) == 0);
}

void test_strlen_() {
    char *str = "rgt4 $";
    assert(strlen_(str) == 6);
}

void test_find_hasAnElement() {
    char *str = "uhhh 7 % ";
    assert(find(str, str + 3, ' ') == str + 3);
}

void test_find_notElement_1() {
    char *str = "uhhh 7 % ";
    assert(find(str, str + 8, 'f') == str + 8);
}

void test_find_notElement_2() {
    char *str = "uhhh 7 % ";
    assert(find(str, str + 4, '%') == str + 4);
}

void test_findNonSpace() {
    char *str = "  uhhh 7 % ";
    assert(findNonSpace(str) == str + 2);
}

void test_findNonSpace_stringOfSpaces() {
    char *str = "  ";
    assert(findNonSpace(str) == str + 2);
}

void test_findSpace_stringOfSpaces() {
    char *str = "   ";
    assert(findSpace(str) == str);
}

void test_findSpace() {
    char *str = "sthh  u ";
    assert(findSpace(str) == str + 4);
}

void test_findSpace_stringWithoutSpaces() {
    char *str = "tggyuh";
    assert(findSpace(str) == str + 6);
}

void test_findNonSpaceReverse_noSpaces() {
    char *str = "tgg";
    assert(findNonSpaceReverse_(str) == str + 2);
}

void test_findNonSpaceReverse_hasMultipleSpaces() {
    char *str = "t g g ";
    assert(findNonSpaceReverse_(str) == str + 4);
}

void test_findNonSpaceReverse_consistsOfSpaces() {
    char *str = " ";
    assert(findNonSpaceReverse_(str) == str - 1);
}

void test_findSpaceReverse_noSpaces() {
    char *str = "abcde";
    assert(findSpaceReverse_(str) == str - 1);
}

void test_findSpaceReverse_hasSpaces() {
    char *str = "ab de";
    assert(findSpaceReverse_(str) == str + 2);
}

void test_strcmp() {
    char *lhs = "abc";
    char *rhs = "abd";
    assert(strcmp(lhs, rhs) == -1);
}

void test_copy() {
    char *str1 = "7ggh 87";
    char *str2 = malloc(10);
    assert(copy(str1 + 2, str1 + 6, str2) == str2 + 4);
    assert(strcmp(str2, "gh 8") == 0);
    free(str2);
}

void test_copyIf() {
    char *str1 = "7g gh 87 u";
    char *str2 = malloc(10);
    assert(copyIf(str1, str1 + 9, str2, isNotAGap) == str2 + 6);
    assert(strcmp(str2, "7ggh87") == 0);
}

void test_copyIfReverse() {
    char *str1 = "7g gh 87 u";
    char *str2 = malloc(10);
    assert(copyIfReverse(str1 + 9, str1, str2, isNotAGap) == str2 + 6);
    assert(strcmp(str2, "u78hgg") == 0);
}

void test_getEndOfString() {
    char *str = "a  w d ef";
    assert(getEndOfString(str) == str + 9);
}

void testLib() {
    test_strlen_emptyLine();
    test_strlen_();
    test_find_notElement_1();
    test_find_notElement_2();
    test_find_hasAnElement();
    test_findNonSpace();
    test_findNonSpace_stringOfSpaces();
    test_findSpace_stringOfSpaces();
    test_findSpace();
    test_findSpace_stringWithoutSpaces();
    test_findNonSpaceReverse_noSpaces();
    test_findNonSpaceReverse_hasMultipleSpaces();
    test_findNonSpaceReverse_consistsOfSpaces();
    test_findSpaceReverse_noSpaces();
    test_findSpaceReverse_hasSpaces();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_getEndOfString();
}


//                                 Task


#define ASSERT_STRING(expected, got) assertString(expected,got, \
 __FILE__ , __FUNCTION__ , __LINE__ )

//task 1

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';

}

void test_removeNonLetters() {
    char str[] = "a  w d ef78 87#";
    removeNonLetters(str);
    ASSERT_STRING("awdef7887#", str);
}


//task2


void test_tasks() {
    test_removeNonLetters();
}


int main() {
    testLib();
    test_tasks();

    return 0;
}
