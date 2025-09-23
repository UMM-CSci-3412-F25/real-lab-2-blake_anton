#include <stdlib.h>
#include <ctype.h>
#include "disemvowel.h"
int is_vowel(char c) {
	c = tolower(c);
	return (c == 'a' || c ==  'e' || c == 'i' || c == 'o' || c == 'u');
}


char *disemvowel(char *str) {
  if (!str) return NULL;
  int count = 0;
  for (char *p = str; *p; p++)
	  if (!is_vowel(*p)) count++;


  char *result = (char*) malloc(count + 1);
  if (!result) return NULL;

  char *ptr = result;
  for(char *p = str; *p; p++) 
	  if (!is_vowel(*p)) 
		  *ptr++ = *p;
  *ptr = '\0';

  return result;
}
