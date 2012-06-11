#include "IntList.h"
#include "CoordList.h"
#include <stdio.h>



/* int list functions */
void
inc(int* a) {
  *a += 1;
}

void
displayInt(int* a) {
  printf("%d\n", *a);
}

int
find_3(int *i) {
  return 3 == *i;
}

/* coord list functions */
void
displayCoord(t_coord* t) {
  printf("Coord : %d %d %d\n", t->x, t->y, t->z);
}

int
find_coord(t_coord* t) {
  if (t->x == 1 && t->y == 2 && t->z == 3)
    return 1;
  return 0;
}

int
main() {
  /* Int list test */
  int_list* list = 0;

  list = push_front_int_list(list, 2);
  list = push_back_int_list(list, 3);
  list = push_front_int_list(list, 1);

  foreach_int_list(list, &displayInt);
  /*printf("After Inc\n");
  foreach_int_list(list, &inc);
  foreach_int_list(list, &displayInt);
  printf("found : %d\n", *(get_elem_int_list(list, &find_3)));
  */


  /* Coord list test */
  coord_list* coordlist = 0;

  t_coord toto = {1, 2, 3};
  coordlist = push_front_coord_list(coordlist,
				    toto);

  t_coord toto2 = {4, 5, 6};
  coordlist = push_back_coord_list(coordlist,
				    toto2);

  foreach_coord_list(coordlist, &displayCoord);

  t_coord* result = get_elem_coord_list(coordlist, &find_coord);
  if (result) {
    printf("found\n");
  }
}
