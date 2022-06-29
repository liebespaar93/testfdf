#include <ft_mac_keyboard.h>
#include <stdio.h>
void ft_key_hold (t_param *param)
{
	if (param->time % 10 == 0)
	{
		param->xyz.x += param->keyboard.hold.x;
		param->xyz.y += param->keyboard.hold.y;
		param->xyz.z += param->keyboard.hold.z;
		param->zoom *= 1 + (0.01 * param->keyboard.hold.zoom);
		param->keyboard.hold.x *= 1.1;
		param->keyboard.hold.y *= 1.1;
		param->keyboard.hold.z *= 1.1;
		printf("?? %e \n",param->zoom);
	}
}