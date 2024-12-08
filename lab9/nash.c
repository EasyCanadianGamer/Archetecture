#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char token[256]; // Allocate a fixed-size buffer for the token

    printf("Welcome to nash\n");

    while (1) {
        printf("? ");
        if (fscanf(stdin, "%255s", token) == EOF) { // Limit input size to prevent buffer overflow
            fprintf(stderr, "EOF\n");
            exit(0);
        }

        if (strcmp(token, "exit") == 0) {
            fprintf(stderr, "bye!\n");
            exit(0);
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) { // Child process
            execlp(token, token, NULL); // Use execlp for simplicity
            perror("execvp");
            exit(1);
        } else { // Parent process
            wait(NULL);
        }
    }

    return 0;
}
