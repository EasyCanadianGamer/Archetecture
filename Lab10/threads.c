#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    int num = *(int*)arg;
    int is_prime = 1;

    if( num < 2) is_prime = 0;
    for(int i = 2; i * i <= num;  i++) { 
      if( num % i == 0 ) {
          is_prime =0;
          break;
         }
     }

      if ( is_prime) printf("%d is prime\n", num);
    return NULL;
}

int main(int argc, char* argv[] ) {
     if( argc != 3){
         fprintf(stderr,"Usage: %s <highest_candidate> <num_threads>\n",argv[0]);
          return 1;
     }

     int highest_candidate = atoi(argv[1]);
     int num_threads = atoi(argv[2]);

     if( highest_candidate <=0 || num_threads <=0){
      fprintf(stderr, "Both <highest_candidate> and <num_threads> must be positive integers.\n");
      return 1;
      }


    pthread_t threads[num_threads];
    int thread_args[num_threads];
    struct timeval tstart, tend;
    double timer;

    gettimeofday(&tstart, NULL);



     for (int start = 2; start <= highest_candidate; start += num_threads) {
        int threads_to_create = 0;

        for (int i = 0; i < num_threads && start + i <= highest_candidate; i++) {
            thread_args[i] = start + i;
            pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
            threads_to_create++;
        }

        for (int i = 0; i < threads_to_create; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    gettimeofday(&tend, NULL);

    timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
    printf("time is %g seconds\n", timer);

    return 0;
}
