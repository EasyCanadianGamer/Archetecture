#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

#define ARRAYSIZE 100
void get_filename_from_cmdline(int argc, char *argv[], char *filename) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    else {
        strncpy(filename, argv[1], 255);
    }
}

int main(int argc, char *argv[]) {
    char filename[255];
    float values[ARRAYSIZE];
   int i, num_floats, j;
    float min_value, max_value, temp;  
      // get the filename from the command line
    get_filename_from_cmdline(argc, argv, filename);
    
    // TODO - complete the program

    // reading file
    printf("Reading File named %s\n", filename);
    open_file(filename);


 read_int(&num_floats);
    read_float(&min_value);
    read_float(&max_value);


    for ( i =0; i < 13; i++)
    {
        read_float(&values[i]);
    }
    printf("The file has %d floats ranging from %.1f to %.1f\n", num_floats, min_value, max_value);



// printing the unsorted array
    printf("The unsorted values are: ");
    for ( i =0; i < 10; i++)
    {
        printf("%.2f ", values[i]);
    }
    printf("\n");

    //sorting the array 
    for ( i = 0; i < num_floats; i++)
    {
        for ( j = 0; j < num_floats -i -1; j++)
        {
            if (values[j] > values[j+1])
            {
               temp = values[j];
               values[j] = values[j+1];
               values[j+1] = temp;
            }
    }  
    } 

// printing the sorted array
    printf("The sorted values are: ");
  for ( i =0; i < num_floats; i++)
    {
        printf("%.2f ", values[i]);
    }
    printf("\n");

    return 0;
}