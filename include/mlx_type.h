
#ifndef MLX_TYPE_H
# define MLX_TYPE_H

#define WIN_WIDTH   1000
#define WIN_HEIGHT  700




#include <stdlib.h>
#include <ft_dot.h>
#include <ft_readfile.h>
#include <ft_mac_keyboard_type.h>
#include <ft_mac_mouse_type.h>

typedef	struct s_param
{
	void	*mlx_ptr;
	void	*win_ptr;

	t_dot	*head_dot;
	t_mouse	mouse;
	t_keyboard	keyboard;
	t_xyz	xyz;
	float	angle;
	float	zoom;
	float	contour_line;

	__int128 time;

} t_param;

# endif