#ifndef SRC_UTILS_BUFFER_H_
#define SRC_UTILS_BUFFER_H_

#include <sys/uio.h>

typedef struct lt_buffer_s lt_buffer_t;
typedef struct iovec iovec_t;

struct lt_buffer_s {
  unsigned char *data;
  int len;
  int capacity;
  int offset;
};

int lt_buffer_init(lt_buffer_t *buf, int capacity);
iovec_t *lt_buffer_to_iovec(lt_buffer_t bufs[], int nbufs);

#endif
