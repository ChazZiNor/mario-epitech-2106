#ifndef __GAME_ENGINE_H__
# define __GAME_ENGINE_H__

# include "GenericList.h"

DEFINE_LIST(GameObject*, GameObjectList)

typedef struct s_gameEngine {
  GameObjectList*	_gameObjects;
  Map			_map;
}		GameEngine;

GameObjectList*	findObjectsByTags(GameEngine*);
GameObject*	findObjectsById(int);

void		gameEngineUpdate(GameEngine*);
void            updateMap(GameObject *this);

#endif
