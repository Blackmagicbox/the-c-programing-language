#include <stdio.h>

#define ASCII_LOWER_CASE_A 97
#define ASCII_LOWER_CASE_Z 122
#define ASCII_UPPER_CASE_A 65
#define ASCII_UPPER_CASE_Z 90
#define ALPHABET_LENGTH 26
#define ASCII_UPPER_CASE_TO_LOWER_CASE_DIFFERENCE 32


int main(int argc, char *argv[]) {

  char nato[ALPHABET_LENGTH][8] = {
      "Alpha", "Bravo", "Charlie", "Delta",
      "Echo", "Foxtrot", "Golf", "Hotel",
      "India", "Juliett", "Kilo", "Lima",
      "Mike", "November", "Oscar", "Papa",
      "Quebec", "Romeo", "Sierra", "Tango",
      "Uniform", "Victor", "Whiskey", "X-ray",
      "Yankee", "Zulu"
  };


  FILE *n;

  char ch;

  if (argc < 2) {
    printf(stderr, "Provide a file name\n");
    return 1;
  }

  n = fopen(argv[1], "r");
  if(n == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  while ((ch = fgetc(n)) != EOF) {
    if (ch >= ASCII_UPPER_CASE_A && ch <= ASCII_UPPER_CASE_Z) {
      ch = ch + ASCII_UPPER_CASE_TO_LOWER_CASE_DIFFERENCE;
    }
    if (ch >= ASCII_LOWER_CASE_A && ch <= ASCII_LOWER_CASE_Z) {
      printf("%s-", nato[ch - ASCII_LOWER_CASE_A]);
    } else {
      putchar(ch);
    }
  }
  printf("\n");

  fclose(n);

  return 0;
}