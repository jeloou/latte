#include <stdlib.h>
#include <string.h>

#include "buffer.h"

void lt_buffer_init(lt_buffer_t *buf, int capacity) {
  buf->capacity = capacity;
  buf->offset = 0;
  buf->len = 0;
  
  buf->data = malloc(capacity);
  if (buf->data == NULL) {
    return -1;
  }
  
  return 0;
}

iovec_t *lt_buffer_to_iovec(lt_buffer_t bufs[], int nbufs) {
  iovec_t io_bufs[nbufs];
  iovec_t *_io_bufs;
  
  int i = 0;
  while (i < nbufs) {
    iovec_t io_buf;
    
    io_buf.iov_base = bufs[i].data;
    io_buf.iov_len = bufs[i].capacity;
    
    io_bufs[i] = io_buf;
    i++;
  }
  
  _io_bufs = malloc(nbufs * sizeof(iovec_t));
  memcpy(_io_bufs, io_bufs, nbufs * sizeof(iovec_t));
  
  return _io_bufs;
}
