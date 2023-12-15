#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "supporting code/matrixMultipicationPar.c"
#include "supporting code/assignMatrixValues.c"
#include "supporting code/printMatrixValues.c"
#include "supporting code/storeInTextPar.c"

int main()
{
    int row1, col1, row2, col2;
    long double cpu_time_used = 0.0;
    struct timeval start, end;
    char matrix1FileName[] = "matrix data/matrix1Data.txt", matrix2FileName[] = "matrix data/matrix2Data.txt", resultantMatrixData[] = "matrix data/resultantMatrixData.txt";
    char matrix1FileNamePar[] = "matrix data Par/matrix1DataPar.txt", matrix2FileNamePar[] = "matrix data Par/matrix2DataPar.txt", resultantMatrixDataPar[] = "matrix data Par/resultantMatrixDataPar.txt";
    ifstream inFile1(matrix1FileName);
    inFile1 >> row1;
    inFile1 >> col1;
    ifstream inFile2(matrix2FileName);
    inFile2 >> row2;
    inFile2 >> col2;
    int **matrix1 = (int **)malloc((row1) * sizeof(int *));
    for (int i = 0; i < row1; i++)
        matrix1[i] = (int *)malloc((col1) * sizeof(int));

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            inFile1 >> matrix1[i][j];
        }
    }
    int **matrix2 = (int **)malloc((row2) * sizeof(int *));
    for (int i = 0; i < row2; i++)
        matrix2[i] = (int *)malloc((col2) * sizeof(int));
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            inFile2 >> matrix2[i][j];
        }
    }
    inFile1.close();
    inFile2.close();
    int **resultantMatrix = (int **)malloc((row1) * sizeof(int *));
    for (int i = 0; i < row1; i++)
        resultantMatrix[i] = (int *)malloc((col2) * sizeof(int));
    if (gettimeofday(&start, NULL) < 0)
        exit(2);
    matrixMultipicationPar(matrix1, matrix2, resultantMatrix, row1, col1, row2, col2);
    if (gettimeofday(&end, NULL) < 0)
        exit(2);
    cpu_time_used = ((double)((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000000);
    // printMatrixValues(matrix1, row1, col1);
    // printMatrixValues(matrix2, row2, col2);
    // printMatrixValues(resultantMatrix, row1, col2);
    printf("Time taken by function: seconds %Le\n", cpu_time_used);
    storeInTextPar(matrix1, row1, col1, matrix1FileNamePar);
    storeInTextPar(matrix2, row2, col2, matrix2FileNamePar);
    storeInTextPar(resultantMatrix, row1, col2, resultantMatrixDataPar);
    return 0;
}
