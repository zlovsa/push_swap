# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 19:13:40 by mcarolee          #+#    #+#              #
#    Updated: 2021/03/10 02:28:54 by mcarolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHKSRC	= checker.c
PSWSRC	= push_swap.c index.c brute.c move.c merge.c operations.c
STSRC	= stack.c instructions.c instructions2.c utils.c

CHKOBJ	= $(CHKSRC:.c=.o)
PSWOBJ	= $(PSWSRC:.c=.o)
STOBJ	= $(STSRC:.c=.o)

CHKNAME	= checker
PSWNAME = push_swap

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -L libft -lft

LFTDIR = ./libft/

LFT = $(LIBFTDIR)libft.a

all:		$(CHKNAME) $(PSWNAME)

$(CHKNAME):	$(CHKOBJ) $(STOBJ)
			make -C $(LFTDIR)
			$(CC) $(CFLAGS) $(LFLAGS) -o $(CHKNAME) $(CHKOBJ) $(STOBJ)

$(PSWNAME):	$(PSWOBJ) $(STOBJ)
			make -C $(LFTDIR)
			$(CC) $(CFLAGS) $(LFLAGS) -o $(PSWNAME) $(PSWOBJ) $(STOBJ)

clean:
			$(RM) $(CHKOBJ) $(PSWOBJ) $(STOBJ)
			make clean -C $(LFTDIR)

fclean:		clean
			$(RM) $(CHKNAME) $(PSWNAME)
			make fclean -C $(LFTDIR)
			
re:			fclean all

.PHONY:		all clean fclean re test