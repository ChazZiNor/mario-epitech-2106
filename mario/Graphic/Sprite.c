/*
** Sprite.c for  in /home/dewitt_t//Mario_Tech/Mario_Alpha/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Fri Jun  8 00:48:26 2012 thomas dewitte
** Last update Fri Jun  8 16:24:17 2012 thomas dewitte
*/

#include "Sprite.h"
#include "Constante.h"

static int	_typeToCompare;
static spriteList	*list;

static int	_findType(t_sprite *data)
{
  if (data->type == _typeToCompare)
    return (1);
  return (0);
}

t_sprite	*loadSpriteObject(spriteList *list, spriteName type)
{
  t_sprite	*result;

  _typeToCompare = type;
  result = get_elem_spriteList(list, &_findType);
  return (result);
}

void	updateSpritePosition(gameObject *Object)
{
  Object->sprite->spritePosition.x = Object->pos->x * PPB;
  Object->sprite->spritePosition.y = Object->pos->y * PPB;
}

void	addNewSpriteList(spriteList *list, char *filename, spriteName type)
{
  t_sprite	value;

  value.filename = filename;
  value.type = type;
  value.spritePosition.x = 0;
  value.spritePosition.y = 0;
  value.spritePosition.h = 0;
  value.spritePosition.w = 0;
  value.sprite = NULL;
  list = push_front_spriteList(list, value);
  if ((list->sprite = IMG_Load(filename)) == NULL)
    printf("Error IMG_Laod failed or %s doesn't exist\n", filename);
}

void	initSpriteList(void)
{
  addNewSpriteList(list, "filename.png", FILEFORM);
  /* ... */
}

void	applySpriteOnScene(SDL_Surface *scene)
{
  gameObject	*tmp;

  initSpriteList();
  tmp = gameObjectHeadList;
  while (tmp)
    {
      tmp->sprite = loadSpriteObject(list, tmp->type);
      updateSpritePosition(tmp);
      SDL_BlitSurface(tmp->sprite->sprite, NULL, scene, tmp->sprite->spritePosition);
      tmp = tmp->next;
    }
}
