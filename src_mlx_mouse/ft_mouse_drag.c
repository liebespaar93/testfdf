#include <ft_mac_mouse.h>

int ft_mouse_drag(int x, int y, t_param *param)
{
	if(param->mouse.hold.left || param->mouse.hold.right || param->mouse.hold.scroll)
	{
		param->xyz.x += x - param->mouse.hold.x;
		param->xyz.y += y - param->mouse.hold.y;
		param->mouse.hold.x = x;
		param->mouse.hold.y = y;
	}
    return (0);
}