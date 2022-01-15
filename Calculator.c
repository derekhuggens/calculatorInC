/* Calculator */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define SIZE 3

// Prototypes
double add(double nums[], int size);
double averaging(double nums[], int size);
double divide(double nums[], int size);
char getArrayOperatorResult(char userChoice);
char getMenuChoice();
bool getNumbers(double numbers[], int size);
double largestCalculating(double nums[], int size);
double multiply(double nums[], int size);
double posNegZeroCalculating(double nums[]);
bool processMenu(char userChoice, bool gotNumbers, double numbers[], int size, double average,
	double largest, double posNegZero);
double subtract(double nums[], int size);
double zeroCheck(double nums[], int size, bool foundZero);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Displays menu with choices and processes menu choices.
 * Return Value:	An integer representing an error code; if the program ends without error, zero
 *					will be returned to the calling program or operating system.
 */
int main() {
	// Variables
	double numbers[SIZE] = { 0.0 };
	char userChoice = 0;
	bool gotNumbers = false;
	double average1 = 0, largest1 = 0, posNegZero1 = 0;

	do {
		// Menu Display and Input
		userChoice = getMenuChoice();

		// Menu Processing
		gotNumbers = processMenu(userChoice, gotNumbers, numbers, SIZE, average1, largest1, posNegZero1);
	} while (userChoice != 'e' && userChoice != 'E');

	return 0;
}

/*
 * Name:			add()
 * Parameters:		nums	Stores an array of all the entered numbers.
 *					size	Determines array size.
 * Processes:		Computes the addition of all the entered numbers.
 * Return Value:	result.
 */
double add(double nums[], int size) {
	// Variables
	double result = 0.0;
	int i = 0;

	// Calculation
	result = nums[0];
	for (i = 1; i < size; i++) {
		result += nums[i];
	}

	return result;
}

/*
 * Name:			averaging()
 * Parameters:		nums	Stores an array of all the entered numbers.
 *					size	Determines array size.
 * Processes:		Computes the average of all entered numbers.
 * Return Value:	average.
 */
double averaging(double nums[], int size) {
	// Variables
	double result = 0.0;
	int i = 0;
	double sum = 0.0;
	double average = 0.0;
	int count = 1;

	// Calculation
	sum = nums[0];
	for (i = 1; i < size; i++) {
		sum += nums[i];
		count++;
	}
	average = sum / count;

	return average;
}

/*
 * Name:			divide()
 * Parameters:		nums	Stores an array of all the entered numbers.
 *					size	Determines array size.
 * Processes:		Computes the division of all the entered numbers.
 * Return Value:	result.
 */
double divide(double nums[], int size) {
	// Variables
	double result = 0.0;
	int i = 0;

	// Calculation
	result = nums[0];
	for (i = 1; i < size; i++) {
		result /= nums[i];
	}

	return result;
}

/*
* Professor Stendel, I cannot figure out how to get this function working with only
* one return statement.
*/

/*
 * Name:			getArrayOperatorResult()
 * Parameters:		userChoice	Gets the user's calculator menu choice.
 * Processes:		Prints the appropriate operator sign.
 * Return Value:	operator.
 */
 
/*
char getArrayOperatorResult(char userChoice) {
	char add = '+';
	// Output
	if (userChoice == 'a' || 'A') {
		printf("%c", add);
	}

	return add;
}*/

/*
 * Name:			getMenuChoice()
 * Parameters:		None.
 * Processes:		Displays the calculator menu and prompts for menu input.
 * Return Value:	userChoice.
 */
char getMenuChoice() {
	// Variables
	char userChoice = 0;

	// Menu Display and Input
	printf("\nCalculator Menu\n\n");
	printf("(G)et multiple numbers.\n");
	printf("(A)dd.\n");
	printf("(S)ubtract.\n");
	printf("(M)ultiply.\n");
	printf("(D)ivide.\n");
	printf("a(V)erage.\n");
	printf("(L)argest number.\n");
	printf("(P)ostive, negative, or zero.\n");
	printf("(E)xit program.\n\n");
	printf("Choice: ");
	scanf_s(" %c", &userChoice, 1);

	return userChoice;
}

