#include "utils/common.h"

int 
str_in_array(char *s, char *a[], size_t size) {
  int i = 0;
  
  while (i < size) {
    if (strcmp(s, a[i]) == 0) { 
      return i;
    }
    ++i;
  }
  
  return -1;
}

int
int_in_array(int n, int a[], size_t size) {
  int i = 0;
  
  while (i < size) {
    if (n == a[i]) { 
      return i;
    }
    ++i;
  }
  
  return -1;
}
