#include <sys/time.h>
#include <stdio.h>
#include "2014072_counter1_nonsafe.h"
#include "2014072_counter2_safe.h"

#define BILLION 1000000000

int main(){
	struct timeval start, end;
	double average_time=0;
	for(int i=1; i<=50; i++){
		
		gettimeofday(&start, NULL);

		counter_nonsafe counter;
		init_nonsafe(&counter);
		count_nonsafe(1*BILLION, &counter);
		
		gettimeofday(&end, NULL);
		double time_taken = 
			(double) (end.tv_usec - start.tv_usec) / 1000000
			+ (double) (end.tv_sec - start.tv_sec);
		average_time = (average_time*(i-1) + time_taken)/i;

		printf("Done %d'th execution. Time Taken = %f, Average Time = %f\n", i, time_taken, average_time);
		
	}
	printf("Average Time = %f\n", average_time);
}