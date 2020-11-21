##
## EPITECH PROJECT, 2020
## PSU_nmobjdump_2019
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
LINE_RETURN	=	$(ECHO) ""

SRC_NM	=   nm/src/array.c	\
			nm/src/print.c	\
			nm/src/print_symbole.c	\
			nm/src/check_format.c


SRC_OBJDUMP =	objdump/src/display_header.c	\
				objdump/src/display_content.c	\
				objdump/src/check_format.c

SRC_TESTS =	tests/main_test.c

NAME_NM	=	my_nm

NAME_OBJDUMP =	my_objdump

NAME_TEST 	= 	unit_tests

CFLAGS	=	-Wall \
    -Wextra \
    -g  \
    -I include/

SRCS_NM 	=	$(SRC_NM)	\
				nm/src/nm.c	\
				nm/src/main.c

SRCS_OBJDUMP	=	$(SRC_OBJDUMP) \
					objdump/src/main.c

SRCS_TESTS	=	$(SRC_NM) $(SRC_OBJDUMP) $(SRC_TESTS)

OBJ_NM	=	$(SRCS_NM:.c=.o)

OBJ_OBJDUMP = $(SRCS_OBJDUMP:.c=.o)

OBJ_TESTS = 	$(SRCS_TESTS:.c=.o)

all:  $(NAME_NM) $(NAME_OBJDUMP)

nm :    $(NAME_NM)

objdump:  $(NAME_OBJDUMP)

$(NAME_NM): $(OBJ_NM)
	$(CC) -o $(NAME_NM) $(OBJ_NM)

$(NAME_OBJDUMP): $(OBJ_OBJDUMP)
	$(CC) -o $(NAME_OBJDUMP) $(OBJ_OBJDUMP)

tests_run: $(OBJ_TESTS) message
	@$(CC) -o $(NAME_TEST) $(OBJ_TESTS) --coverage -lcriterion
	@$(LINE_RETURN)
	@./unit_tests
	@$(LINE_RETURN)
	@gcovr --exclude tests --print-summary
	@$(LINE_RETURN)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)" _   _       _ _     _____         _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)"| | | |_ __ (_) |_  |_   _|__  ___| |_ ___"$(DEFAULT)
	@$(ECHO) $(BOLD_T)"| | | | '_ \| | __|   | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)'| |_| | | | | | |_    | |  __/\__ \ |_\__ \\'$(DEFAULT)
	@$(ECHO) $(BOLD_T)" \___/|_| |_|_|\__|   |_|\___||___/\__|___/\n"$(DEFAULT)
	@$(LINE_RETURN)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_TESTS)
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf tests/*.gcda
	@rm -rf tests/*.gcno

fclean:	clean
	@rm -f $(NAME_NM)
	@rm -f $(NAME_OBJDUMP)
	@rm -f $(NAME_TEST)

re:	fclean all

.PHONY: all tests_run clean fclean re message nm objdump
