#include <stdio.h>
#include <string.h>


// Method that merges both strings together;
char* mergeStringsAlternately(const char *word1, const char *word2){
  int length1 = strlen(word1);
  int length2 = strlen(word2);

  char merged[(length1 + length2) + 1];

  int idx = 0;
  for(int i = 0; i <= length1 - 1; i++) {
    merged[idx] = word1[i];
    idx += 2;
  }

  idx = 1;
  for(int j = 0; j <= length2 - 1; j++) {
    merged[idx] = word2[j];
    idx +=2;
  }

  merged[length1 + length2] = '\0';


  return (char*) merged;

}


// Get user arguments
int main(void) {

    char word1[50];
    char word2[50];

    printf("Hello, so you want to merge words together right?\n");
    printf("To exit t his program type ctrl+c\n");
    printf("Type the first word: ");
    scanf("%s", word1);
    printf("Type the second word: ");
    scanf("%s", word2);

    char* merged = mergeStringsAlternately( word1, word2);

    printf("This is the new word you have created: %s\n", merged);

    return 0;
}