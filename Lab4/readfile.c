#include <stdio.h>
#include "readfile.h"

// global variables
FILE *infile;

int open_file(char *filename) {

    infile = fopen(filename, "r");
    if (infile == NULL) {
        return -1;
    }
    else {
        return 0;
    }
}

int close_file(void) {
    fclose(infile);
    return 0;
}

int read_int(int *value) {
    int rv = fscanf(infile, "%d", value);
    if (rv == EOF) {
        return 1;
    }
    else {
        return 0;
    }
}

int read_string(char *value) {
    int rv = fscanf(infile, "%s", value);
    if (rv == EOF) {
        return 1;
    }
    else {
        return 0;
    }
}

int read_float(float *value) {
    int rv = fscanf(infile, "%f", value);
    if (rv == EOF) {
        return 1;
    }
    else {
        return 0;
    }
}