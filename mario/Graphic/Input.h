/*
** Input.h for  in /u/all/vangys_c/public/mario/Graphic
** 
** Made by thomas dewitte
** Login   <dewitt_t@epitech.net>
** 
** Started on  Thu Jun  7 19:12:57 2012 thomas dewitte
** Last update Thu Jun  7 19:16:12 2012 thomas dewitte
*/

#ifndef __INPUT_H__
# define __INPUT_H__

typedef struct	s_input
{
  int		token;
  void		(*func)();
}		Input;

DEFINE_LIST(Input*, InputList)

#endif
