#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 4   // change this to solve for other n (e.g. 8)

char board[N][N];   // chessboard
int solution = 0;

// check if it's safe to place a queen at board[row][col]
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

// recursive function to place queens row by row
void nQueens(int row, int n)
{
    if (row == n)
    {
        // print one solution
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
    // initialize board with '.'
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';

    nQueens(0, N);
    printf("Total solutions = %d\n", solution);
    return 0;
}
