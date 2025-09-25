#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char board[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char player = 'O';
char bot = 'X';

void printBoard() {
    printf("%c|%c|%c\n", board[1], board[2], board[3]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", board[4], board[5], board[6]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n\n", board[7], board[8], board[9]);
}

bool spaceIsFree(int pos) {
    return board[pos] == ' ';
}

bool checkWhichMarkWon(char mark) {
    if ((board[1]==mark && board[2]==mark && board[3]==mark) ||
        (board[4]==mark && board[5]==mark && board[6]==mark) ||
        (board[7]==mark && board[8]==mark && board[9]==mark) ||
        (board[1]==mark && board[4]==mark && board[7]==mark) ||
        (board[2]==mark && board[5]==mark && board[8]==mark) ||
        (board[3]==mark && board[6]==mark && board[9]==mark) ||
        (board[1]==mark && board[5]==mark && board[9]==mark) ||
        (board[3]==mark && board[5]==mark && board[7]==mark))
        return true;
    return false;
}

bool checkForWin() {
    return checkWhichMarkWon(player) || checkWhichMarkWon(bot);
}

bool checkDraw() {
    for (int i = 1; i <= 9; i++) {
        if (board[i] == ' ')
            return false;
    }
    return true;
}

int minimax(bool isMaximizing) {
    if (checkWhichMarkWon(bot)) return 1;
    if (checkWhichMarkWon(player)) return -1;
    if (checkDraw()) return 0;

    if (isMaximizing) {
        int bestScore = -800;
        for (int i = 1; i <= 9; i++) {
            if (board[i] == ' ') {
                board[i] = bot;
                int score = minimax(false);
                board[i] = ' ';
                if (score > bestScore)
                    bestScore = score;
            }
        }
        return bestScore;
    } else {
        int bestScore = 800;
        for (int i = 1; i <= 9; i++) {
            if (board[i] == ' ') {
                board[i] = player;
                int score = minimax(true);
                board[i] = ' ';
                if (score < bestScore)
                    bestScore = score;
            }
        }
        return bestScore;
    }
}

void insertLetter(char letter, int pos) {
    if (spaceIsFree(pos)) {
        board[pos] = letter;
        printBoard();

        if (checkWhichMarkWon(letter)) {
            if (letter == bot) {
                printf("Bot wins!\n");
            } else {
                printf("Player wins!\n");
            }
            exit(0);
        }

        if (checkDraw()) {
            printf("Draw!\n");
            exit(0);
        }
    } else {
        printf("Can't insert there! Enter new position: ");
        int newPos;
        scanf("%d", &newPos);
        insertLetter(letter, newPos);
    }
}

void compMove() {
    int bestScore = -800;
    int bestMove = 0;

    for (int i = 1; i <= 9; i++) {
        if (board[i] == ' ') {
            board[i] = bot;
            int score = minimax(false);
            board[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    insertLetter(bot, bestMove);
}

void playerMove() {
    int pos;
    printf("Enter the position for 'O': ");
    scanf("%d", &pos);
    insertLetter(player, pos);
}

int main() {
    printBoard();
    printf("Computer goes first! Good luck.\n");
    printf("Positions are as follows:\n");
    printf("1, 2, 3\n");
    printf("4, 5, 6\n");
    printf("7, 8, 9\n\n");

    while (!checkForWin()) {
        compMove();
        playerMove();
    }

    return 0;
}
