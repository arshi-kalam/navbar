void printMatrixValues(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("*****************************************************\n");
    return;
}