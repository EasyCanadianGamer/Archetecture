#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>

char *strcat(char *restrict dst, const char *restrict src);
char *strchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);
char *strcpy(char *restrict dst, const char *restrict src);
char *strdup(const char *s);
size_t strlen(const char *s);
char *strstr(const char *haystack, const char *needle);

#endif