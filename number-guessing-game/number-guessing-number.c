#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int number = 97;

    printf("Guess the number!\n");
    printf("Enter a number between 1 and 100 or 'q' to quit\n");

    int guess = 0;
    while (guess != number) {
        char input[10];
        printf("Your guess: ");
        fgets(input, 10, stdin);

        if (input[0] == 'q') {
            printf("Quitting...\n");
            exit(0);
        }

        guess = atoi(input);

        if (guess < number) {
            printf("Too low!\n");
        } else if (guess > number) {
            printf("Too high!\n");
        } else {
            printf("Correct!\n");
        }
    }

}
