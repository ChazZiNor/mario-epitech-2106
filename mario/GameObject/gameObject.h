#ifndef __GAMEOBJECT_H__
# define __GAMEOBJECT_H__

# define GROUNDTAG 0b0000000000000000000000000000000000000000000000000000000000000001
# define PLAYERTAG 0b0000000000000000000000000000000000000000000000000000000000000010
# define ENNEMYTAG 0b0000000000000000000000000000000000000000000000000000000000000100

typedef struct	s_gameobject {
  unsigned int		id;
  short			speed;
  size_t		sizeX;
  size_t		sizeY;
  Transform             transform;
  gameObjectType	type;
  int                   tags;

  Physics		*physics;

  void			(*update)(struct s_gameobject *);
}		GameObject;

GameObject	*instanciateGameObject(gameObjectType type, int x, int y);

#endif
