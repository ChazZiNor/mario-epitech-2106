/*
** Input.c for  in /u/all/vangys_c/public/mario/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Thu Jun  7 19:16:20 2012 thomas dewitte
** Last update Fri Jun  8 16:07:00 2012 thomas dewitte
*/

#include "Input.h"
#include "SDL/SDL.h"

static int	_token;

void	setRepeatKeyTimer(int delay, int interval)
{
  SDL_EnableKeyRepeat(delay, interval);
}

void	addNewInput(InputList *list, int token, void (*func)())
{
  Input	value;

  value.token = token;
  value.func = func;
  list = push_front_InputList(list, value);
}

static int	_isSameToken(Input *value)
{
  if (value->token == _token)
    return (1);
  return (0);
}

Input	*getInputFunctionAssociate(InputList *list, int token)
{
  Input	*result;

  _token = token;
  result = get_elem_InputList(list, &isSameToken);
  return (result);
}

InputList	*initInputList(void)
{
  InputList	*list;

  addNewInput(list, /* token */, /*func assiciate */);
  /* ... */
}
