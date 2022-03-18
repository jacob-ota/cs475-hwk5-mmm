#ifndef MMM_H_
#define MMM_H_

typedef struct arguments {
    int tid;
    int beginRow; //get start row for the partial matrix multi
    int finishRow; //get partial matrix multi and which row to finish
    int matrixSize; //get size to run through full length of a column
} thread_args;

void mmm_init(int matrixSize);
void mmm_reset(double **matrix, int matrixSize);
void mmm_freeup();
void mmm_seq(int matrixSize);
void *mmm_par(void *args);
double mmm_verify(int matrixSize);

#endif /* MMM_H_ */
