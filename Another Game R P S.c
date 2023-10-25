#include <stdio.h>
#include <stdlib.h> // mem aloc.
#include <time.h> //work time
#include <stdbool.h> //bool tru false
#include <string.h> // String man.

// Function to get the computer's choice (Rock, Paper, or Scissors)
char getComputerChoice() {
    char choices[] = {'R', 'P', 'S'};
    int randomIndex = rand() % 3;
    return choices[randomIndex];
}

// Function to determine the winner of the game
char getWinner(char playerChoice, char computerChoice) {
    if (playerChoice == computerChoice)
        return 'T'; // Tie

    if ((playerChoice == 'R' && computerChoice == 'S') ||
        (playerChoice == 'P' && computerChoice == 'R') ||
        (playerChoice == 'S' && computerChoice == 'P'))
        return 'P'; // Player wins

    return 'C'; // Computer wins
}

int main() {
    char playerChoice, computerChoice;
    char choiceName[10];
    int playerScore = 0, computerScore = 0;
    bool continueGame = true;

    srand(time(NULL));

    printf("Welcome to the Rock, Paper, Scissors Game!\n");

    while (continueGame) {
        printf("Enter your choice (R for Rock, P for Paper, S for Scissors, Q to quit): ");
        scanf(" %c", &playerChoice);

        // Convert the player's choice to uppercase
        playerChoice = toupper(playerChoice);

        // Check if the player wants to quit
        if (playerChoice == 'Q') {
            continueGame = false;
            break;
        }

        // Validate the player's choice
        if (playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S') {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Get the computer's choice
        computerChoice = getComputerChoice();

        // Determine the winner
        char winner = getWinner(playerChoice, computerChoice);

        // Display the choices and the result
        printf("You chose: %c\n", playerChoice);
        printf("Computer chose: %c\n", computerChoice);

        if (winner == 'T') {
            printf("It's a tie!\n");
        } else if (winner == 'P') {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        printf("Current Score: You %d - %d Computer\n", playerScore, computerScore);
        printf("\n");
    }

    // Display the final score
    printf("Final Score: You %d - %d Computer\n", playerScore, computerScore);
    printf("Thank you for playing!\n");

    return 0;
}
