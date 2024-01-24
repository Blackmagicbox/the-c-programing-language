#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char sometext[64];
  char *match;

  printf("Enter some text: ");
  fgets(sometext, 64, stdin);

  match = strtok(sometext, " ");

  while (match)
  {
    printf("%s\n", match);
    match = strtok(NULL, " ");
  }

  return (0);

}