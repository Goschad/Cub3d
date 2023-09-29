NAME = cub3D

SRCS =	src/key.c \
		src/main.c \
		src/init.c \
		src/quit.c \
		src/math.c \
		src/door.c \
		src/mouse.c \
		src/error.c \
		src/emote.c \
		src/check.c \
		src/player.c \
		src/weapon.c \
		src/ft_itoa.c \
		src/ft_atoi.c \
		src/check_2.c \
		src/hide_map.c \
		src/true_map.c \
		src/ft_split.c \
		src/lib_utils.c \
		src/parse_map.c \
		src/raycastig.c \
		src/move_utils.c \
		src/vertical_ray.c \
		src/another_utils.c \
		src/utils_texture.c \
		src/horizontal_ray.c \
		src/character_utils.c \
		src/utils_map_check.c \
		src/utils_map_check_2.c \
		src/utils_map_check_3.c \
		src/utils_map_check_4.c \
		src/utils_map_check_5.c \
		src/utils_texture_check.c \
		src/utils_texture_check_2.c \
		src/utils_texture_check_3.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# ------------------------------ Flags -------------------------------

CC = @gcc -Wall -Wextra -Werror

# ------------------------------ Colors ------------------------------

# Colors

GREY 	 := "\033[1;30m"
RED 	 :=	"\033[1;31m"
GREEN 	 := "\033[1;32m"
YELLOW 	 := "\033[1;33m"
BLUE	 :=	"\033[1;36m"
PURPLE	 :=	"\033[1;35m"
WHITE	 :=	"\033[1;37m"
END		 :=	"\033[0;0m"

# ------------------------------ Messages ------------------------------

MAKE_MESS		= • Make :

FILES_OK		= has been successfully compiled!

FILES_DELETE	= • Clean : please make am fclean to delete cub3d

FCLEAN_DELETE	= • Fclean : cub3D was been successfully deleted!
                                             

# ------------------------------ so_long --------------------------------

all: $(NAME)

bonus : all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) MLX42/libmlx42.a -I include -lglfw -L /Users/$$USER/.brew/opt/glfw/lib
	@echo ${GREEN}"$(MAKE_MESS) $(NAME) $(FILES_OK)"${END}

# ------------------------------ Rules -----------------------------------

clean:
	@rm -rf ${OBJS}
	
	@echo ${RED}"$(FILES_DELETE)"${END}

fclean: clean 
	@rm -rf $(NAME)
	@echo ${RED}"$(FCLEAN_DELETE)"${END}

re : fclean all