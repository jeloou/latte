#include <string.h>
#include <sys/types.h>

#include "utils/common.h"

int 
str_in_array(char *s, const char *a[], size_t size) {
  unsigned int i = 0;
  
  while (i < size) {
    if (strcmp(s, a[i]) == 0) { 
      return i;
    }
    ++i;
  }
  
  return -1;
}

int 
int_in_array(int n, const int a[], size_t size) {
  unsigned int i = 0;
  
  while (i < size) {
    if (n == a[i]) { 
      return i;
    }
    ++i;
  }
  
  return -1;
}

int 
char_in_array(char c, const char a[], size_t size) {
  unsigned int i = 0;
  
  while (i < size) {
    if (c == a[i]) { 
      return i;
    }
    ++i;
  }
  
  return -1;
}
