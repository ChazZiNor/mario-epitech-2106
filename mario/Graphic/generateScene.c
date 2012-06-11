/*
** generateScene.c for  in /home/dewitt_t//Mario_Tech/Mario_Alpha/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Thu Jun  7 23:50:10 2012 thomas dewitte
** Last update Fri Jun  8 12:18:20 2012 thomas dewitte
*/

#include <stdio.h>
#include <stdlib.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Constantes.h"

SDL_Surface	*generateScene(char **map)
{
  SDL_Surface	*scene = NULL;

  if (map && map[0])
    scene = SDL_CreateRGBSurface(SDL_HWSURFACE, sizeof(map[0]) * PPB,
				 sizeof(map) * PPB, BPP, 0, 0, 0, 0);
  else
    return (NULL);
  SDL_FillRect(scene, NULL, SDL_MapRGB(scene->format, 116, 208, 241));   /* Azur */
  return (scene);
/* scene = SDL_CreateRGBSurface(SDL_HWSURFACE, _calculWidthScene(map), _calculHeightScene(map), */
/* 			       BPP, 0, 0, 0, 0); */
}
