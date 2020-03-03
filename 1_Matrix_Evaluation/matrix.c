#include <stdio.h>
#include "matrix.h"

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