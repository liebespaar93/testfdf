#include <mlx.h>
#include <mlx_type.h>
#include <ft_draw.h>
#include <ft_mac_keyboard.h>
#include <ft_mac_mouse.h>

#include "src_dot/ft_dot.c"
#include "src_dot/ft_dot_add.c"

#include "src_read_file/ft_readfile.c"
#include "src_read_file/ft_oneline.c"
#include "src_read_file/get_next_line.c"

#include "src_draw/ft_draw_color.c"
#include "src_draw/ft_draw.c"

#include "src_mlx_keyboard/ft_mac_keyboard.c"
#include "src_mlx_keyboard/ft_mac_key_up.c"
#include "src_mlx_keyboard/ft_mac_key_down.c"
#include "src_mlx_keyboard/ft_mac_key_hold.c"

#include "src_mlx_mouse/ft_mouse_up.c"
#include "src_mlx_mouse/ft_mouse_down.c"
#include "src_mlx_mouse/ft_mouse_drag.c"

t_param	*ft_param_init(t_param **param_ptr, t_dot_header *head_dot_ptr)
{
	t_param *param;

	*param_ptr = (t_param *)malloc(sizeof(t_param));
	if (!*param_ptr)
		return (NULL);
	param = *param_ptr;
	ft_memset(param, 0, sizeof(t_param));
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr , WIN_WIDTH, WIN_HEIGHT, "Hello, World!");
	param->head_dot = head_dot_ptr->head_dot;
	param->zoom = 1;
	param->angle = 0.4;
	param->contour_line = 255 * 3 / head_dot_ptr->max_len_z;
	return (param);
}

#include <stdio.h>
int	ft_loop_event (t_param *param)
{
	ft_draw_dot_auto(*param);
	mlx_clear_window(param->mlx_ptr,param->win_ptr);
	ft_key_hold(param);

	printf("%d\n",param->time);
	param->time++;
	return (0);
}



#include <stdio.h>
int main(int ac, char **av)
{
	t_param *param;
    t_dot_header   *header_dot;

	if (!ft_dot_init(&header_dot, readfile("test_maps/100-6.fdf")))
		return (-1);
	if (!ft_param_init(&param, header_dot))
		return (-1);
	/* keyboard set */
	mlx_hook(param->win_ptr, 2, 0, key_down, param);
	mlx_key_hook(param->win_ptr, key_up, param);
	
	/* mouse set */
	mlx_mouse_hook(param->win_ptr, ft_mouse_down, param);
	mlx_hook(param->win_ptr, 5, 0, ft_mouse_up, param);
	mlx_hook(param->win_ptr, 6, 0, ft_mouse_drag, param);
	
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);

	mlx_loop(param->mlx_ptr);
	return (0);
}

