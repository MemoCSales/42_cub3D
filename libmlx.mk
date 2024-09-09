LIBMLX_URL			= https://cdn.intra.42.fr/document/document/25837/minilibx-linux.tgz
LIBMLX_DIR			= lib/mlx
LIBMLX				= $(LIBMLX_DIR)/libmlx.a

INC					+= -I$(LIBMLX_DIR)
LDFLAGS				+= -L$(LIBMLX_DIR)
LDLIBS				+= -lmlx -lXext -lX11

$(LIBMLX_DIR):
	curl -sS -o mlx.tar.gz $(LIBMLX_URL)
	tar xf mlx.tar.gz
	$(RM) mlx.tar.gz
	mv minilibx* $(LIBMLX_DIR)

$(LIBMLX): $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR)
