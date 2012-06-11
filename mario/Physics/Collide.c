#include <stdlib.h>
#include <stdbool.h>

#include "Transform.h"
#include "MapSerializer.h"
#include "Physics.h"
#include "coord.h"
#include "enumGameObject.h"
#include "gameObject.h"
#include "GameEngine.h"

typedef bool (*func_ptr)(Coord *coord);
typedef bool (*check_tag_ptr)(int);

extern GameEngine*	gameEngine;

static bool
groundTagCheck(int tags) {
  if ((tags & GROUNDTAG) == GROUNDTAG) return true;
  return false;
}

static bool
ennemyTagCheck(int tags) {
  if ((tags & ENNEMYTAG) == ENNEMYTAG) return true;
  return false;
}

static check_tag_ptr checkTagFuncs[] = {
  &groundTagCheck,
  &ennemyTagCheck,
  0
};

static bool
ground_collide(Coord *coord) {
  if (findObjectsById(gameEngine->_map._map[coord->x][coord->y])->type == GROUND) return true;
  return false;
}

static bool
ennemy_collide(Coord *coord) {
  if (findObjectsById(gameEngine->_map._map[coord->x][coord->y])->type == GOOMBA) return true;
  return false;
}

static func_ptr g_collide_test[] = {
  &ground_collide,
  &ennemy_collide,
  0
};

bool
collide(Coord *coord, int tags) {
  for (int i = 0; i != sizeof(checkTagFuncs); ++i) {
    if (checkTagFuncs[i](tags) && g_collide_test[i](coord)) return true;
  }
  return false;
}
