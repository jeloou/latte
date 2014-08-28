#include <errno.h>
#include <stdio.h>

#include "fs.h"
#include "utils/common.h"

#define INIT(type)								\
  do {									        \
    (req)->fs_type = LT_FS_ ## type;					        \
    (req)->result = 0;							        \
    (req)->path = NULL;						                \
  } while (0)

int lt_fs_open(lt_fs_t *req, const char *path, int flags, int mode) {
  ssize_t r;
  
  INIT(OPEN);
  
  req->path = path;
  req->flags = flags;
  req->mode = mode;
  
  r = open(req->path, req->flags, req->mode);
  req->result = r;
  if (r >= 0) {
    return req->result;
  }

  req->result = -errno;
  return req->result;
}

int lt_fs_read(lt_fs_t *req, lt_file file, lt_buffer_t bufs[], unsigned int nbufs, off_t off) {
  ssize_t r;

  INIT(READ);
  req->file = file;

  req->nbufs = nbufs;
  req->bufs = bufs;
  req->off = off;

  iovec_t *io_bufs = NULL;
  if (req->nbufs > 1) {
    io_bufs = lt_buffer_to_iovec(req->bufs, req->nbufs);
  }
  
  if (off < 0) {
    if (req->nbufs > 1) {
      r = readv(req->file, io_bufs, req->nbufs);
    } else {
      r = read(req->file, bufs[0].data, bufs[0].capacity);
    }
  } else {
    if (req->nbufs > 1) {
      r = preadv(req->file, io_bufs, req->nbufs, req->off);
    } else {
      r = pread(req->file, bufs[0].data, bufs[0].capacity, req->off);
    }
  }

  if (io_bufs != NULL) {
    free(io_bufs);
  }
  
  req->result = r;
  if (r >= 0) {
    return req->result;
  }

  req->result = -errno;
  return req->result;
}

int lt_fs_close(lt_fs_t *req, lt_file file) {
  int r;

  INIT(CLOSE);
  req->file = file;
  
  r = close(req->file);
  if (r >= 0) {
    return req->result;
  }

  req->result = -errno;
  return req->result;
}
  
