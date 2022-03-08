#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string/tasks/string_.h"
#include <ctype.h>
#include <string.h>

/*
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
*/

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
int areNotDuplicateCharacters(int a, int b) {
    return a != b;
}

void removeAdjacentEqualLetters(char *s) {
    char *endSource = getEndOfString(s) - 1;
    char *destination = copyIf2(s, endSource, s, areNotDuplicateCharacters);
    *destination = '\0';
}

void test_removeAdjacentEqualLetters() {
    char str[] = "a    ww d eeef7887#";
    removeAdjacentEqualLetters(str);
    ASSERT_STRING("a w d ef787", str);
}


//task3
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void task3(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word; // считываемое слово
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_task3() {
    char str[] = "a4   w3j4 d 7eeef456";
    task3(str);
    ASSERT_STRING("4a   43wj d 6547eeef", str);
}

//

void lettersToStart(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer,
                               word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void transfersLettersToTheBeginningOfAWordAndNumbersToTheEndWhileMaintainingOrder(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word; // считываемое слово
    while (getWord(beginSearch, &word)) {
        lettersToStart(word);
        beginSearch = word.end;
    }
}

void test_transfersLettersToTheBeginningOfAWordAndNumbersToTheEndWhileMaintainingOrder() {
    char str[] = "5a4   w3j4 d 7eeef456";
    transfersLettersToTheBeginningOfAWordAndNumbersToTheEndWhileMaintainingOrder(str);
    ASSERT_STRING("a54   wj34 d eeef7456", str);
}


//task4
void replaceEachDigitOfTheStringWithTheCorrespondingNumberOfSpaces(char *beginString) {
    char *_stringBuffer = malloc(MAX_STRING_SIZE + 1);
    char *endStringBuffer = copy(beginString, getEndOfString(beginString), _stringBuffer);

    while (_stringBuffer < endStringBuffer) {
        if (isdigit(*_stringBuffer)) {
            int digit = *_stringBuffer - '0';
            while (digit > 0) {
                *beginString = ' ';
                beginString++;
                digit--;
            }
        } else {
            *beginString = *_stringBuffer;
            beginString++;
        }
        _stringBuffer++;
    }
    *beginString = '\0';
}

void test_replaceEachDigitOfTheStringWithTheCorrespondingNumberOfSpaces() {
    char str[] = "A3B0C1";
    replaceEachDigitOfTheStringWithTheCorrespondingNumberOfSpaces(str);
    ASSERT_STRING("A   BC ", str);
}

void test_tasks() {
    // test_removeNonLetters();
    // test_removeAdjacentEqualLetters();
    //test_task3();
    //test_transfersLettersToTheBeginningOfAWordAndNumbersToTheEndWhileMaintainingOrder();
    test_replaceEachDigitOfTheStringWithTheCorrespondingNumberOfSpaces();
}


int main() {
    //testLib();
    test_tasks();

    return 0;
}
