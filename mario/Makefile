NAME	=	mario

SRCS	=	MapSerializer/main.c		\
		MapSerializer/MapSerializer.c	\
		GameObject/gameObject.c		\
		Physics/Physics.c		\
		Physics/Collide.c		\
		Physics/RigidBody/RigidBody.c	\
		GameEngine/GameEngine.c		\
		Perception/Perception.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc
RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -std=c99 -IMapSerializer/ -IGameObject/ -IPhysics/ -IPhysics/RigidBody \
		-ITools/ -ITools/GenericList/ -IGameEngine/ -IGameEngine/ -ITransform -IPerception -ggdb

LDFLAGS	+=	-lm

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean