#include <ft_mac_keyboard.h>

int ft_keydown_plus_min(int keycode, t_param *param)
{
	int flag;

	flag = 0;
	if ((keycode == KEY_PLUS || keycode == KEY_P_PLUS) && ++flag)
	{
		if (param->keyboard.hold.shift)
			param->keyboard.hold.contour_line++;
		else
			param->keyboard.hold.zoom++;
	}
	else if ((keycode == KEY_MINUS || keycode == KEY_P_MINUS) && ++flag)
	{
		if (param->keyboard.hold.shift)
			param->keyboard.hold.contour_line--;
		else
			param->keyboard.hold.zoom--;
	}
	if (flag)
	{
		if (param->keyboard.hold.shift)
			param->contour_line *= 1 + (0.01 * param->keyboard.hold.zoom);
		else
			param->zoom *= 1 + (0.01 * param->keyboard.hold.zoom);
		return (1);
	}
	return (0);
}

int ft_keydown_move(int keycode, t_param *param)
{
	int flag;

	flag = 0;
	if ((keycode == KEY_ARROW_U || keycode == KEY_W) && ++flag)
		param->keyboard.hold.y--;
	else if ((keycode == KEY_ARROW_D || keycode == KEY_S) && ++flag)
		param->keyboard.hold.y++;
	else if ((keycode == KEY_ARROW_R || keycode == KEY_D) && ++flag)
		param->keyboard.hold.x++;
	else if ((keycode == KEY_ARROW_L || keycode == KEY_A) && ++flag)
		param->keyboard.hold.x--;
	if (flag)
		return (1);
	return (0);
}

int	ft_keydown_option(int keycode, t_param *param)
{
	int	flag;

	flag = 0;
	if ((keycode == KEY_R_SHIFT || keycode == KEY_L_SHIFT || keycode == KEY_NEW_R_SHIFT || keycode == KEY_NEW_L_SHIFT)  && ++flag)
		param->keyboard.hold.shift = 1;
	if (flag)
		return (1);
	return (0);
}