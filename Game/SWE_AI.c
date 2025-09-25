#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getComputerChoice() {
    int randNum = rand() % 3;
    if (randNum == 0) return 's'; // Snake
    else if (randNum == 1) return 'w'; // Water
    else return 'g'; // Gun
}

char checkWinner(char user, char comp) {
    if (user == comp) return 'D'; // Draw
    if ((user == 's' && comp == 'w') || 
        (user == 'w' && comp == 'g') || 
        (user == 'g' && comp == 's'))
        return 'U'; // User wins
    else
        return 'C'; // Computer wins
}

int main() {
    char user, comp, winner;

    // Seed the random number generator once
    srand((unsigned int)time(NULL));

    printf("=== Snake Water Gun Game vs Computer ===\n");
    printf("Choose:\n s - Snake\n w - Water\n g - Gun\n");

    printf("Your choice: ");
    scanf(" %c", &user);

    // Get computer's random choice
    comp = getComputerChoice();
    printf("Computer chose: %c\n", comp);

    // Determine the winner
    winner = checkWinner(user, comp);

    if (winner == 'D')
        printf("Result: It's a Draw!\n");
    else if (winner == 'U')
        printf("Result: You Win!\n");
    else
        printf("Result: Computer Wins!\n");

    return 0;
}
