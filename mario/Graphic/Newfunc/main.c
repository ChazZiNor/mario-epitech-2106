/*
** main.c for  in /home/dewitt_t//Mario_Tech/Mario_Alpha/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Fri Jun  8 12:11:46 2012 thomas dewitte
** Last update Fri Jun  8 16:17:08 2012 thomas dewitte
*/

#include "Input.h"
#include "Sprite.h"

void		SuperMarioTech(SDL_Surface *screen)
{
  SDL_Envent	event;
  SDL_Surface	*scene = NULL;
  SDL_Rect	camPosition;
  Input		*in;
  InputList	*list;
  static int	game = 1;

  camPosition.x = 0;
  camPosition.y = 0;

  scene = generateScene(char **map);
  setRepeatKeyTimer(10, 10);
  list = initInputList();
  while (game)
    {
      SDL_PollEvent(&event);
      switch(envent.type)
	{
	case SDLK_QUIT:
	  game = 0;
	  break;
	case SDL_KEYDOWN:
	  in = getInputFunctionAssociate(list, event.key.keysym.sym);
	  in->func();
	  break;
	}
    }
}

int	main(int ac, char **av)
{
  SDL_Surface   *screen = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Can't init SDL : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  atexit(SDL_Quit);
  if ((screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
				 SDL_HWSURFACE)) == NULL)
    {
      printf("Can't set video mode : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Mario Alpha", NULL);
  SuperMarioTech(screen);
  return (0);
}
