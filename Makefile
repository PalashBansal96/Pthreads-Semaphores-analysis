CC = gcc
CFLAGS = -pthread
counters = 2014072_counter1_nonsafe.c 2014072_counter2_safe.c

all: stp mtp_c1 mtp_c2 mtp_c1_sem

stp: 
	$(CC) $(CFLAGS) $(counters) 2014072_stp.c -o stp.out

mtp_c1: 
	$(CC) $(CFLAGS) $(counters) 2014072_mtp_c1.c -o mtp_c1.out

mtp_c2: 
	$(CC) $(CFLAGS) $(counters) 2014072_mtp_c2.c -o mtp_c2.out

mtp_c1_sem: 
	$(CC) $(CFLAGS) $(counters) 2014072_mtp_c1_sem.c -o mtp_c1_sem.out

# 2014072_counter2_safe.o: 2014072_counter2_safe.c
# 	$(CC) $(CFLAGS) -c 2014072_counter2_safe.c

# 2014072_counter1_nonsafe.o: 2014072_counter1_nonsafe.c
# 	$(CC) $(CFLAGS) -c 2014072_counter1_nonsafe.c

clean:
	rm *.out 
