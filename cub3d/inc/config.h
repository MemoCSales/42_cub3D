#ifndef CONFIG_H
# define CONFIG_H

/// keyboard configuration
# include <X11/keysym.h>
# define KEY_FORWARD		XK_w
# define KEY_BACKWARD		XK_s
# define KEY_SLIDELEFT		XK_a
# define KEY_SLIDERIGHT		XK_d
# define KEY_LEFT			XK_Left
# define KEY_RIGHT			XK_Right
# define KEY_UP				XK_Up
# define KEY_DOWN			XK_Down
# define KEY_EXIT1			XK_Escape
# define KEY_EXIT2			XK_x

// ===== gameplay =====
/// vertical movement speed
# define ROT_SPEED			.1

// game resolution
# define GAME_W				1920
# define GAME_H				1080

// ===== graphics =====
/// height of perspective (=eye height)
# define CAM_HEIGHT			.5
/// camera width
# define CAM_WIDTH			.0001

# define MAP_SUFFIX			".cub"

# define RAY_MARCH_DELTA	.001

# define DISPLAY_TITLE		"cub3D"
# define TEX_NOTFOUND		"assets/404.xpm"

# define MOUSE_SENS_Y		1.5

// rendering options
# define MAXHITS			1

# define CTRANSPARENT		0xff000000
# define CWHITE				0x00ffffff
# define CBLACK				0x00000000
# define CGREEN				0x004df84a
# define CRED				0x00a00000
# define CBLUE				0x0000a000
# define CGRAY				0x00d3d3d3

# define GAME_UPSCALE		2

#endif
