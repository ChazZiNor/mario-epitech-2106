#include <stdlib.h>
#include <sys/types.h>

#include "Transform.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"

typedef Physics *(*physics_func_ptr)(GameObject*);
typedef void (*update_func_ptr)(GameObject*);
static unsigned int id = 0;

static Physics*
return_zero_physics(GameObject* g) {
  (void)g;
  return (0);
}

static void
return_zero_update(GameObject* g) {
  (void)g;
}

static physics_func_ptr physics_init_ptr[] = {
  return_zero_physics,
  return_zero_physics,
  return_zero_physics,
  instanciatePhysics,
  instanciatePhysics,
};

static update_func_ptr physics_init[] = {
  return_zero_update,
  return_zero_update,
  return_zero_update,
  return_zero_update,
};

GameObject*
instanciateGameObject(gameObjectType type, int x, int y) {
  GameObject* t = malloc(sizeof(GameObject));

  t->id = id;
  ++id;
  t->type = type;
  t->transform.position.x = x;
  t->transform.position.y = y;
  t->sizeX = 3;
  t->sizeY = 3;
  t->speed = 1;
  t->update = 0;
  t->physics = physics_init_ptr[t->type](t);
  return (t);
}

void
gameObjectUpdate(GameObject* this) {
  this->update(this);
}
