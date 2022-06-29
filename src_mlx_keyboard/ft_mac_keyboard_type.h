
#ifndef FT_MAC_KEYBOARD_TYPE_H
# define FT_MAC_KEYBOARD_TYPE_H

typedef struct s_key_hold
{
	float	x;
	float	y;
	float	z;

	int		zoom;
	int		shift;
	int		contour_line;
} t_key_hold;

typedef struct s_keyboard
{
	t_key_hold hold;
} t_keyboard;

#endif