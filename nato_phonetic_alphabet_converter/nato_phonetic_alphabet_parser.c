#include <stdio.h>
#include <string.h>

char isTerm(char *term) {
  const char nato[26][8] = {
    "Alpha", "Bravo", "Charlie", "Delta",
    "Echo", "Foxtrot", "Golf", "Hotel",
    "India", "Juliett", "Kilo", "Lima",
    "Mike", "November", "Oscar", "Papa",
    "Quebec", "Romeo", "Sierra", "Tango",
    "Uniform", "Victor", "Whiskey", "X-ray",
    "Yankee", "Zulu"
  };

  char *n,*t;

  for(int x = 0; x < 26; x++){
    n = nato[x];
    t = term;
    while(*n != '\0'){
      if((*n | 0x20) != (*t | 0x20)) {
        break;
      }
      n++;
      t++;
    }
    if(*n == '\0') {
      return (*nato[x]);
    }
  }
  return ('\0');
}


int main(int argc, char *argv[]) {
  char phrase[64];
  char *match;
  char ch;

  if(argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return (1);
  }

  FILE *n = fopen(argv[1], "r");

  while(!feof(n)) {
    fgets(phrase, 64, n);
    match = strtok(phrase, " .-,?\"!");
    while (match) {
      if((ch = isTerm(match)) != '\0') {
        putchar(ch);
      }
      match = strtok(NULL, " .-,?\"!");
    }
  }

  putchar('\n');

  return (0);

}