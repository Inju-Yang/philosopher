# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inyang <inyang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 17:36:07 by inyang            #+#    #+#              #
#    Updated: 2021/10/26 01:49:54 by inyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
CC				=	gcc
CFLAGS_42		=	-Wall -Wextra -Werror
RM				=	rm -rf

PHILO_C			=	check_philo.c\
					philo.c\
					philo_util.c\
					fork_thing.c\
					philo_action.c\
					print_status.c\
					philo_init.c

PHILO_O			=	$(PHILO_C:.c=.o)

all: $(NAME)

$(NAME): $(PHILO_O)
	$(CC) $(CFLAGS_42) $(PHILO_O)
	mv a.out $(NAME)

.c.o:
	$(CC) $(CFLAGS_42) -c -o $@ $<

clean:
	$(RM) $(PHILO_O) 

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus