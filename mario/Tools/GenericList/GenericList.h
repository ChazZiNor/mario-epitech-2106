#ifndef __GENERIC_LIST_H__
# define __GENERIC_LIST_H__


# include <stdlib.h>
# include <string.h>

#define DEF #define
#define MACRO(name) DEF

#define DEFINE_LIST(A, TYPENAME)					\
  typedef struct TYPENAME {						\
    A			value;						\
    struct TYPENAME*	next;						\
  } TYPENAME;	       							\
  struct TYPENAME *push_front_##TYPENAME(struct TYPENAME *list, A value); \
  struct TYPENAME *push_back_##TYPENAME(struct TYPENAME *list, A value); \
  void foreach_##TYPENAME(struct TYPENAME *list, void (*func_ptr)(A*));	\
  A get_elem_##TYPENAME(struct TYPENAME* list, A*, int (*func_ptr)(A*, A*));

# define list_push_front(TYPENAME, list, node) push_front_##TYPENAME(list, node)
# define list_push_back(TYPENAME, list, node) push_back_##TYPENAME(list, node)
# define list_foreach(TYPENAME, list, func) foreach_##TYPENAME(list, func)
# define list_get_elem(TYPENAME, list, pattern, func) get_elem_##TYPENAME(list, pattern, func)


#define DEFINE_LIST_FUNC(A, TYPENAME)					\
  struct TYPENAME *push_front_##TYPENAME(struct TYPENAME *list, A value) { \
  struct TYPENAME *new_elem = malloc(sizeof(struct TYPENAME));		\
  new_elem->next = list;						\
  memcpy(&new_elem->value, &value, sizeof(value));			\
  return new_elem; }							\
  									\
 struct TYPENAME *push_back_##TYPENAME(struct TYPENAME *list, A value) { \
   struct TYPENAME *new_elem = malloc(sizeof(struct TYPENAME));		\
   struct TYPENAME * tmp = list;					\
  									\
  new_elem->next = 0;							\
  memcpy(&new_elem->value, &value, sizeof(value));			\
  if (tmp != 0) {							\
    while (tmp->next != 0) {						\
      tmp = tmp->next;							\
    }									\
    tmp->next = new_elem;						\
  }									\
  else {								\
    return new_elem;							\
  }									\
  return list;								\
}									\
									\
 void foreach_##TYPENAME(struct TYPENAME *list, void (*func_ptr)(A*)) {	\
  while (list) {							\
    func_ptr(&(list->value));						\
    list = list->next;							\
  }									\
}									\
 									\
 A get_elem_##TYPENAME(struct TYPENAME* list, A* t, int (*func_ptr)(A*, A*)) { \
   while (list) {							\
     if (func_ptr(&list->value, t)) return list->value;			\
     list = list->next;							\
   }									\
   return 0;								\
 }									\


#endif
