#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "2014072_counter1_nonsafe.h"
#include "2014072_counter2_safe.h"

#define BILLION 1000000000

typedef struct tcount{
	counter_nonsafe counter;
	int n_threads;
	sem_t sem_lock;
} tcount;

void *thread_counter(void *v_counter){
	tcount *counter = (tcount *)v_counter; 
	long limit = 1*BILLION/counter->n_threads;
	for(long i = 0; i < limit; i++){
		sem_wait(&counter->sem_lock);	
		//increment_nonsafe(&counter->counter);
		counter->counter.value++;
		sem_post(&counter->sem_lock);
	}
	//count_nonsafe(1*BILLION, &counter->counter);
}


int main(){
	struct timeval start, end;
	for(int n_thread=1; n_thread<=10; n_thread++){
		
		double average_time=0;
		pthread_t threads[10];
		printf("%d Threads\n", n_thread);
		for(int i=1; i<=50; i++){
			
			gettimeofday(&start, NULL);

			tcount counter;
			counter.n_threads = n_thread;

			sem_init(&counter.sem_lock, 0, 1);

			init_nonsafe(&counter.counter);
			
			for(int t = 0; t<n_thread; t++) {
				pthread_create(&threads[t], NULL, thread_counter, &counter);
			}
			
			for(int t = 0; t<n_thread; t++) {
				pthread_join(threads[t], NULL);
			}

			gettimeofday(&end, NULL);
			double time_taken = 
				(double) (end.tv_usec - start.tv_usec) / 1000000
				+ (double) (end.tv_sec - start.tv_sec);
			average_time = (average_time*(i-1) + time_taken)/i;

			printf("\tDone %d'th execution. Final Value = %ld, Time Taken = %f, Average Time = %f\n", i, counter.counter.value, time_taken, average_time);

		}
		printf("For %d Threads, Average Time = %f\n", n_thread, average_time);
		//Write average to file
	}
}