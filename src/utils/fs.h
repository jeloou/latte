#ifndef SRC_UTILS_FS_H_
#define SRC_UTILS_FS_H_

#include <errno.h>
#include <sys/stat.h>

#include "buffer.h"

typedef struct lt_fs_s lt_fs_t;
typedef int lt_file;

typedef enum {
  LT_FS_OPEN,
  LT_FS_CLOSE,
  LT_FS_READ,
  LT_FS_WRITE
} lt_fs_type;

struct lt_fs_s {
  lt_fs_type fs_type;
  lt_file file;
  mode_t mode;
  int flags;
  const char *path;
  ssize_t result;
  off_t off;
  unsigned int nbufs;
  lt_buffer_t *bufs;
};

int lt_fs_open(lt_fs_t *req, const char *path, int flags, int mode);
int lt_fs_read(lt_fs_t *req, lt_file file, lt_buffer_t bufs[], unsigned int nbufs, off_t off);
int lt_fs_write(lt_fs_t *req, const char *path, lt_file file);
int lt_fs_close(lt_fs_t *req, lt_file file);

#endif
