#ifndef MMM_H_
#define MMM_H_

void mmm_init(int matrixSize);
void mmm_reset(double **matrix, int matrixSize);
void mmm_freeup();
void mmm_seq(int matrixSize);
void *mmm_par(void *args);
double mmm_verify();

#endif /* MMM_H_ */
