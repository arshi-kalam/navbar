#include <omp.h>
#define threadNo 20
using namespace std;
void matrixMultipicationPar(int **matrix1, int **matrix2, int **resultantMatrix, int row1, int col1, int row2, int col2)
{
    int i, j, k;
    omp_set_num_threads(threadNo);
#pragma omp parallel for private(i, j, k) shared(matrix1, matrix2, resultantMatrix)
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
