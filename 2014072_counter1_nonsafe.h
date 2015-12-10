#ifndef COUNT_NONSAFE
#define COUNT_NONSAFE

typedef struct counter_nonsafe{
	long value;
} counter_nonsafe;

void init_nonsafe(counter_nonsafe* counter);

void increment_nonsafe(counter_nonsafe* counter);

void count_nonsafe(long limit, counter_nonsafe* counter);

#endif