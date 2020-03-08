#include <stdio.h>

void printMatrix(int m, int n, float arr[][n]);
void transposeFunction(int row, int column, float matrix[][column], float matrixTranspose[][row]);
void gess_( int *, float *, int *, float *, int * , int *, float * );
void matrixMultiplication(int m, int n, int p, float A[m][n], float B[n][p], float C[m][p]);



int main(int argc, char **argv)
{
	int i, j, k;
	int NC,IC,ID,ND;
	float cond;

	float data[11][1] = {75.994, 91.972, 105.71, 122.775, 131.669, 150.697, 179.323, 203.235, 227.224, 249.438, 281.421};
	float B[9][1] = {75.994, 91.972, 105.71, 122.775, 131.669, 150.697, 179.323, 203.235, 227.224};
	float P_y[11] = {0};

	float A[9][3] = {0};
	float A_T[3][9] = {0};

	// float C = A^T *A, D = A^T * B
	float C[3][3] = {0};
	float C_T[3][3] = {0};
	float D[3][1] = {0}; 
	float D_T[1][3] = {0};

	float Y[11] = {0};

	// Year data
	for (i = 0; i < 11; i++)
		Y[i] = 1900 + i*10;

	// Vector for Population Model
	for (i = 0; i < 9; i++)
	{
		A[i][0] = 1;
		A[i][1] = Y[i];
		A[i][2] = Y[i]*Y[i];
	}

	// A transpose is used for fortran subroutines
	transposeFunction(9, 3, A, A_T);

	matrixMultiplication(3, 9, 3, A_T, A, C);

	transposeFunction(3, 3, C, C_T);

	matrixMultiplication(3, 9, 1, A_T, B, D);

	transposeFunction(3, 1, D, D_T);

	NC = 3;	
	IC = 3; 
	ID = 3; 
	ND = 1; 

	gess_( (int *)&NC, (float *)&C_T, (int *)&IC, (float *) &D_T, (int *)&ID, (int *)&ND, (float *) &cond);

	puts("c1 c2 c3");
	printMatrix(3, 1, D_T);

	FILE * temp = fopen("results.txt", "w");

	for (i = 0; i < 11; i++)
	{
		P_y[i] = D_T[0][0] + Y[i]*D_T[0][1] + Y[i]*Y[i]*D_T[0][2];
		fprintf(temp,"%f %f %f\n", Y[i], P_y[i], data[i][0] );
	}

	// Print the error
	printf("\n1990 Population\n Estimate: %f\t  Actual: %f\n", P_y[9], data[9][0]);
	printf("Error = %f\n", data[9][0] - P_y[9]);

	printf("\n2000 Population\n Estimate: %f\t  Actual: %f\n", P_y[10], data[10][0]);
	printf("Error = %f\n", data[10][0] - P_y[10]);

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