#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))

int str_in_array(char *s, const char *a[], size_t size);
int int_in_array(int n, const int a[], size_t size);
int char_in_array(char n, const char a[], size_t size);

#endif
