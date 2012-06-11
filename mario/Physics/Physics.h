#ifndef __PHYSICS_H__
# define __PHYSICS_H__

struct s_gameobject;

typedef struct	s_physics {
  enum	e_state {
    NOPHYSICS,
    isGrounded,
    isFalling,
    isInWater
  }	physicsState;

  void		(*physicsUpdate)(struct s_gameobject*);

  float		gravityForce;
}		Physics;

Physics *instanciatePhysics(struct s_gameobject*);

#endif
