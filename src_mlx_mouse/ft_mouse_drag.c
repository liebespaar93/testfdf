#include <ft_mac_mouse.h>

#include <stdio.h>
int ft_mouse_drag(int x, int y, t_param *param)
{
	if(param->mouse.hold.left)
	{
		param->xyz.x += x - param->mouse.hold.x;
		param->xyz.y += y - param->mouse.hold.y;
		param->mouse.hold.x = x;
		param->mouse.hold.y = y;
	}
	if(param->mouse.hold.right)
	{
		param->angle += x - param->mouse.hold.x;
		param->angle += y - param->mouse.hold.y;
		param->mouse.hold.x = x;
		param->mouse.hold.y = y;
	}
	if(param->mouse.hold.scroll)
	{
		param->xyz.x += x - param->mouse.hold.x;
		param->xyz.y += y - param->mouse.hold.y;
		param->mouse.hold.x = x;
		param->mouse.hold.y = y;
	}
	printf("test:%d %d %d \n", param->mouse.hold.left, param->mouse.hold.right , param->mouse.hold.scroll);

    return (0);
}