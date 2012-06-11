#include <sys/types.h>

#include "Transform.h"
#include "coord.h"
#include "Physics.h"
#include "enumGameObject.h"
#include "MapSerializer.h"
#include "gameObject.h"
#include "GameEngine.h"

GameEngine* gameEngine;

int
main() {
  gameEngine = malloc(sizeof(*gameEngine));
  MapSerializer_serialize();
  while (1) gameEngineUpdate(gameEngine);
}
