/*
** Sprite.h for  in /home/dewitt_t//Mario_Tech/Mario_Alpha/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Fri Jun  8 00:16:15 2012 thomas dewitte
** Last update Fri Jun  8 01:49:58 2012 thomas dewitte
*/

#ifndef	__SPRITE_H__
# define __SPRITE_H__

# include "GenericList.h"
# include "SDL/SDL.h"

typedef enum spriteName {
    BLOC,
    MARIO,
    GOOMBA
}	spriteName;

typedef struct	s_sprite
{
  char		*filename;
  spriteName	type;
  SDL_Rect	spritePosition;
  SDL_Surface	*sprite;
}		t_sprite;

DEFINE_LIST(t_sprite*, spriteList)

#endif	/* __SPRITE_H__ */
