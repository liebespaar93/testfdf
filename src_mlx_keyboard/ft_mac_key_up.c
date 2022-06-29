#include <ft_mac_keyboard.h>

int ft_keyup_plus_min(int keycode, t_param *param)
{
	int flag;

	flag = 0;
	if ((keycode == KEY_PLUS || keycode == KEY_P_PLUS) && ++flag)
	{
		param->keyboard.hold.zoom = 0;
		param->keyboard.hold.contour_line = 0;
	}
	else if ((keycode == KEY_MINUS || keycode == KEY_P_MINUS) && ++flag)
	{
		param->keyboard.hold.zoom = 0;
		param->keyboard.hold.contour_line = 0;
	}
	if (flag)
		return (1);
	return (0);
}

int ft_keyup_move(int keycode, t_param *param)
{
	int flag;

	flag = 0;
	if ((keycode == KEY_ARROW_U || keycode == KEY_W) && ++flag)
		param->keyboard.hold.y = 0;
	else if ((keycode == KEY_ARROW_D || keycode == KEY_S) && ++flag)
		param->keyboard.hold.y = 0;
	else if ((keycode == KEY_ARROW_R || keycode == KEY_D) && ++flag)
		param->keyboard.hold.x = 0;
	else if ((keycode == KEY_ARROW_L || keycode == KEY_A) && ++flag)
		param->keyboard.hold.x = 0;
	if (flag)
		return (1);
	return (0);
}

int	ft_keyup_option(int keycode, t_param *param)
{
	int	flag;
	
	flag = 0;
	if ((keycode == KEY_R_SHIFT || keycode == KEY_L_SHIFT || keycode == KEY_NEW_R_SHIFT || keycode == KEY_NEW_L_SHIFT)  && ++flag)
		param->keyboard.hold.shift = 0;
	if (flag)
		return (1);
	return (0);
}