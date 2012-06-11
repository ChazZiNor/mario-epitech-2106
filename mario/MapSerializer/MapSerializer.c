#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "Transform.h"
#include "coord.h"
#include "Physics.h"
#include "enumGameObject.h"
#include "MapSerializer.h"
#include "gameObject.h"
#include "GameEngine.h"

extern GameEngine* gameEngine;

static char __map[][6]= {
  {NONE, GOOMBA, NONE, NONE, NONE, NONE},
  {NONE, NONE, NONE, NONE, NONE, NONE},
  {NONE, NONE, MARIO, NONE, NONE, GROUND},
  {GROUND, GROUND, GROUND, GROUND, GROUND, GROUND},
};

static void
fillMap(int start_i, int start_j, gameObjectType type) {
  GameObject*	t;
  int		id;

  if (type != 0) {
    t = instanciateGameObject(type, start_i, start_j);
    gameEngine->_gameObjects = list_push_front(GameObjectList, gameEngine->_gameObjects, t);
    id = t->id;
  } else {
    id = -1;
  }

  int end_i = start_i + 3;
  int end_j = start_j + 3;
  int save_j = start_j;

  while (start_i != end_i) {
    start_j = save_j;
    while (start_j != end_j) {
      gameEngine->_map._map[start_i][start_j] = id;
      ++start_j;
    }
    ++start_i;
  }
}

void
MapSerializer_serialize(void) {

  gameEngine->_map._map = malloc((4 * 3) * sizeof(char*));
  gameEngine->_map.xSize = 4 * 3;
  gameEngine->_map.ySize = 6 * 3;
  for (int i = 0; i != 4 * 3; ++i) {
    gameEngine->_map._map[i] = malloc(6 * 3);
    gameEngine->_map._map[i] = memset(gameEngine->_map._map[i], -1, 6 * 3);
  }
  for (int i = 0, map_i = 0; i != 4; ++i, map_i += 3) {
    for (int j = 0, map_j = 0; j != sizeof(__map[i]); ++j, map_j += 3) {
      fillMap(map_i, map_j, __map[i][j]);
    }
  }
}

