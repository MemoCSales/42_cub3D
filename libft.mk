LIBFT_DIR			= lib/libft
LIBFT				= $(LIBFT_DIR)/libft.a

INC					+= -I$(LIBFT_DIR)
LDFLAGS				+= -L$(LIBFT_DIR)
LDLIBS				+= -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
