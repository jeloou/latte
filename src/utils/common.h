#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))

int str_in_array(char *s, char *a[], size_t size);
int int_in_array(int n, int a[], size_t size);

#endif
