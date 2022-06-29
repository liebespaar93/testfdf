#include <ft_mac_mouse.h>

int ft_mouse_up(int keycode, int x, int y, t_param *param)
{             
    if (keycode == MOUSE_LEFT_BUTTON)
    {
	    param->mouse.hold.x = 0;
	    param->mouse.hold.y = 0;
        param->mouse.hold.left = 0;
    }
    else if (keycode == MOUSE_RIGHT_BUTTON)
    {
	    param->mouse.hold.x = 0;
	    param->mouse.hold.y = 0;
        param->mouse.hold.right = 0;
    }
    else if (keycode == MOUSE_SCROLL_BUTTON)
    {
	    param->mouse.hold.x = 0;
	    param->mouse.hold.y = 0;
        param->mouse.hold.scroll = 0;
    }
    return (0);
}