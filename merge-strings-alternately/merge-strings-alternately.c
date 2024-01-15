#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXECUTION_PER_RUN 5

// Method that merges both strings together;
char* mergeStringsAlternately(const char *word1, const char *word2) {
  size_t length1 = strlen(word1);
  size_t length2 = strlen(word2);

  char *merged = malloc((length1 + length2) + 1);

  int idx = 0;
  int i = 0;

  while (i < length1 && i <  length2) {
    merged[idx++] = word1[i];
    merged[idx++] = word2[i];
    i++;
  }

  while(i < length1) {
    merged[idx++] = word1[i];
    i++;
  }

  while(i < length2) {
    merged[idx++] = word2[i];
    i++;
  }

  merged[idx] = '\0';

  return (char*) merged;

}

void clearScreen() {
    //Introduce a pause
    printf("Press any key to clear screen...\n");
    getchar();
    getchar(); //To clear newline character from input buffer

    //clear screen
    printf("\033[H\033[J");
}

// Get user arguments
int main(void) {
    int runs = 0;
    char word1[50];
    char word2[50];

    while(runs < MAX_EXECUTION_PER_RUN) {
      printf("Hello, so you want to merge words together right?\n");
      printf("To exit this program type ctrl+c\n");
      printf("Type the first word: ");
      scanf("%s", word1);
      printf("Type the second word: ");
      scanf("%s", word2);

      char* merged = mergeStringsAlternately( word1, word2);

      printf("This is the new word you have created: %s\n", merged);

      // Wait for the user to enter any key then clear the screen
      clearScreen();

      free(merged);
      ++runs;
    }
    return 0;
}