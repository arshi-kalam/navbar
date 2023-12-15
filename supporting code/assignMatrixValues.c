void assignMatrixValues(int **matrix, int row, int col, int lower, int upper)
{
    int num;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            num = (rand() % (upper - lower + 1)) + lower;
            matrix[i][j] = num;
        }
    }
    return;
}