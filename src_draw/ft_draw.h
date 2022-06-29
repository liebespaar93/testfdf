#ifndef FT_DRAW_DOT_H
# define FT_DRAW_DOT_H


#include <stdlib.h>
#include <libft.h>
#include <ft_dot.h>
#include <mlx_type.h>
#include <mlx.h>

typedef union u_color
{
    int num;
    
	struct
	{
		unsigned char	b :8 ;
		unsigned char   g :8 ;
		unsigned char	r :8 ;
		unsigned char	a :8 ;
	}	s_bit;
}   t_color;


/* ft_draw_color */
int ft_draw_color(int num);

/* ft_draw_dot.c */
void ft_draw_dot_auto(t_param param);


#endif