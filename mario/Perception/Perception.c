#include <stdlib.h>
#include <stdbool.h>

#include "Transform.h"
#include "coord.h"
#include "Physics.h"
#include "MapSerializer.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "GameEngine.h"

extern GameEngine*      gameEngine;

static enum e_state
lookBackward(Coord coord) {
  if (coord.y - 3 > gameEngine->_map.ySize) return 0;
  if (gameEngine->_map._map[coord.x][coord.y - 3] != -1 &&
      findObjectsById(gameEngine->_map._map[coord.x][coord.y - 3])->type == WATER) return (isInWater);
  return (0);
}

static enum e_state
lookForward(Coord coord) {
  if (coord.y + 3 > gameEngine->_map.ySize) return 0;
  if (gameEngine->_map._map[coord.x][coord.y + 3] != -1 && findObjectsById(gameEngine->_map._map[coord.x][coord.y + 3])->type == WATER) return (isInWater);
  return (0);
}

static enum e_state
lookDown(Coord coord) {
  if (coord.x + 3 > gameEngine->_map.xSize) return 0;
  if (gameEngine->_map._map[coord.x + 3][coord.y] != -1 && findObjectsById(gameEngine->_map._map[coord.x + 3][coord.y])->type == GROUND) return (isGrounded);
  else if (gameEngine->_map._map[coord.x + 3][coord.y] == -1) return (isFalling);
  return (0);
}

static enum e_state
findState(Coord coord, enum e_state state) {
  if (lookForward(coord) == isInWater || lookBackward(coord) == isInWater) return (isInWater);
  else
    state = lookDown(coord);
  return (state);
}

enum e_state
perception(struct s_gameobject *this) {
  enum e_state state = 0;

  if (this->physics->physicsUpdate != 0) { state = findState(this->transform.position, state);
    return (state);
  }
  return (0);
}
