#include <stdio.h>

// function prototype for sum.s
long sum(long n);

int main(int argc, char *argv[]) {
    long l_n, l_sum;
    char line[256];

    printf("This program computes the sum of 1-N\n");
    printf("Enter a value for n: ");
    if (fgets(line, sizeof(line), stdin)) {
        if (1 == sscanf(line, "%ld", &l_n)) {
            l_sum = sum(l_n);  // call the assembly function
	}
    }
    printf("The sum of 1 to %ld is %ld\n", l_n, l_sum);
    return 0;
}
