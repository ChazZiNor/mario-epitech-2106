#include <stdlib.h>
#include <stdbool.h>

#include "Transform.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "RigidBody.h"

typedef void (*physicsFuncPtr)(GameObject*);

static void
NoPhysics(GameObject* g) {
  (void)g;
}

static physicsFuncPtr physicsFunctions[] = {
  &NoPhysics,
  &NoPhysics,
  &NoPhysics,
  &RigidBodyBehaviour,
  &RigidBodyBehaviour,
  0
};

Physics*
instanciatePhysics(GameObject* g) {
  Physics *t = malloc(sizeof(Physics));

  t->physicsState = NOPHYSICS;
  t->physicsUpdate = physicsFunctions[g->type];
  t->gravityForce = 1;
  return (t);
}
