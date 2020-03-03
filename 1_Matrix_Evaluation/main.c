/*
* Author: Frank Manu
*
*/

#include <stdio.h>

void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]);

void printMatrix(int m, int n, float arr[][n]);

void gess_( int *, float *, int *, float *, int * , int *, float * );


int main(int argc, char** argv){
    int N, IA, IB, NB;
    float cond;

    //defining matrix A
    float A[3][3] = {{-2, 1, 2},{2, 3, -2},{1, -2, 3}};

    //Defining matrix B
    float B[3][3] = {{-2, 2, 4},{3, 1, -1},{5, -4, 6}};

    float ATranspose[3][3];
    float BTranspose[3][3];

    //Transposing Matrix A and B
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            ATranspose[j][i] = A[i][j];
            BTranspose[j][i] = B[i][j];
        }
    }

    N = 3;
    IA=3;
    IB=3;
    NB=3;

    gess_( (int *)&N, (float *)&ATranspose, (int *)&IA, (float *)&BTranspose, (int *)&IB, (int *)&NB, (float *)&cond);

	transposeFunction(3, 3, BTranspose, B);
	printMatrix(3, 3, B);

    return 0;
}

//
void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]){
    int i, j;

    for (i=0; i<row;i++){
        for(j=0;j<column;j++){
        matrixTranspose[j][i] = matrix[i][j];
        }
    }
}

//
void printMatrix(int m, int n, float arr[][n]) { 
    int i, j; 

    for (i = 0; i < m; i++){
    	for (j = 0; j < n; j++){ 
        	printf("%.3f\t", arr[i][j]);
    	}
    	printf("\n");
    } 
}
