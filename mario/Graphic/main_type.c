/*
** main_type.c for  in /u/all/vangys_c/public/mario/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Thu Jun  7 11:18:16 2012 thomas dewitte
** Last update Thu Jun  7 18:17:37 2012 thomas dewitte
*/


#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Constantes.h"

static const int	SCREEN_BPP = 32;

/* static t_input		g_input[] = */
/*   { */
/*     {SDLK_UP,}, */
/*     {SDLK_DOWN,}, */
/*     {SDLK_RIGHT,}, */
/*     {SDLK_LEFT,}, */
/*     {SDLK_SPACE,} */
/*   }; */

SDL_Surface	*change_mario_sprite()
{
}

void		Exec_Game(SDL_Surface *screen)
{
  SDL_Event	event;
  SDL_Rect	imagePosition;
  SDL_Rect	spritePosition;
  SDL_Surface	*menu = NULL;
  SDL_Surface	*sprite_test;
  static int	game = 1;

  imagePosition.x = 10;
  imagePosition.y = 10;
  spritePosition.x = 10;
  spritePosition.y = 10;
  SDL_EnableKeyRepeat(10,10);
  menu = SDL_CreateRGBSurface(SDL_HWSURFACE, SCREEN_WIDTH - 2 * SCREEN_BORDER,
			      SCREEN_HEIGHT - 2 * SCREEN_BORDER, 32, 0, 0, 0, 0);
  sprite_test = IMG_Load("mario_sprite.png");

  SDL_FillRect(menu, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
  SDL_BlitSurface(menu, NULL, screen, &imagePosition);
  SDL_BlitSurface(sprite_test, NULL, screen, &spritePosition);
  SDL_Flip(screen);
  while (game)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  game = 0;
	  break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym)
	      {

		/* Func d'apply des input */
	      case SDLK_RIGHT:
		  spritePosition.x += 1;
		  break;
	      case SDLK_LEFT:
		  spritePosition.x -= 1;
		  break;



	      }
	    break;
	}
      /* Func d'updata */
      SDL_BlitSurface(menu, NULL, screen, &imagePosition);
      SDL_BlitSurface(sprite_test, NULL, screen, NULL);
      SDL_Flip(screen);
    }
}


int	main(int ac, char **av)
{
  SDL_Surface	*screen = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Can't init SDL : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  atexit(SDL_Quit);
  if ((screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE)) == NULL)
    {
      printf("Can't set video mode : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Mario Alpha", NULL);
  Exec_Game(screen);
  return (EXIT_SUCCESS);
}
