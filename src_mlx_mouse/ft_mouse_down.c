
#include <ft_mac_mouse.h>

int ft_mouse_down(int keycode, int x, int y, t_param *param)
{
    if (keycode == MOUSE_LEFT_BUTTON) 
    {
	    param->mouse.hold.x = x;
	    param->mouse.hold.y = y;
        param->mouse.hold.left = 1;
        param->mouse.hold.right = 0;
        param->mouse.hold.scroll = 0;
    }
    else if (keycode == MOUSE_RIGHT_BUTTON)
    {
	    param->mouse.hold.x = x;
	    param->mouse.hold.y = y;
        param->mouse.hold.left = 0;
        param->mouse.hold.right = 1;
        param->mouse.hold.scroll = 0;
    }
    else if (keycode == MOUSE_SCROLL_BUTTON)
    {
	    param->mouse.hold.x = x;
	    param->mouse.hold.y = y;
        param->mouse.hold.left = 0;
        param->mouse.hold.right = 0;
        param->mouse.hold.scroll = 1;
    }
    else if (keycode == MOUSE_SCROLL_UP)
	{
		param->zoom *= 1.1;
	}
    else if (keycode == MOUSE_SCROLL_DOWN)
	{
		param->zoom *= 0.9;
	}
    return (0);
}