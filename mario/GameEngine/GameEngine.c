#include <sys/types.h>

#include "Transform.h"
#include "MapSerializer.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "GameEngine.h"

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
  printf("Updating : %d\n", (*g)->id);
  if ((*g)->update) (*g)->update(*g);
  if ((*g)->physics) (*g)->physics->physicsState = perception((*g));
  if ((*g)->physics) { (*g)->physics->physicsUpdate(*g);
    printf("Updating Physics : %d\n", (*g)->id);
  }
}

void
gameEngineUpdate(GameEngine* this) {
  char buf[512];

  list_foreach(GameObjectList, this->_gameObjects, &updateForeach);
  for (int i = 0; i != 4 * 3; ++i) {
    for (int j = 0; j != 6 * 3; ++j) {
      if (gameEngine->_map._map[i][j] != -1 && findObjectsById(gameEngine->_map._map[i][j])->type == 4)
        printf("type = %d coord = %d - %d\n", findObjectsById(gameEngine->_map._map[i][j])->type, findObjectsById(gameEngine->_map._map[i][j])->transform.position.x, findObjectsById(gameEngine->_map._map[i][j])->transform.position.y);
    }
    printf("\n");
  }
  read(0, buf, 1);
}