/*
 * Name:			getNumbers()
 * Parameters:		numbers		Stores an array of all the entered numbers.
 *					size		Determines array size.
 * Processes:		Prompts for the input of numbers.
 * Return Value:	true.
 */
bool getNumbers(double numbers[], int size) {
	// Variables
	int i = 0;

	// Input
	printf("\nEnter %d numbers separated with a space: ", size);
	for (i = 0; i < size; i++) {
		scanf_s("%lf", &numbers[i]);
	}
	
	// Tells the calling function, numbers were acquired.
	return true;
}

/*
 * Name:			largestCalculating()
 * Parameters:		nums	Stores an array of all the entered numbers.
 *					size	Determines array size.
 * Processes:		Determines the largest of the entered numbers.
 * Return Value:	largest.
 */
double largestCalculating(double nums[], int size) {
	// Variables
	double largest = 0.0;
	int i = 0;

	// Calculation
	largest = nums[0];
	for (i = 1; i < size; i++) {
		if (nums[i] > largest) {
			largest = nums[i];
		}
	}

	return largest;
}

/*
 * Name:			multiply()
 * Parameters:		nums	Stores an array of all the entered numbers.
 *					size	Determines array size.
 * Processes:		Computes the multiplication of all the entered numbers.
 * Return Value:	result.
 */
double multiply(double nums[], int size) {
	// Variables
	double result = 0.0;
	int i = 0;

	// Calculation
	result = nums[0];
	for (i = 1; i < size; i++) {
		result *= nums[i];
	}

	return result;
}

/*
 * Name:			posNegZeroCalculating()
 * Parameters:		nums	Stores an array of all the entered numbers.
 * Processes:		Determines whether the reulting answer is positive, negative, or zero.
 * Return Value:	nums[i].
 */
double posNegZeroCalculating(double nums[]) {
	// Variable
	int i = 0;

	// Determination
	for (i = 0; i < SIZE; i++) {
		if (nums[i] > 0) {
			// Output - Positive
			printf("\n%f is a positive number.", nums[i]);
		} else if (nums[i] < 0) {
			// Output - Negative
			printf("\n%f is a negative number.", nums[i]);
		} else {
			// Output - Zero
			printf("\n%f is zero.", nums[i]);
		}
	}
	printf("\n");

	return nums[i];
}

/*
 * Name:			processMenu()
 * Parameters:		userChoice	The user choice letter from the calculator menu.
 *					gotNumbers	Determines whether numbers were entered or not.
 *					numbers		Stores an array of all the entered numbers.
 *					size		Determines array size.
 *					average		Stores the average of all the entered numbers.
 *					largest		Stores the largest of all the entered numbers.
 *					posNegZero	Determines whether the resulting answer is positive, negative,
 *								or zero.
 * Processes:		Executes input selections.
 * Return Value:	gotNumbers.
 */
