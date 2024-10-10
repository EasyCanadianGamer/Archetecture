#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"


float *values;


void get_filename_from_cmdline(int argc, char *argv[], char *filename) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    else {
        strncpy(filename, argv[1], 255);
    }
}



float *get_values(int *size, int *capacity, char *filename) {
    // TODO - complete the function
    int num_floats;
    float value;
    int numfloats = read_float(&value);


   values = (float*)malloc( sizeof(float) * *capacity);
   
   if ( values == NULL) {
       fprintf(stderr, "malloc failed\n");
       exit(1);
   }
   else{
    printf(" Memory allocated\n");


    // read the floats from the file
    while (numfloats != 1) { 
        num_floats = read_float(&value);
        if (num_floats == 1) {
            break;

        }
        else {

            // add the value to the array
            values[*size] = value;
            *size = *size + 1;
            if (*size == *capacity) {
                *capacity = *capacity * 2;
                values = (float*)realloc(values, sizeof(float) * *capacity);
                if (values == NULL) {
                    fprintf(stderr, "realloc failed\n");
                    exit(1);
                }
            }
            
        }
    }
    }
    return values; 
}

int main(int argc, char *argv[]) {
    char filename[255];
    int size = 0;
    int cap  = 1;


    // get the filename from the command line
    get_filename_from_cmdline(argc, argv, filename);



    // TODO - complete the program

    open_file(filename);

    values = get_values(&size, & cap, filename);

// print
    for (int i = 0; i < size+1; i++) {
        printf("%f\n", values[i]);
    }

close_file();


    

    



    

    return 0;
}