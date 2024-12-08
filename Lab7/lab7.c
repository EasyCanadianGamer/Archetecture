/*
    CSC 325-your_section_here
    Lab 7
    Name: your_name_here
    Email: your_email_here
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int **genRandomMatrix(int n, int max) {
    int i, j;
    int **mat = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {
            mat[i][j] = 1 + rand() % max;
        }
    }

    return mat;
}

void free_all(int **mat, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(mat[i]);
    }

    free(mat);
}

float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
        }
    }

    return (float) total / (n * n);
}

float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
        }
    }

    return (float) total / (n * n);
}

int main(int argc, char** argv) {
    /* Validate command line parameters. */
    if (argc != 3) {
        fprintf(stderr, "usage: %s <n> <v>\n", argv[0]);
        fprintf(stderr, "where <n> is the dimension of the matrix and <v> is the algorithm version (1 or 2)\n");
        return 1;
    }

    /* Declare and initialize variables. */
    float res;
    double timer;
    int n = strtol(argv[1], NULL, 10);
    int v = strtol(argv[2], NULL, 10);
    srand(time(NULL));
    struct timeval tstart, tend;
    int ** matrix = genRandomMatrix(n, 100);

    gettimeofday(&tstart, NULL);
    if (v == 1)
        /* Time version 1. */
        res = averageMat_v1(matrix, n);
    else
        /* Time version 2. */
        res = averageMat_v2(matrix, n);

    gettimeofday(&tend, NULL);
    timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
    printf("average is: %.2f; time is %g\n", res, timer);

    /* Clean up. */
    free_all(matrix, n);
    return 0;
}