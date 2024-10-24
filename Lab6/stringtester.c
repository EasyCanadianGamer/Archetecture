/*
    CSC 325- sec 02
    Lab 6 - stringtester.c
    Name: Eyad Merajuddin
    Email: merajue1@tcnj.edu
*/

#include "my_strings.h"
#include <string.h>





int main(int argc, char *argv[]) {
    // TODO - write your code here
    char src[100] = "ballers";

    char str1[100] = "ball";
    char str2[100] = "boi";

    char str3[100] = "Lego";
    char str4[100] = "Ninjago";

    //strdup
     char *str5 = strdup(src);
    char *p;
  //strcat
    strcat(str1, str2);
    //strchr
    strchr(str1, 'l');
// strcpy
    strcpy(str3, str4);
   //strcmp
    int a = strcmp(str1, str2);
   //strstr
    p = strstr(str1, str2);
//strlen
    strlen(src);

    




    return 0;

} 