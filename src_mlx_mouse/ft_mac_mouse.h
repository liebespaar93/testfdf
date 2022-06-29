

#ifndef FT_MAC_MOUSE_H
# define FT_MAC_MOUSE_H

#include <mlx.h>
#include <mlx_type.h>
#include <mac_mousecode.h>
#include <ft_mac_mouse_type.h>

/* ft_mouse_up.c */
int ft_mouse_up(int keycode, int x, int y, t_param *param);

/* ft_mouse_down.c */
int ft_mouse_down(int keycode, int x, int y, t_param *param);

/* ft_mouse_draw.c */
int ft_mouse_drag(int x, int y, t_param *param);

#endif