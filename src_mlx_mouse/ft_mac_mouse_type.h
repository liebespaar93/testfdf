

#ifndef FT_MAC_MOUSE_TYPE_H
# define FT_MAC_MOUSE_TYPE_H

typedef struct s_mouse_hold
{
	int		left;
	int		right;
	int		scroll;
	float	x;
	float	y;
} t_mouse_hold;

typedef struct s_mouse
{
	int mouse_keycode;

	t_mouse_hold	hold;

	float zoom;
}	t_mouse;

#endif