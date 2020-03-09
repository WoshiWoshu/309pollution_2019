##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

VERSION			=		-std=c++11

CXX				=		g++ $(VERSION)

RM				=		rm -f

INCDIRS			=		$(addprefix -I, $(shell find ./include -type d -print))

CXXFLAGS		=		-Wall -Wextra
CXXFLAGS		+=		$(INCDIRS)

NAME			=		309pollution

SRCS			=		$(wildcard src/*.cpp) \
						main.cpp

OBJS			=		$(addsuffix .o, $(basename $(SRCS)))

all				:		$(NAME)

$(NAME)			:		$(OBJS)
				@$(CXX) -o $(NAME) $(OBJS)
				@printf "[\033[1;33mBuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
				@echo "\033[1;34m\n==== \033[1;35mCOMPLETED\033[34m ====\033[0m"

clean			:
				@$(RM) $(OBJS)
				@printf "[\033[1;31mDeleted_Obj\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean			:		clean
				@$(RM) $(NAME)
				@printf "[\033[1;31mDeleted_Binary\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re				:		fclean all

%.o				:		%.cpp
				@$(CXX) $(CXXFLAGS) -c -o $@ $<
				@echo "[\033[1;34mCompiled\033[0m]" "---->" $< || echo "REALLY NIGGA ??!!" $<

.PHONY			:		all clean fclean re %.o
