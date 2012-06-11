#ifndef __GENERIC_LIST_H__
# define __GENERIC_LIST_H__

# include <stdlib.h>

#define DEF #define
#define MACRO(name) DEF

#define DEFINE_LIST(A, TYPENAME)					\
  typedef struct TYPENAME {						\
    A*			value;						\
    struct TYPENAME*	next;						\
  } TYPENAME;	       							\
  									\
  struct TYPENAME *push_front_##TYPENAME(struct TYPENAME *list, A value) { \
    struct TYPENAME *new_elem = malloc(sizeof(struct TYPENAME));	\
    new_elem->next = list;						\
    new_elem->value = malloc(sizeof(A));				\
    *new_elem->value = value;						\
    return new_elem; }							\
  									\
  struct TYPENAME *push_back_##TYPENAME(struct TYPENAME *list, A value) { \
    struct TYPENAME *new_elem = malloc(sizeof(struct TYPENAME));	\
    struct TYPENAME * tmp = list;					\
    									\
    new_elem->next = 0;							\
    new_elem->value = malloc(sizeof(A));				\
    *new_elem->value = value;						\
    if (tmp != 0) {							\
      while (tmp->next != 0)	{					\
	tmp = tmp->next;						\
      }									\
      tmp->next = new_elem;						\
    }									\
    else {								\
      return new_elem;							\
    }									\
    return list;							\
  }									\
									\
  void foreach_##TYPENAME(struct TYPENAME *list, void (*func_ptr)(A*)) { \
    while (list) {							\
      func_ptr((list->value));						\
      list = list->next;						\
    }									\
  }									\
  									\
  A *get_elem_##TYPENAME(struct TYPENAME* list, int (*func_ptr)(A*)) {	\
    while (list) {							\
      if (func_ptr(list->value)) return list->value;			\
      list = list->next;						\
    }									\
    return 0;								\
  }									\

#endif
