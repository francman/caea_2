/*
* Author: Frank Manu
*
*/

// Matrix Computation C=(A^-1)*(B)

#include <stdio.h>

void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]);
void printMatrix(int m, int n, float arr[][n]);
void gess_( int *, float *, int *, float *, int * , int *, float * );

int main(int argc, char** argv){
    int N, IA, IB, NB;
    float cond;

    //defining matrix A
    //      [-2 1 2]
    // A =  [2 3 -2]
    //      [1 -2 3]
    float A[3][3] = {{-2, 1, 2},{2, 3, -2},{1, -2, 3}};

    //Defining matrix B
    float B[3][3] = {{-2, 2, 4},{3, 1, -1},{5, -4, 6}};

    float ATranspose[3][3];
    float BTranspose[3][3];
    float C[3][3];

    transposeFunction(3, 3, A, ATranspose);
    transposeFunction(3, 3, B, BTranspose);

    N=3;
    IA=3;
    IB=3;
    NB=3;

    gess_( (int *)&N, (float *)&ATranspose, (int *)&IA, (float *)&BTranspose, (int *)&IB, (int *)&NB, (float *)&cond);

	transposeFunction(3, 3, BTranspose, C);
	printMatrix(3, 3, C);

    return 0;
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
