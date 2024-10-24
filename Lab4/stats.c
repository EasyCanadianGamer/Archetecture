/* Yana Goldberg and Eyad Merajuddin
CSC 325-02 
October 13, 2024
The program reads in float values from a file, sorts them, and 
calculates some statistics about them. The statistics calculated
are the minimum, maximum, mean, median, and standard deviation.
The program also uses malloc to dynamically allocate arrays which
hold the float values that are read in. When the program reads
in more values than the array can hold, a new array is created
which is double the size of the previous array, and the original
array is freed.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "readfile.h"

// Retrieve the file name from the cmd line
void get_filename_from_cmdline(int argc, char *argv[], char *filename) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    else {
        strncpy(filename, argv[1], 255);
    }
}

// Sort function using the bubble sort algorithm.
void bubble_sort(float *arr, int size) {
   for (int i = 0; i < size - 1; i++) {
       for (int j = 0; j < size - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               float temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
    
            }
        }
    }
} 

// Reallocation function which is called when the number
// of floats in the file exceeds the capacity of the array
float *reallocate(float *oldArray, int *capacity) {
    float *newArray;

    // Allocate space for a new array which is double the size
    // of the original array
    newArray = malloc(sizeof(float) * (*capacity) * 2);

    // Copy all the floats from the old array to the new array
    for (int i = 0; i < (*capacity); i++) {
        newArray[i] = oldArray[i]; 
    }
    
    // Free the memory holding the old array
    free(oldArray);
    // Update the variably holding capacity
    *capacity = (*capacity) * 2;
    return newArray;
}

// Populate the array with floats from the file being read
float *get_values(int *size, int *capacity, char *filename) {
    float *numArray;
    float num;
    int i = 0;

    *capacity = 20;
    // Allocate space for an array of 20 floats 
    numArray = malloc(sizeof(float) * (*capacity));

    // While there are still floats to be read from the file,
    // place them into the array and update the size.
    while(read_float(&num) != 1) {
        numArray[i] = num;
        i++;
        (*size)++;

        // If the size of the array is about to exceed the capacity,
        // call the previously defined reallocation function to 
        // allocate space for a new, larger array.
        if (*size >= *capacity - 1) {
            numArray = reallocate(numArray, capacity);
        }
    }

    return numArray;    
}

// Return the first value in the sorted array
float minimum(float *array) {
    return array[0];
}

// Return the last value in the sorted array
float maximum(float* array, int size) {
    return array[size - 1];
}

// Calculate the mean of the array
double calcMean(float *array, int size) {
    double sum = 0;
    double mean = 0;

    // Find the sum of all the numbers in the array
    for (int i = 0; i < size; i++) {
        sum = sum + array[i];
    }
    
    // Divide the sum by the size of the array to find the mean
    mean = sum / size;
    return mean;
}

// Find the median of the array
float findMedian(float *array, int size) {
    float median;

    // If there are an odd number of floats in the array
    if (size % 2 == 1) {
        median = array[(size - 1) / 2];
    }
    // If there are an even number of floats in the array
    else {
        median = array[size / 2];
    }

    return median;
}

// Calculate the standard deviation
double stdDev(float *array, int size, double mean) {
    double standardDev;
    double summation = 0;

    // Find the summation of the number in the ith position subtracted
    // by the mean and all to the power of 2
    for (int i = 0; i < size; i++) {
        summation = summation + pow((array[i] - mean), 2);
    }
    
    // Use the formula for standard deviation
    standardDev = sqrt((1.0 / size) * summation);

    return standardDev;
}


int main(int argc, char *argv[]) {
    char filename[255];
    int arraySize = 0; 
    int arrayCapacity = 0;
    float *numArray;
    double mean;
    int unusedCapacity;

    // get the filename from the command line
    get_filename_from_cmdline(argc, argv, filename);

    // Open the file
    open_file(filename);

    // Call the get_values function to populate the array
    numArray = get_values(&arraySize, &arrayCapacity, filename);

    // Sort the array using the bubble_sort function
    bubble_sort(numArray, arraySize);

    // Calculate the mean to make the call to the stdDev function cleaner
    mean = calcMean(numArray, arraySize);

    // Calculate the unused capacity left over in the array
    unusedCapacity = arrayCapacity - arraySize;

    // Print all results
    printf("Results: \n-------\nnum values: %d\n", arraySize);
    printf("%10s: %.3f\n", "min", minimum(numArray));
    printf("%10s: %.3f\n", "max", maximum(numArray, arraySize));
    printf("%10s: %.3f\n", "mean", mean);
    printf("%10s: %.3f\n", "median", findMedian(numArray, arraySize));
    printf("%10s: %.3f\n", "std dev", stdDev(numArray, arraySize, mean));
    printf("unused array capacity: %d\n", unusedCapacity);

    // Free the array and close the file
    free(numArray);
    close_file();

    return 0;
}