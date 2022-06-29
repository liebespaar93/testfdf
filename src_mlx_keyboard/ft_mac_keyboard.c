#include <ft_mac_keyboard.h>

/*
int	key_map_change(int keycode, t_param *param)
{
	if (keycode == KEY_R_A_BRAKET)
	{
		ft_map_next();
	}
	if (keycode == KEY_L_A_BRAKET)
	{
		ft_map_pres();
	}
}
*/

int key_up(int keycode, t_param *param)
{
	if (ft_keyup_plus_min(keycode, param))
		return (0);
	if (ft_keyup_move(keycode, param))
		return (0);
	if (ft_keyup_option(keycode, param))
		return (0);
	else if (keycode == KEY_ESC)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	return (0);
}

int key_down(int keycode, t_param *param)
{
	if (ft_keydown_plus_min(keycode, param))
		return (0);
	if (ft_keydown_move(keycode, param))
		return (0);
	if (ft_keydown_option(keycode, param))
		return (0);
	return (0);
}
