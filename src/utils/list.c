#include <stdlib.h>

#include "utils/list.h"

void lt_list_init(lt_list_t *l) {
  l->head = NULL;
  l->tail = NULL;
  l->i = NULL;
  l->len = 0;
}

void lt_list_push(lt_list_t *l, void *v) {
  lt_list__node_t *n;
  
  n = malloc(sizeof(*n));
  n->next = NULL;
  n->v = v;

  if (l->tail == NULL) {
    l->tail = l->head = n;
    return;
  }

  l->tail->next = n;
  l->tail = n;
  l->len++;
}

void *lt_list_pop(lt_list_t *l) {
  lt_list__node_t *n;
  void *v;
  
  if (l->tail == NULL) {
    return NULL;
  }

  n = l->tail;
  l->tail = n->prev;
  l->tail->next = NULL;
  l->len--;
  
  v = n->v;
  free(n);
  
  return v;
}

void *lt_list_last(lt_list_t *l) {
  if (l->tail != NULL) {
    return l->tail->v;
  }

  return NULL;
}


