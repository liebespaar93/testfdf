
#ifndef FT_MAC_KEYBOARD_H
# define FT_MAC_KEYBOARD_H

#include <mlx.h>
#include <mlx_type.h>
#include <mac_keycode.h>
#include <ft_mac_keyboard_type.h>

/* ft_mac_key_down.c */
int ft_keydown_zoom(int keycode, t_param *param);
int ft_keydown_move(int keycode, t_param *param);

/* ft_mac_key_up.c */
int ft_keyup_zoom(int keycode, t_param *param);
int ft_keyup_move(int keycode, t_param *param);

/* ft_mac_keyboard */
int key_up(int keycode, t_param *param);
int key_down(int keycode, t_param *param);

/* ft_mac_key_hold */
void ft_key_hold (t_param *param);

#endif