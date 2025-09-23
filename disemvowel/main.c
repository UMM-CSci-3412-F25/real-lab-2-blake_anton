#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t size = 0;

  while (getline(&line, &size, stdin) > 0 ) {
    char *dis = disemvowel(line);
    if (dis) {
       printf("%s\n", dis);
       free((void*) dis);
    }
  }
  free((void*) line);
  return 0;
}
