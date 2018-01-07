#include <stdio.h>

#include "main.h"

#define FILE_PATH "db.txt"

#define DEBUG 1

// Reada file into a char buffer
int read_file (char *path, char *buffer) {
  FILE *fp;
  fp = fopen(path, "r");

  long nc = 0; // keep count of characters
  char c; // current character

  while( (c = fgetc(fp)) != EOF) {
    
    // too long, index + null terminator
    if (nc > (MAX_FILE_LENGTH -2)) {
      printf("the input is too long\n");
      fclose(fp);

      return -1;
    }


    buffer[nc] = c;
    nc++;
  }

  // null terminate
  buffer[nc] = '\0';

  fclose(fp);

  return 0;
}

int main () {
  char buffer[MAX_FILE_LENGTH];

  if(!read_file(FILE_PATH, buffer)) {
    printf("%s", buffer);
  }

  return 0;
}
