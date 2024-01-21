#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256
#define NUMBER_OF_RECORDS 100
#define FILE_PATH "./pithy.txt"

int main() {
  const char filename[] = FILE_PATH;
  FILE *fp;
  char buffer[BSIZE];
  char *r, *entry;
  int items = 0;
  int saying;
  char **list_base;

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf(stderr, "Unable to open file %s\n", filename);
    exit(1);
  }

  list_base = (char **)malloc(sizeof(char *) * NUMBER_OF_RECORDS);
  if (list_base == NULL)
  {
    fprintf(stderr,"Unable to allocate memory\n");
    exit(1);
  }
  

  while (!feof(fp)) {
    r = fgets(buffer, BSIZE, fp);
    if (r == NULL) {
      break;
    }
    entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
    if (entry == NULL) {
      printf(stderr, "Unable to allocate memory\n");
      exit(1);
    }
    strcpy(entry, buffer);
    *(list_base + items) = entry;
    items++;

    if(items%100 == 0) {
      list_base = (char **) realloc(list_base, sizeof(char *) * (items+NUMBER_OF_RECORDS));
      if( list_base == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);

      }
    }
  }

  fclose(fp);

  srand((unsigned)time(NULL));
  saying = rand() % (items - 1);
  printf("%s", *(list_base+saying));

  free(list_base);
  return (0);
}