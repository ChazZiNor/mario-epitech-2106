#include <math.h>
#include <sys/types.h>

#include "Transform.h"
#include "MapSerializer.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "GameEngine.h"
#include "RigidBody.h"

typedef void (*physicsBehaviour)(GameObject*);

static void
isGroundedPhysics(GameObject* this) {
  this->physics->gravityForce = 1.0f;
}

static int
myRound(float nb) {
  int res = nb - (int)nb;

  if (res > 0.5f) return nb + (1 - res);
  else return (int)nb;
}

static void
isFallingPhysics(GameObject* this) {
  this->physics->gravityForce += 0.1f;
  this->transform.position.x += myRound(this->physics->gravityForce);
  updateMap(this);
}

static void
isInWaterPhysics(GameObject* this) {
  this->transform.position.x += this->physics->gravityForce;
}

static physicsBehaviour physicsCallback[] =
  {
    0,
    &isGroundedPhysics,
    &isFallingPhysics,
    &isInWaterPhysics,
  };

void
RigidBodyBehaviour(GameObject* this) {
  if (physicsCallback[this->physics->physicsState]) physicsCallback[this->physics->physicsState](this);
}
