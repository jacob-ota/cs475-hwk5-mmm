#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "rtclock.h"
#include "mmm.h"

/* globals (anything here would be shared with all threads) */
extern double **firstMatrix;
extern double **secondMatrix;
extern double **seqMatrix;
extern double **parMatrix;

int main(int argc, char *argv[])
{
	int size, numThreads;
	double clockstart, clockend;

	// when they user only uses ./mmm
	if(argc == 1) {
		printf("Usage: ./mmm <mode> [num threads] <size>\n");
	}
	//when the user uses ./mmm S
	else if(!strcmp(argv[1], "S") && argc > 1) {
		//checks for next param
		if(argc == 3) {
			//sets size to what user gives and numthreads to 1
			size = atoi(argv[2]);
			numThreads = 1;
			//checks if the size is positive
			if(size > 0) {
				//output to user
				printf("========\n");
				printf("mode: sequential\n");
				printf("thread count: %d\n", numThreads);
				printf("size: %d\n", size);
				printf("========\n");
				mmm_init(size);
				clockstart = rtclock(); // start clocking
				mmm_seq(size);
				clockend = rtclock(); // stop clocking
				printf("Sequential Time: %.6f sec\n", (clockend - clockstart));
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
	//when the user uses ./mmm P
	else if(!strcmp(argv[1], "P") && argc > 1) {
		//checks for the next 2 parameters
		if(argc == 4) {
			//sets numthreads and size to what user gives
			numThreads = atoi(argv[2]);
			size = atoi(argv[3]);
			//checks if numthreads and size are positive
			if(numThreads > 0) {
				if(size > 0) {
					//output to user
					printf("========\n");
					printf("mode: parallel\n");
					printf("thread count: %d\n", numThreads);
					printf("size: %d\n", size);
					printf("========\n");
					// start: stuff I want to clock
					// clockstart = rtclock(); // start clocking
					// mmm_seq here to clock it
					// clockend = rtclock(); // stop clocking
					// double seqTime = clockend - clockstart;
					// printf("Sequential Time: %.6f sec\n", seqTime);				
					// end: stuff I want to clock

					// start: stuff I want to clock
					// clockstart = rtclock(); // start clocking
					// mmm_par here to clock it
					// clockend = rtclock(); // stop clocking
					// double parTime = clockend - clockstart;
					// printf("Parallel Time: %.6f sec\n", parTime);
					// end: stuff I want to clock

					//do the speedup
					// double speedup = seqTime / parTime;
					// printf("Speedup: %.6f\n", speedup);

					//verification
					// printf("Verifying... largest error between parallel and sequential matrix:  %.6f\n", mmm_verify());
				}
				else {
					printf("Entered size cannot be 0 or negative or a nonnumber!\n");
				}
			}
			else {
				printf("Entered num threads cannot be 0 or negative or a nonnumber!\n");
			}
		}
		//checks if there is one less parameter and asks for size
		else if(argc == 3) {
			printf("Error: parallel mode requires <size>\n");
		}
		else {
			printf("Usage: ./mmm <mode> [num threads] <size>\n");
		}
	}
	//if user input after ./mmm is wrong then hint format
	else {
		printf("Usage: ./mmm <mode> [num threads] <size>\n");
	}

	return 0;
}
