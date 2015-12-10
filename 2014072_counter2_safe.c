#include "2014072_counter2_safe.h"

void init_safe(counter_safe* counter){
	pthread_mutex_init(&(counter->lock), NULL);
	counter->value = 0;
}

void count_safe(long limit, counter_safe* counter){
	//limit/=counter->n_threads;
	//for(long i = 0; i<limit ; i++)
	while(counter->value<limit){
		pthread_mutex_lock(&(counter->lock));
		if(counter->value<limit)
			counter->value++;
		pthread_mutex_unlock(&(counter->lock));
	}
}