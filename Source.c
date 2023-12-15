#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "supporting code/matrixMultipication.c"
#include "supporting code/assignMatrixValues.c"
#include "supporting code/printMatrixValues.c"
#include "supporting code/storeInText.c"

int main()
{
    int row1, col1, row2, col2;
    int lower = 1, upper = 2; // generate random values
    long double cpu_time_used = 0.0;
    struct timeval start, end;
    char matrix1FileName[] = "matrix data/matrix1Data.txt", matrix2FileName[] = "matrix data/matrix2Data.txt", resultantMatrixData[] = "matrix data/resultantMatrixData.txt";
    printf("please enter row1, column1, column2 values\n");
    scanf("%d %d %d", &row1, &col1, &col2);
    row2 = col1;
    int **matrix1 = (int **)malloc((row1) * sizeof(int *));
    for (int i = 0; i < row1; i++)
        matrix1[i] = (int *)malloc((col1) * sizeof(int));
    int **matrix2 = (int **)malloc((row2) * sizeof(int *));
    for (int i = 0; i < row2; i++)
        matrix2[i] = (int *)malloc((col2) * sizeof(int));
    int **resultantMatrix = (int **)malloc((row1) * sizeof(int *));
    for (int i = 0; i < row1; i++)
        resultantMatrix[i] = (int *)malloc((col2) * sizeof(int));

    // Use current time as
    // seed for random generator
    srand(time(0));
    assignMatrixValues(matrix1, row1, col1, lower, upper);
    assignMatrixValues(matrix2, row2, col2, lower, upper);
    if (gettimeofday(&start, NULL) < 0)
        exit(2);
    matrixMultipication(matrix1, matrix2, resultantMatrix, row1, col1, row2, col2);
    if (gettimeofday(&end, NULL) < 0)
        exit(2);
    cpu_time_used = ((double)((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000000);
    // printMatrixValues(matrix1, row1, col1);
    // printMatrixValues(matrix2, row2, col2);
    // printMatrixValues(resultantMatrix, row1, col2);
    printf("Time taken by function: seconds %Le\n", cpu_time_used);
    storeInText(matrix1, row1, col1, matrix1FileName);
    storeInText(matrix2, row2, col2, matrix2FileName);
    storeInText(resultantMatrix, row1, col2, resultantMatrixData);
    return 0;
}
