#ifndef COUNT_SAFE
#define COUNT_SAFE

#include <pthread.h>

typedef struct counter_safe {
	long value;
	int n_threads;
	pthread_mutex_t lock;
} counter_safe;

void init_safe(counter_safe* counter);

void count_safe(long limit, counter_safe* counter);

#endif