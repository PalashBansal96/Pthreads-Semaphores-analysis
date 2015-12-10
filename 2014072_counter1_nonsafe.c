#include "2014072_counter1_nonsafe.h"
#include <stdio.h>

void init_nonsafe(counter_nonsafe* counter){
	counter->value = 0;
}

void increment_nonsafe(counter_nonsafe* counter){
	counter->value++;
}

void count_nonsafe(long limit, counter_nonsafe* counter){
	while(counter->value<limit)
		counter->value++;
	if(counter->value>limit)
		printf("Problem Occured, Value = %ld \n", counter->value);
}