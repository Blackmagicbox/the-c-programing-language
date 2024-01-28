#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_lives(int lives) {
  printf("Lives: ");
  for (int i = 0; i < lives; i++) {
    printf("❤️ ");
  }
  printf("\n");
}

int main(void) {
  char *word = "TERMINATOR";
  char display[strlen(word)+1];

  for (int i = 0; i <= strlen(word); i++) {
    display[i] = '_';
  }
  display[strlen(word)] = '\0';

  char guess;
  int correct_guess = 0;
  int lives = 5;

  // Clear the Screen
  printf("\033[H\033[J");

  // Print the game state
  printf("Guess the word:\n");
  printf("%s\n", display);
  print_lives(lives);


  while ((guess = getchar()) != '0' && lives >0 && correct_guess < strlen(word)) {
    if(guess == '\n') continue;

    char guessToUpper = toupper(guess);
    int hasTheLetter = 0;
    for (int i = 0; i < strlen(word); i++) {
      if (guessToUpper == word[i]) {
        display[i] = word[i];
        hasTheLetter ^= 1;
        break;
      }
    }

    if (hasTheLetter) {
      for (int i = 0; i < strlen(word); i++) {
        if (guessToUpper == word[i]) {
          display[i] = word[i];
          correct_guess++;
          continue;
        }
      }
    } else {
      lives--;
    }

    // Clear the Screen
    printf("\033[H\033[J");

    // Print the game state
    printf("Guess the word:\n");
    printf("%s\n", display);
    print_lives(lives);
  }

  if (lives < 0) {
    printf("You loose!\n");
  } else if (correct_guess == strlen(word)) {
    printf("You won!\n");
  } else {
    printf("The player quit the game.\n");
  }
  return 0;
}