/*
** cameraManagement.c for  in /home/dewitt_t//Mario_Tech/Mario_Alpha/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Fri Jun  8 02:14:51 2012 thomas dewitte
** Last update Fri Jun  8 12:04:55 2012 thomas dewitte
*/

#include "SDL/SDL.h"

void	applyCamSceneOnScreen(SDL_Surface *scene, SDL_Rect *camPosition,
			      SDL_Surface *screen)/*,SDL_Rect *copyPositionOnScreen)*/
{
  SDL_BlitSurface(scene, camPosition, screen, NULL);
}

void	camScrolling(SDL_Rect *cam, gameObject *mainChar)
{
  if ((mainChar->sprite.spritePosition.x - cam->x) / 3 >= SCREEN_WIDTH)
    cam->x += PPB;
  /* else */
  /*   mainChar->sprite.spritePosition.x += PPB; */
}
