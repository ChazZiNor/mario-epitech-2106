#ifndef __MAP_SERIALIZER_H__
# define __MAP_SERIALIZER_H__

typedef struct s_map {
  char		**_map;
  unsigned int  xSize;
  unsigned int  ySize;
}		Map;

void		MapSerializer_serialize(void);


#endif
