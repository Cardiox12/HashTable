CC			= gcc

INC_DIR		= includes
SRC_DIR		= srcs

SRCS		= $(SRC_DIR)/ht_add.c \
$(SRC_DIR)/ht_create.c \
$(SRC_DIR)/ht_dump.c \
$(SRC_DIR)/ht_hash.c \
$(SRC_DIR)/ht_pair.c

INC_FILES	= $(INC_DIR)/hashtable.h \
$(INC_DIR)/ht_internals.h

NAME		= hashtable

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(SRCS) $(INC_FILES)
	@$(CC) -o $(NAME) main.c $(SRCS) -I $(INC_DIR)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
