#ifndef SRC_UTILS_LIST_H_
#define SRC_UTILS_LIST_H_

typedef struct lt_list_s lt_list_t;
typedef struct lt_list__node_s lt_list__node_t;

struct lt_list__node_s {
  lt_list__node_t *next;
  lt_list__node_t *prev;
  void *v;
};
  
struct lt_list_s {
  lt_list__node_t *head;
  lt_list__node_t *tail;
  lt_list__node_t *i;
  int len;
};

void lt_list_init(lt_list_t *l);
void lt_list_push(lt_list_t *l, void *v);
void *lt_list_last(lt_list_t *l);
void *lt_list_pop(lt_list_t *l);
int lt_list_has_next(lt_list_t *l);
void *lt_list_next(lt_list_t *l);

#endif /* SRC_LIST_H_ */
