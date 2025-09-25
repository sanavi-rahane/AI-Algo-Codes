#include <stdio.h>
#include <string.h>

char checkWinner(char p1, char p2) {
    if (p1 == p2) return 'D'; // Draw
    if ((p1 == 's' && p2 == 'w') || (p1 == 'w' && p2 == 'g') || (p1 == 'g' && p2 == 's'))
        return '1'; // Player 1 wins
    else
        return '2'; // Player 2 wins
}

int main() {
    char p1, p2, winner;
    printf("Welcome to Snake Water Gun Game!\n");
    printf("Choose s for Snake, w for Water, g for Gun\n");

    printf("Player 1, enter your choice: ");
    scanf(" %c", &p1);
    printf("Player 2, enter your choice: ");
    scanf(" %c", &p2);

    winner = checkWinner(p1, p2);

    if (winner == 'D')
        printf("It's a Draw!\n");
    else
        printf("Player %c wins!\n", winner);

    return 0;
}
