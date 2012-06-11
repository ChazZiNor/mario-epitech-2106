/*
** Graphic.h for  in /u/all/vangys_c/public/mario/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Thu Jun  7 15:43:22 2012 thomas dewitte
** Last update Thu Jun  7 18:16:55 2012 thomas dewitte
*/

#ifndef		GRAPHIC_H__
# define	GRAPHIC_H__

typedef	int	SDLKey;

typedef struct	s_input
{
  SDLKey	token;
  void		(*func)();
}		t_input;

typedef struct	s_sprite
{
  int		x;
  int		y;
  SDL_Surface	*sprite;
}		t_sprite;

#endif		/* GRAPHIC_H */
