#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char player1 = 'X';
char player2 = 'O';

void printBoard() {
    printf("\n");
    printf("%c | %c | %c\n", board[1], board[2], board[3]);
    printf("--+---+--\n");
    printf("%c | %c | %c\n", board[4], board[5], board[6]);
    printf("--+---+--\n");
    printf("%c | %c | %c\n\n", board[7], board[8], board[9]);
}

bool spaceIsFree(int pos) {
    return board[pos] == ' ';
}

bool checkWin(char mark) {
    return (board[1]==mark && board[2]==mark && board[3]==mark) ||
           (board[4]==mark && board[5]==mark && board[6]==mark) ||
           (board[7]==mark && board[8]==mark && board[9]==mark) ||
           (board[1]==mark && board[4]==mark && board[7]==mark) ||
           (board[2]==mark && board[5]==mark && board[8]==mark) ||
           (board[3]==mark && board[6]==mark && board[9]==mark) ||
           (board[1]==mark && board[5]==mark && board[9]==mark) ||
           (board[3]==mark && board[5]==mark && board[7]==mark);
}

bool checkDraw() {
    for (int i = 1; i <= 9; i++) {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

void insertLetter(char letter, int pos) {
    if (spaceIsFree(pos)) {
        board[pos] = letter;
    } else {
        printf("Position already taken! Try again: ");
        int newPos;
        scanf("%d", &newPos);
        insertLetter(letter, newPos);
    }
}

int main() {
    int pos;
    printBoard();
    printf("Positions are numbered as:\n");
    printf("1 2 3\n4 5 6\n7 8 9\n\n");

    while (true) {
       //here player 1 will pLy
        printf("Player 1 (X), enter position: ");
        scanf("%d", &pos);
        insertLetter(player1, pos);
        printBoard();
        if (checkWin(player1)) {
            printf("Player 1 (X) wins!\n");
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }

        //here player 2 will play
        printf("Player 2 (O), enter position: ");
        scanf("%d", &pos);
        insertLetter(player2, pos);
        printBoard();
        if (checkWin(player2)) {
            printf("Player 2 (O) wins!\n");
            break;
        }
        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
