#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <strings.h>

char* numbers[32];
int maxLen;
char* vowels;

char* concat(char* str1,char* str2);
char* intToString(int num);
int lenstr(char* str, int max);
int in_str(char* n, char* target);
int equals(char* a, char* b);
char* concat(char* str1,char* str2);
int is_vowel(char* n);
int lenstr(char* str, int max);
