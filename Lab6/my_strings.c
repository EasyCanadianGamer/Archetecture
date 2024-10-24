/*
    CSC 325-your_section_here
    Lab 6 - my_strings.c
    Name: your_name_here
    Email: your_email_here
*/

#include <stdio.h>
#include <stdlib.h>

// TODO - write your code here
char *strcat(char *restrict dst, const char *restrict src)
{
    // cocatenating strings

    // navigate to end of the string
    while(*dst)
    {
        ++dst;
    }

      // Copy characters of the second string to the end of
    // the first string
    while(*src)
    {
        *dst++ = *src++;
    }

        // Add the null-terminating character

        *dst = '\0';

}




char *strchr(const char *s, int c)
{
      while (*s != '\0') {
        if (*s == c) {
            return (char *)s; // Return a pointer to the first occurrence
        }
        s++;
    }
    return NULL; // Return NULL if the character is not found

}
int strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
char *strcpy(char *restrict dst, const char *restrict src)
{
 char *ret = dst; // puts the original dst into ret
 while(*src != '\0') // while src is not null
 {
    *dst = *src; // copy src into dst
    dst++; // inncrement dst
    src++; // increment src

 }

 *dst = '\0'; // dst is null

 return ret; // return ret

}
char *strdup(const char *s){
   if (s == NULL) {
        return NULL;
    }

    // Calculate the length of the string
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    // Allocate memory for the new string
    char *new_str = (char *)malloc(len + 1); 
    if (new_str == NULL) {
        return NULL; // Memory allocation failed
    }

    // Copy the string
    for (int i = 0; i <= len; i++) { 
        new_str[i] = s[i];
    }

    return new_str;

}
size_t strlen(const char *s)
{
     size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }

    return len;


}
char *strstr(const char *haystack, const char *needle){
 if (*needle == '\0') {
        return (char *)haystack; // Empty needle matches at the beginning
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h == *n && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack; // Found a match
        }

        haystack++;
    }

    return NULL; // No match found

}



