#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "Transform.h"
#include "MapSerializer.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "GameEngine.h"
#include "Perception.h"

extern GameEngine* gameEngine;

DEFINE_LIST_FUNC(GameObject*, GameObjectList)

static int
findById(GameObject** g, GameObject** pattern) {
  if ((*g)->id == (*pattern)->id) return 1;
  return 0;
}

GameObject*
findObjectsById(int id) {
  GameObject *pattern;

#warning optimize ptr GameObject
  pattern = malloc(sizeof(GameObject));
  pattern->id = id;
  return list_get_elem(GameObjectList, gameEngine->_gameObjects, &pattern, &findById);
}

static void
updateForeach(GameObject** g) {
  if ((*g)->update) (*g)->update(*g);
  if ((*g)->physics) (*g)->physics->physicsState = perception((*g));
  if ((*g)->physics) { (*g)->physics->physicsUpdate(*g);
  }
}

void
updateMap(GameObject *this) {
  printf("toUpdate = %d %d\n", this->transform.position.x, this->transform.position.y);
  char                  tmp;
  unsigned int           i = this->transform.position.x - 1;
  unsigned int           j = this->transform.position.y;

  while (j < this->transform.position.y + 3) {
    tmp = gameEngine->_map._map[i + 3][j];
    gameEngine->_map._map[i + 3][j] = gameEngine->_map._map[i][j];
    gameEngine->_map._map[i][j] = tmp;
    j++;
  }

  for (int i = 0; i != 4 * 3; ++i) {
    for (int j = 0; j != 6 * 3; ++j) {
      printf("\t%d", gameEngine->_map._map[i][j]);
    }
    printf("\n");
  }
  printf("\n\n\n\n\n\n\n");
}

void
gameEngineUpdate(GameEngine* this) {
  list_foreach(GameObjectList, this->_gameObjects, &updateForeach);

  char buf[512];

  read(1, buf, 1);
#warning debug physics
  /* for (int i = 0; i != 4 * 3; ++i) { */
  /*   for (int j = 0; j != 6 * 3; ++j) { */
  /*     if (gameEngine->_map._map[i][j] != -1 && findObjectsById(gameEngine->_map._map[i][j])->type == 4) */
  /*       printf("type = %d coord = %d - %d\n", findObjectsById(gameEngine->_map._map[i][j])->type, findObjectsById(gameEngine->_map._map[i][j])->transform.position.x, findObjectsById(gameEngine->_map._map[i][j])->transform.position.y); */
  /*   } */
  /* } */
}