bool processMenu(char userChoice, bool gotNumbers, double numbers[], int size, double average,
	double largest, double posNegZero) {
	// Variables
	double result = 0.0;
	bool foundZero = false;
	int i = 0;
	
	// Menu Processing
	switch (userChoice) {
		// Number Input
		case 'G':
		case 'g':
			// Got Numbers - True or False
			gotNumbers = getNumbers(numbers, size);
			break;
		// Addition
		case 'A':
		case 'a':
			// Validation - Got Numbers True
			if (gotNumbers == true) {
				// Calculation
				result = add(numbers, size);

				// Output
				printf("\nAnswer: ");
				for (i = 0; i < size - 1; i++) {
					printf("%.3f + ", numbers[i]);
				}
				printf("%.3f = %.3f\n", numbers[i], result);
			} else {
				// Error
				printf("\n\tError: Select G from the menu first!\n");
			}
			break;
		// Subtraction
		case 'S':
		case 's':
			// Validation - Got Numbers True
			if (gotNumbers == true) {
				// Calculation
				result = subtract(numbers, size);

				// Output
				printf("\nAnswer: ");
				for (i = 0; i < size - 1; i++) {
					printf("%.3f - ", numbers[i]);
				}
				printf("%.3f = %.3f\n", numbers[i], result);
			} else {
				// Error
				printf("\n\tError: Select G from the menu first!\n");
			}
			break;
		// Multiplication
		case 'M':
		case 'm':
			// Validation - Got Numbers
			if (gotNumbers == true) {

				// Calculation
				result = multiply(numbers, size);

				// Output
				printf("\nAnswer: ");
				for (i = 0; i < size - 1; i++) {
					printf("%.3f * ", numbers[i]);
				}
				printf("%.3f = %.3f\n", numbers[i], result);
			} else {
				// Error
				printf("\n\tError: Select G from the menu first.\n");
			}
			break;
		// Division
		case 'D':
		case 'd':
			// Validation - Got Numbers
			if (gotNumbers == true) {
				// Validation - Cannot Divide by Zero
				foundZero = zeroCheck(numbers, size, foundZero);

				// Validation - Found Zero
				if (foundZero != true) {
					// Calculations
					result = divide(numbers, size);

					// Output
					printf("\nAnswer: ");
					for (i = 0; i < size - 1; i++) {
						printf("%.3f / ", numbers[i]);
					}
					printf("%.3f = %.3f\n", numbers[i], result);
				} else {
					// Error
					printf("\n\tError! Cannot divide by zero!\n");

					// Found Zero Reset
					foundZero = false;
				}
			} else {
				// Error
				printf("\n\tError: Select G from the menu first!\n");
			}
			break;
		// Average
		case 'V':
		case 'v':
			// Validation - Got Numbers
			if (gotNumbers == true) {
				// Calculation
				average = averaging(numbers, size);

				// Output
				printf("\nAnswer: (");
				for (i = 0; i < size - 1; i++) {
					printf("%.3f + ", numbers[i]);
				}
				printf("%.3f) / %d = %.3f\n", numbers[i], size, average);
			} else {
				// Error
				printf("\n\tError: Select G from the menu first.\n");
			}
			break;
		// Largest Numbers
		case 'L':
		case 'l':
			// Validation - Got Numbers
			if (gotNumbers == true) {
				// Determination - Largest
				largest = largestCalculating(numbers, size);

				// Output
				printf("\nThe largest number is %.3f.\n", largest);
			} else {
				// Error
				printf("\n\tError: Select G from the menu first.\n");
			}
			break;
		// Postive, Negative or Zero
		case 'P':
		case 'p':
			// Validation - Got Numbers
			if (gotNumbers == true) {
				// Determination
				posNegZero = posNegZeroCalculating(numbers);

			} else {
				// Error
				printf("\n\tError: Select G from the menu first.\n");
			}
			break;
		// Exit Menu
		case 'E':
		case 'e':
			// Output - Good-Bye Message
			printf("\nThank you for using Derek's simple calculator! Good-bye!\n");
			break;
		// Switch Default
		default:
			// Output - Invalid Menu Choice
			printf("\n\tError: Invalid choice!\n");
	}

	return gotNumbers;
}

/*
 * Name:			subtract()
 * Parameters:		nums	Stores an array.
 *					size	Determines array size.
 * Processes:		Computes the subtraction of all the array numbers.
 * Return Value:	result.
 */
double subtract(double nums[], int size) {
	// Variables
	double result = 0.0;
	int i = 0;

	// Calculation
	result = nums[0];
	for (i = 1; i < size; i++) {
		result -= nums[i];
	}

	return result;
}

/*
 * Name:			zeroCheck()
 * Parameters:		nums		Stores an array.
 *					size		Determines array size.
 *					foundZero	Proof for 0 in an array.
 * Processes:		Validates if any of the entered numbers are equal to zero.
 * Return Value:	foundZero.
 */
double zeroCheck(double nums[], int size, bool foundZero) {
	// Variable
	int i = 0;

	// Validation - Cannot Divide by Zero
	for (i = 1; i < size && foundZero != true; i++) {
		if (nums[i] == 0) {
			foundZero = true;
		}
	}

	return foundZero;
}
