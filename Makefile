NAME	=	pathfinder

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		= 	mx_printerr_pf.c mx_validation.c mx_validation_cmd_args.c \
			mx_validation_file_empty.c mx_validation_file_dexist.c \
			mx_validation_check_end_line.c mx_validation_check_weight.c \
			mx_validation_first_line.c mx_validation_num_islnd.c \
			mx_validation_check_delim.c mx_validation_check_island_one_isalpha.c \
			mx_validation_check_island_two_isalpha.c mx_validation_check_number.c \
			mx_graph_island_create.c mx_graph_island_add.c mx_graph_island_get.c \
			mx_graph_link_create.c mx_graph_link_add.c mx_graph_link_push_back.c \
			mx_graph_link_pop_back.c mx_graph_link_set.c mx_graph_path_create.c \
			mx_graph_path_push_front.c mx_graph_path_push_back.c \
			mx_pathainder_parse.c mx_pathainder_algorithm.c mx_pathainder_reverse_paths.c \
			mx_pathainder_prepare_for_algorithm.c mx_pathainder_print_paths.c \
			mx_until_file_to_arr.c mx_until_bzero.c mx_until_memalloc.c \
			mx_crate_file.c mx_create_algorithm.c mx_create_main.c main.c


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
