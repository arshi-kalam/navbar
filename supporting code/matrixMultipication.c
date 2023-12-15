void matrixMultipication(int **matrix1, int **matrix2, int **resultantMatrix, int row1, int col1, int row2, int col2)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            resultantMatrix[i][j] = 0;
            for (k = 0; k < row2; k++)
            {
                resultantMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
