NAME			=	cub3d

NAMEBON			=	cub3d_bonus

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I includes/ -I $(LIB_DIR) -I mlx/

LIBFT			=	$(LIB_DIR)libft.a

HEADER			=	includes/cub3d.h libft/libft.h

MLX				= 	libmlx.a

LIBS			= 	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm

RAYCASTING		=	raycasting lodev

MAP				=	minimap	radar

MOVE			=	move mouse

MAIN			=	main tools

PARSING			=	parse	valid_wall valid_name	valid_head	valid_color

INIT			=	init_player init_texture init_map

SRC				=	$(addsuffix .c, $(addprefix srcs/raycasting/, $(RAYCASTING))) \
					$(addsuffix .c, $(addprefix srcs/map/, $(MAP))) \
					$(addsuffix .c, $(addprefix srcs/move/, $(MOVE))) \
					$(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
					$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
					$(addsuffix .c, $(addprefix srcs/init/, $(INIT))) \

SRCBON				=	$(addsuffix .c, $(addprefix srcs_bonus/raycasting/, $(RAYCASTING))) \
					$(addsuffix .c, $(addprefix srcs_bonus/map/, $(MAP))) \
					$(addsuffix .c, $(addprefix srcs_bonus/move/, $(MOVE))) \
					$(addsuffix .c, $(addprefix srcs_bonus/main/, $(MAIN))) \
					$(addsuffix .c, $(addprefix srcs_bonus/parsing/, $(PARSING))) \
					$(addsuffix .c, $(addprefix srcs_bonus/init/, $(INIT))) \

OBJ				=	$(SRC:c=o)

OBJBON			=	$(SRCBON:c=o)

LIB_DIR			=	libft/

all				:	$(NAME)

$(NAME)			:	$(MLX) $(LIBFT) $(OBJ) $(HEADER)
	@echo "\n"
	@echo "\033[0;32mCompiling cub3d..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ) ${LIBS}
	@echo "\n\033[0mDone !"

bonus			:	$(MLX) $(LIBFT) $(OBJBON) $(HEADER)
	@echo "\n"
	@echo "\033[0;32mCompiling cub3d..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $(NAMEBON) $(OBJBON) ${LIBS}
	@echo "\n\033[0mDone !"

$(MLX)			:
	@echo "\033[0;32mCompiling mlx..."
	@$(MAKE) -sC mlx
	@mv mlx/libmlx.a .

$(LIBFT)		:
	@$(MAKE) -sC $(LIB_DIR)

%.o				:		%.c
	@printf "\033[0;33mGenerating cub3d objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean			:
	@$(MAKE) -C mlx clean
	@$(MAKE) -sC $(LIB_DIR) clean
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@rm -f $(OBJBON)
	@echo "\033[0m"

fclean			: clean
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@rm -f $(OBJBON)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@rm -f $(NAMEBON)
	@echo "\033[0m"

re				:	fclean all

norm:
	@norminette $(SRC) includes/cub3d.h $(SRCBON) $(LIB_DIR)

.PHONY: all clean fclean re test norm bonus