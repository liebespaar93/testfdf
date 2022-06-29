#include <mlx.h>
#include <mlx_type.h>
#include <ft_draw.h>

#include "src_dot/ft_dot.c"
#include "src_dot/ft_dot_add.c"

#include "src_read_file/ft_readfile.c"
#include "src_read_file/ft_oneline.c"
#include "src_read_file/get_next_line.c"

#include "src_draw/ft_draw_color.c"
#include "src_draw/ft_draw.c"

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
	param->zoom = 30;
	return (param);
}

#include <stdio.h>

int	ft_loop_event(t_param *param)
{
	ft_draw_dot_auto(*param);
	mlx_clear_window(param->mlx_ptr,param->win_ptr);
	printf("%d\n", param->mouse.x++);
	return (0);
}


int main(int ac, char **av)
{
	t_param *param;
    t_dot_header   *header_dot;

	if (!ft_dot_init(&header_dot, readfile("test.fdf")))
		return (-1);
	if (!ft_param_init(&param, header_dot))
		return (-1);
	param->zoom= 30;
	mlx_loop_hook(param->mlx_ptr, ft_loop_event, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}

