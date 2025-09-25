#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 4   

char board[N][N];  
int solution = 0;

bool isSafe(int row, int col, int n)
{
    int i, j;

    // horizontal check (same row)
    for (j = 0; j < n; j++)
        if (board[row][j] == 'Q')
            return false;

    // vertical check (same column)
    for (i = 0; i < n; i++)
        if (board[i][col] == 'Q')
            return false;

    // left diagonal (↖)
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // right diagonal (↗)
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}


void nQueens(int row, int n)
{
    if (row == n)
    {
        
        solution++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", board[i][j]);
            printf("\n");
        }
        printf("----\n");
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 'Q';
            nQueens(row + 1, n);
            board[row][col] = '.';
        }
    }
}

int main(void)
{
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';

    nQueens(0, N);
    printf("Total solutions = %d\n", solution);
    return 0;
}
