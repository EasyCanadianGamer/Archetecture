#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include <math.h>


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

// Function to calculate min
float get_min(float *values, int size) {
    float min = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

// Function to calculate max
float get_max(float *values, int size) {
    float max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}

float get_mean(float *values, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

float get_median(float *values, int size) {
    float temp;
    // Sorting values for median calculation
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (values[i] > values[j]) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        return (values[size/2 - 1] + values[size/2]) / 2;
    } else {
        return values[size/2];
    }
}


float get_std_dev(float *values, int size, float mean) {
    float sum_sq_diff = 0;
    for (int i = 0; i < size; i++) {
        sum_sq_diff += (values[i] - mean) * (values[i] - mean);
    }
    return sqrt(sum_sq_diff / size);
}


float *get_values(int *size, int *capacity, char *filename) {
    // Allocate memory for values
    values = (float*)malloc(sizeof(float) * (*capacity));
   
    if (values == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    printf("Memory allocated\n");

    float value;
    int num_floats;

    // Read the floats from the file
    while ((num_floats = read_float(&value)) == 0) { // 0 means read successful
        // Add the value to the array
        values[*size] = value;
        (*size)++;

        // Check if we need to resize the array
        if (*size == *capacity) {
            *capacity *= 2;
            values = (float*)realloc(values, sizeof(float) * (*capacity));
            if (values == NULL) {
                fprintf(stderr, "realloc failed\n");
                exit(1);
            }
        }
    }
    return values; 
}

int main(int argc, char *argv[]) {
    char filename[255];
    int size = 0;
    int cap  = 4;


    // get the filename from the command line
    get_filename_from_cmdline(argc, argv, filename);



    // TODO - complete the program

    open_file(filename);

    values = get_values(&size, & cap, filename);

close_file();

// print
   float min = get_min(values, size);
    float max = get_max(values, size);
    float mean = get_mean(values, size);
    float median = get_median(values, size);
    float std_dev = get_std_dev(values, size, mean);


  printf("Results\n");
    printf("-------\n");
    printf("num values:         %d\n", size);
    printf("       min:      %.3f\n", min);
    printf("       max:      %.3f\n", max);
    printf("      mean:      %.3f\n", mean);
    printf("    median:      %.3f\n", median);
    printf("   std dev:      %.3f\n", std_dev);
    printf("unused array capacity: %d\n", cap - size);




   



    

    
free( values);


    

    return 0;
}