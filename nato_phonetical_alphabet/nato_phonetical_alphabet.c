#include <stdio.h>

#define ASCII_LOWER_CASE_A 97
#define ASCII_LOWER_CASE_Z 122
#define ASCII_UPPER_CASE_A 65
#define ASCII_UPPER_CASE_Z 90
#define ALPHABET_LENGTH 26
#define PHONETIC_INDEX_LENGTH 124
#define ASCII_UPPER_CASE_TO_LOWER_CASE_DIFFERENCE 32


int main() {

  char natoPhoneticAlphabet[ALPHABET_LENGTH][8] = {
      "Alpha","Bravo","Charlie","Delta",
      "Echo","Foxtrot","Golf","Hotel",
      "India","Juliett","Kilo","Lima",
      "Mike","November","Oscar","Papa",
      "Quebec","Romeo","Sierra","Tango",
      "Uniform","Victor","Whiskey","X-ray",
      "Yankee","Zulu"
  };


  char input_char;

  // Get input_char from input
  printf("Enter a string: ");

  while ((input_char = getchar()) != '\n') {
    if (input_char >= ASCII_UPPER_CASE_A && input_char <= ASCII_UPPER_CASE_Z) {
      input_char = input_char + ASCII_UPPER_CASE_TO_LOWER_CASE_DIFFERENCE;
    }
    if (input_char >= ASCII_LOWER_CASE_A && input_char <= ASCII_LOWER_CASE_Z) {
      printf("%s-", natoPhoneticAlphabet[input_char - ASCII_LOWER_CASE_A]);
    } else {
      putchar(input_char);
    }
  }
  printf("\n");

  return 0;
}