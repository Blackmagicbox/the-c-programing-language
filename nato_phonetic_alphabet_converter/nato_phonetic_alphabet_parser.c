#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
  char ch;
  int offset = 0;
  char word[64];

  if(argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return (1);
  }

  FILE *n = fopen(argv[1], "r");
  if(n == NULL) {
    perror("open");
    return (1);
  }

  while((ch = fgetc(n)) != EOF) {
    if( isalpha(ch)) {
      word[offset++] = ch;
      if(offset >= 64) {
        printf("Word too long, buffer overflow\n");
        return (1);
      }
    } else if(offset > 0) {
      word[offset] = '\0';
      putchar(isTerm(word));
      offset = 0;
    }
  }

  putchar('\n');

  return (0);

}