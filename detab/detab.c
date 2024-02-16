#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER   1024
#define SPACE        ' '
#define TAB_CHARACTER          '\t'

int CalculateNumberOfSpaces(int Offset, int TabSize) {
  return TabSize - (Offset % TabSize);
}

int get_line(char line[], int limit) {
  int ch, i;

  // Read characters into line[] until limit is reached, EOF is encountered, or a newline ch is read
  for (i = 0; i < limit - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i) {
    line[i] = ch;
  }

  // If a newline ch was read, add it to the line
  if (ch == '\n') {
    line[i] = ch;
    ++i;
  }

  // Null-terminate the line
  line[i] = '\0';

  // Return the length of the line
  return i;
}

int main(int argc, char *argv[]) {
  printf("Type a phrase\n");
  char Buffer[MAX_BUFFER];
  // Set the tab size based on the command line argument, or default to 4
  int TabSize = argv[1] ? atoi(argv[1]) : 4;

  int ch, numSpaces, spaceIndex, outputLength;

  // Process each line of input
  while (get_line(Buffer, MAX_BUFFER) > 0) {
    // Process each character in the line
    for (ch = 0, outputLength = 0; Buffer[ch] != '\0'; ch++) {
      if (Buffer[ch] == TAB_CHARACTER) {
        // If the character is a tab, calculate the number of spaces to output
        numSpaces = CalculateNumberOfSpaces(outputLength, TabSize);
        // Output the calculated number of spaces
        for (spaceIndex = 0; spaceIndex < numSpaces; spaceIndex++) {
          putchar(SPACE);
          outputLength++;
        }
      } else {
        // If the character is not a tab, output it as is
        putchar(Buffer[ch]);
        outputLength++;
      }
    }
  }

  return 0;
}