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

int split_lines(char *buffer, char lines[TASK_LIMIT][MAX_LINE_LENGTH]) {
  long nl = 0; // keep count of the current line
  long i = 0; // iterator

  char c; // current character

  while( (c = buffer[i])) {
    if (c == '\n') {
      lines[nl][i] = '\0';
      nl++;
    }

    else {
      lines[nl][i] = c;
    }

    i++;
  }

  return 0;
}

int print_array (char arr[TASK_LIMIT][MAX_LINE_LENGTH]) {
  size_t s = sizeof(arr) / sizeof(arr[0]);

  for (size_t i = 0; i < s; i++) {
    for (int j = 0; arr[i][j]; j++)
      printf("%c", arr[i][j]);
    printf("\n");
  }

  return 0;
}


int main () {
  char buffer[MAX_FILE_LENGTH];
  char lines[TASK_LIMIT][MAX_LINE_LENGTH];

  if (!read_file(FILE_PATH, buffer)) {
    if (!split_lines(buffer, lines)) {
      printf("Length of array: %zd\n", sizeof(lines) / sizeof(lines[0]));

      /* print_array(lines); */
    }
  }

  return 0;
}
