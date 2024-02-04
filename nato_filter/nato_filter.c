#include <ctype.h>
#include <stdio.h>

void printUsage() {
  // Get stdin from the user or from a pipe and put the output to a file
  printf("Usage: nato_filter < input.txt | stdin\n" );
}


int main(const int argc, char *argv[]) {

  if(argc > 1) {
    printUsage();
    return 1;
  }

  char *nato[] = {
      "Alpha",  "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};
  char ch;

  // Replace characters by their NATO phonetic alphabet and put to a file named
  // natoed-text.txt
  FILE *fp = fopen("natoed-text.txt", "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      fprintf(fp, "%s ", nato[toupper(ch) - 'A']);
    } else {
      // Put non-alphabetic characters as they are to the file
      fprintf(fp, "%c", ch);
    }
  }
  // Add a newline character to the file
  fprintf(fp, "\n");
  fclose(fp);

  printf("Done! Check the file natoed-text.txt\n");
  
  return 0;
}
