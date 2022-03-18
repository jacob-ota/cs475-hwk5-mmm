#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "rtclock.h"
#include "mmm.h"

/* globals (anything here would be shared with all threads) */
int size;
int numThreads;

int main(int argc, char *argv[])
{
	// double clockstart, clockend;
	// clockstart = rtclock(); // start clocking

	// start: stuff I want to clock
	if(argc == 1) {
		printf("Usage: ./mmm <mode> [num threads] <size>\n");
	}
	else if(!strcmp(argv[1], "S") && argc > 1) {
		if(argc == 3) {
			size = atoi(argv[2]);
			numThreads = 1;
			if(size > 0) {
				printf("========\n");
				printf("mode: sequential\n");
				printf("thread count: %d\n", numThreads);
				printf("size: %d\n", size);
				printf("========\n");
			}
			else {
				printf("Entered size cannot be 0 or negative or a nonnumber!\n");
			}
		}
		else if(argc == 2) {
			printf("Error: sequential mode requires <size>\n");
		}
		else {
			printf("Usage: ./mmm <mode> [num threads] <size>\n");
		}
	}
	else if(!strcmp(argv[1], "P") && argc > 1) {
		if(argc == 4) {
			numThreads = atoi(argv[2]);
			size = atoi(argv[3]);
			if(numThreads > 0) {
				if(size > 0) {
					printf("========\n");
					printf("mode: parallel\n");
					printf("thread count: %d\n", numThreads);
					printf("size: %d\n", size);
					printf("========\n");
				}
				else {
					printf("Entered size cannot be 0 or negative or a nonnumber!\n");
				}
			}
			else {
				printf("Entered num threads cannot be 0 or negative or a nonnumber!\n");
			}
		}
		else if(argc == 3) {
			printf("Error: parallel mode requires <size>\n");
		}
		else {
			printf("Usage: ./mmm <mode> [num threads] <size>\n");
		}
	}
	else {
		printf("Usage: ./mmm <mode> [num threads] <size>\n");
	}
	// end: stuff I want to clock

	// clockend = rtclock(); // stop clocking
	// printf("Time taken: %.6f sec\n", (clockend - clockstart));

	return 0;
}
