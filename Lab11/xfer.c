#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_XFERS 1000000 // Number of account xfers
#define INITIAL_BALANCE 1000.0 // Initial balance for each account
#define N 2 // Number of accounts

typedef struct {
    int id;
    double balance;
    pthread_mutex_t mutex; // Lock to use/modify account balance
} Account;

Account accounts[N];

// Initialize accounts with initial balance
void initializeAccounts() {
    for (int i = 0; i < N; ++i) {
        accounts[i].id = i;
        accounts[i].balance = INITIAL_BALANCE;
        pthread_mutex_init(&accounts[i].mutex, NULL);
    }
}

// Simulate a withdrawal from an account
void withdraw(Account* account, double amount) {
    pthread_mutex_lock(&account -> mutex);
    account->balance -= amount;
    pthread_mutex_unlock(&account -> mutex);
}

// Simulate a deposit to an account
void deposit(Account* account, double amount) {
        pthread_mutex_lock(&account -> mutex);

    account->balance += amount;
        pthread_mutex_unlock(&account -> mutex);

}

// Transfer money from one account to another
void* transfer(void *arg) {
    Account *from, *to;

    // arg determines xfer direction
    if (arg == (void *)&accounts[0]) {
        from = &accounts[0];
        to = &accounts[1];
    }
    else {
        from = &accounts[1];
        to = &accounts[0];
    }
    for (long i = 0; i < NUM_XFERS; ++i) {
        // Random amount to transfer (between 1 and 100)
        double amount = rand() % 100 + 1;


  

        // Transfer funds
            withdraw(from, amount);
            deposit(to, amount);
        


    
   
    }
    return NULL;
}

int main() {
    initializeAccounts();

    // Print initial balances
    printf("Account 0 initial balance: %.2lf\n", accounts[0].balance);
    printf("Account 1 initial balance: %.2lf\n", accounts[1].balance);
    printf("Total initial balances: %.2lf\n", accounts[0].balance + accounts[1].balance);

    // Create two threads for money transfer
    pthread_t thread0, thread1;
    pthread_create(&thread0, NULL, transfer, (void *)&accounts[0]);
    pthread_create(&thread1, NULL, transfer, (void *)&accounts[1]);

    // Wait for threads to finish
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);

    // Print final balances
    printf("Account 0 final balance: %.2lf\n", accounts[0].balance);
    printf("Account 1 final balance: %.2lf\n", accounts[1].balance);
    printf("Total final balances: %.2lf\n", accounts[0].balance + accounts[1].balance);

    // Clean up
    for (int i = 0; i < N; ++i) {
        pthread_mutex_destroy(&accounts[i].mutex);
    }

    return 0;
}
