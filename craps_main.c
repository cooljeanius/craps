/*
 * Eric Gallager
 *
 * Problem:
 * 
 * We want you to make a Craps simulator.
 * You are required to have at least one user defined function in the code (Perhaps for example a int rollDice() function).
 * You might recall rules for Craps
 * 
 * Roll Two 6 sided dice.
 * * 7 or 11 on the first roll -> player wins.
 * * 2, 3, or 12 on the first roll -> player loses
 * * 4,5,6,8,9,10 -> the value becomes the player's 'point'. The player must roll that value before they roll a 7 in order to win.
 *
 * #(Output example)
 * 
 * ./Craps 
 * Players rolls 6+5=11
 * Player wins
 *
 * ./Craps
 * Player rolls 6+6=12
 * Player loses
 * 
 * ./Craps
 * Player rolls 4+6=10
 * Point is 10
 * Player rolls 4+2=6
 * Player rolls 5+6=11
 * Player rolls 3+3=6
 * Player rolls 5+5=10
 * Player wins
 * 
 * ./
 * Player rolls 2+2=4
 * Point is 4
 * Player rolls 4+1=5
 * Player rolls 6+3=9
 * Player rolls 4+6=10
 * Player rolls 5+4=9
 * Player rolls 1+2=3
 * Player rolls 6+1=7
 * Player loses
 *
 * --- 
 * 
 * Algorithm:
 *
 * 1. Dice rolling function
 * 2. Main function
 * 3. ???
 * 4. Profit
 *
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> // needed for rand() function
#define RAND_MAX 5 // redefining RAND_MAX as 5 instead of 6 because the numbers start at 0 instead of 1. (the redefinition should generate a warning, that's okay)


/* 
 * GenerateRandomNumber = Uses the "time" method to generate a random number
 */
int GenerateRandomNumber(void); // Prototype
int
GenerateRandomNumber (void) {
	int RandomNumber = ((int)time(NULL)) % 5; // Another way of generating a random number, in case rand() isn't working properly
	// printf("\n RandomNumber is %i \n", RandomNumber); // Statement for debugging
	return (RandomNumber);
}

/*
 * Dice rolling function: Rolls the dice
 */
int rollDice(int randmax); // Prototype
int
rollDice(int randmax) {
	int roll1 = 0; // Initialize
	int roll2 = 0; // Initialize
	int roll_value = 0; // Initialize
	char dummy = 0; // Initialize
	int i = 1; // Control (no reason)
	if (i == 1) { // (Remember, "==", not "="!)
		// randmax = RAND_MAX; // making the RAND_MAX constant into a variable because I feel more comfortable working with those
		// printf("\n RAND_MAX = %i \n", randmax); //statement for debugging
		// roll1 = rand(); // first attempt at generating a random number, commented out because it didn't work.
		roll1 = GenerateRandomNumber();
		roll1++; // shifting the range from 0-5 to 1-6
		printf("\n Your first die roll is %i, press any key to continue> ", roll1); // statement for debugging
		scanf("%c", &dummy); // require user input to keep GenerateRandomNumber() from generating the same results (any further scanf's are for backup)
		roll2 = GenerateRandomNumber();
		roll2++; // shifting the range from 0-5 to 1-6
		printf("\n Your second die roll is %i, press any key to continue> ", roll2); // statement for debugging
		scanf("%c", &dummy);
		roll_value = (roll1 + roll2);
		printf("\n The total roll value is: %i + %i = %i \n", roll1, roll2, roll_value); // trying putting this debugging statement within the dice-rolling function to see if it generates different results
		// printf("\n The dice have been rolled! \n"); // generic success message
	} else
		printf("Oops, failed to roll the dice. \n"); // this shouldn't actually ever happen 
	return (roll_value);
}

/*
 * Main function: Makes up the main part of the program
 */
int main (int roll_value) {
    int game_over = 0; // Initialize
	int point = 0; // Initialize (used later)
	int roll_number = 1; // First roll is roll 1
	char dummy = 0; // Initialize
	while (game_over != 1) { // Use while-loop to keep rolling until the game is over
		roll_value = rollDice(5);
		// roll_value = 1; // reassigning a value to it for testing until I can get the rollDice() function to actually generate values of its own
		// printf("\n The total roll value is: %i \n", roll_value); // statement for debugging
		if (roll_number == 1) {
			if (roll_value == 7 || roll_value == 11) { // win condition 
				printf("\n The player wins! :-) \n");
				game_over = 1;
			} else if (roll_value == 2 || roll_value == 3 || roll_value == 12) { // lose condition
				printf("\n The player loses. :-( \n");
				game_over = 1;
			} else if (roll_value != point) { // just using this single condition is easier than doing an "else if" for each other possible roll
				printf("\n %i is the player's point. Press any key to roll again. \n", roll_value);
				scanf("%c", &dummy);
				point = roll_value;
				roll_number++; // to get out of this specific "if"
			} else {
				printf("\n There shouldn't be an ''else''. \n"); // Just in case
				game_over = 1;
			}
		} else if (roll_number > 1) {
			if (roll_value == point) {
				printf("\n The player wins! :-) \n"); // win condition for rolls after the first
				game_over = 1;
			} else if (roll_value == 7) {
				printf("\n The player loses. :-( \n"); // lose condition for rolls after the first
				game_over = 1;
			} else {
				printf("\n Press any key to roll again. \n");
				scanf("%c", &dummy);
				roll_number++;
				// printf("\n This is roll number %i \n", roll_number); // Statement for debugging
			}
		}
	}
	printf(" \n ");
    return 0;
}

// newline \n
