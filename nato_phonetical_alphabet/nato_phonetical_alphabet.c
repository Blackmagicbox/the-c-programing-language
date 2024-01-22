#include <stdio.h>

#define ASCII_LOWER_CASE_A 97
#define ASCII_LOWER_CASE_Z 122
#define ASCII_UPPER_CASE_A 65
#define ASCII_UPPER_CASE_Z 90
#define ALPHABET_LENGTH 26
#define PHONETIC_INDEX_LENGTH 124
#define ASCII_UPPER_CASE_TO_LOWER_CASE_DIFFERENCE 32


int main() {
  char nato[ALPHABET_LENGTH][8] = {
      "Alpha",
      "Bravo",
      "Charlie",
      "Delta",
      "Echo",
      "Foxtrot",
      "Golf",
      "Hotel",
      "India",
      "Juliett",
      "Kilo",
      "Lima",
      "Mike",
      "November",
      "Oscar",
      "Papa",
      "Quebec",
      "Romeo",
      "Sierra",
      "Tango",
      "Uniform",
      "Victor",
      "Whiskey",
      "X-ray",
      "Yankee",
      "Zulu"
  };

  char phrase[64];
  char ch = ' ';

  
  printf("Enter a word or phrase: ");
  fgets(phrase,64, stdin);


  int i = 0;
  while(phrase[i]) {
    ch = toupper(phrase[i]);
    if(isalpha(ch)) {
      printf("%s-", nato[ch - 'A']);
    }
    i++;
    if(i== 64) {
      break;
    }
  }
  putchar('\n');
  
  return (0);
}