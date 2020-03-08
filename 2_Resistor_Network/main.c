/*
* Author: Frank Manu
*
*/

#include <stdio.h>

void printMatrix(int m, int n, float arr[][n]);
void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]);
void gess_( int *, float *, int *, float *, int * , int *, float * );
void matrixMultiplication(int m, int n, int p, float A[m][n], float B[n][p], float C[m][p]);


int main(int argc, char **argv)
{
	int i, j, k, l;
	int N,IC,IB,NB;
	float cond;

	// I = {1, 2}
	float I1 = 1;
	float I2 = 2;

	// V = {1, 2, 3}
	float V1 = 1;
	float V2 = 2;
	float V3 = 3;

	float A[3][5] = {{I1, I2, 0, 0, 0},
					 {0, I1, I2, 0, 0},				
					 {0, 0, 0, I1, I2}};

	float B[3][1] = {V1, V2, V3};

	float R[5][1] = {0};

	float A_T[5][3];
	float C[3][3] = {0};
	float C_T[3][3] = {0};
	transposeFunction(3, 5, A, A_T);

	
	for (k = 0; k < 3; k++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 5; j++){
				C[k][i] += A[k][j]*A_T[j][i];
            }
        }
    }
	
	transposeFunction(3, 3, C, C_T);

	N = 3;	
	IC = 3; 
	IB = 3; 
	NB = 3;

	gess_( (int *)&N, (float *)&C_T, (int *)&IC, (float *) &B, (int *)&IB, (int *)&NB, (float *) &cond);

	matrixMultiplication(5, 3, 1, A_T, B, R);

	puts("R11\tR12\tR22\tR31\tR32");

	for (i = 0; i < 5; i++){
		printf("%.5f ", R[i][0]);
    }

	printf("\n");

	return 0;
}

//
void printMatrix(int m, int n, float matrix[][n]) { 
    int i, j; 

    for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){ 
        	printf("%.3f\t", matrix[i][j]);
    	}
    	printf("\n");
    }
    printf("\n");
}

void matrixMultiplication(int m, int n, int p, float A[m][n], float B[n][p], float C[m][p])
{
	int i, j, k;

	for (i = 0; i < m; i++){
		for (k = 0; k < p; k++){
			for (j = 0; j < n; j++){
				C[i][k] += A[i][j] * B[j][k];
            }
        }
    }

}

// Input: row, column, matrix[][]
// Output: matrixTranspose[][]
// matrixTranspose[][] is modified in place
void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]){
    int i, j;

    for (i=0; i<row;i++){
        for(j=0;j<column;j++){
            matrixTranspose[j][i] = matrix[i][j];
        }
    }
}