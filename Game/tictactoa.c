#include <stdio.h>
 char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int spaceIsFree(int a,int b)
{

    if(board[a][b]==' ')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

int main() {

    printBoard();

   
    printf("Player = O And Bot = X");
    printf("first move is for Player O");
    char player = 'O';
    char bot = 'X';

    int row;
    int col;
    //  printf("Enter position as row and col (0 2): ");
    //  scanf("%d %d",&row, &col);
   for(int i=1;i<100;i++)
   {
            do{
                    printf("Enter position as row and col (0 2): ");
                    scanf("%d %d",&row, &col);
                        if(spaceIsFree(row,col)) //if true then insert,check conditon 
                        { 

                            if (i%2==0)
                                board[row][col] = player;
                                printf("your move inserted");
                                printf("\n");
                                //check is is it winning
                                printBoard();
                        }
                        else{
                            printBoard();
                            printf("space is not free.Enter Another Position");
                        }
            }while (condition) //until win or tie
            // {
            //     /* code */
            // }
            
   }
    return 0;
}
