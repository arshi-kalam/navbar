#include <fstream>
using namespace std;
void storeInText(int **matrix, int row, int col, char *fileName)
{
    ofstream outFile;
    outFile.open(fileName);
    outFile << row << " ";
    outFile << col << "\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            outFile << matrix[i][j] << " ";
        }
        outFile << "\n";
    }
    outFile.close();
    return;
}