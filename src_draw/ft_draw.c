#include <ft_draw.h>


t_dot   ft_symtax_pixel(t_param param, t_dot dot)
{
    dot.x *= param.zoom;
    dot.y *= param.zoom;
    dot.z *= param.zoom;
    dot.x = (dot.x - dot.y) * ft_cos(0.4);
    dot.y = (dot.x + dot.y) * ft_sin(0.4) - dot.z;
    return (dot);
}



t_xyz ft_allow_init(t_xyz *c_allow, t_dot position_dot, t_dot next_dot)
{
    c_allow->x = -ft_sign(position_dot.x - next_dot.x);
    c_allow->y = -ft_sign(position_dot.y - next_dot.y);
    c_allow->z = -ft_sign(position_dot.z - next_dot.z);
	
	return (*c_allow);
}


float    ft_ratio_max(t_xyz *c_distance, t_dot position_dot, t_dot next_dot)
{
    float max_distance;

    max_distance = 0;
    c_distance->x = ft_abs(position_dot.x - next_dot.x);
    c_distance->y = ft_abs(position_dot.y - next_dot.y);
    c_distance->z = ft_abs(position_dot.z - next_dot.z);
    max_distance = c_distance->x;
    if (max_distance < c_distance->y)
        max_distance = c_distance->y;
    if (max_distance < c_distance->z)
        max_distance = c_distance->z;
    return (max_distance);
}

t_xyz    ft_ratio_init(t_xyz *c_ratio, t_dot position_dot, t_dot next_dot)
{
    float max_distance;
    t_xyz c_distance;
    
    max_distance = ft_ratio_max(&c_distance , position_dot, next_dot);
    if (!max_distance)
    {
        c_ratio->x = 1;
        c_ratio->y = 1;
        c_ratio->z = 1;
        return (*c_ratio);
    }
    c_ratio->x = ft_ratio(c_distance.x, max_distance);
    c_ratio->y = ft_ratio(c_distance.y, max_distance);
    c_ratio->z = ft_ratio(c_distance.z, max_distance);

    return (*c_ratio);
}

int    ft_auto_pixel_put(t_param param, t_dot position_dot, int color)
{
    float x;
    float y;

    x = position_dot.x + WIN_WIDTH/2 + param.xyz.x;
    y =  position_dot.y + WIN_HEIGHT/2 + param.xyz.y;

    if (!(0 < x && x < WIN_WIDTH && 0 < y && y < WIN_HEIGHT))
        return (0);
    mlx_pixel_put(param.mlx_ptr, param.win_ptr, x, y, color);
    return (1);
}

int    ft_auto_ratio_draw(t_param param, t_dot *position_dot, t_xyz c_allow, t_xyz c_ratio)
{
    int color;

    color = ft_draw_color((position_dot->z / param.zoom * param.contour_line));
    if (!ft_auto_pixel_put(param, *position_dot, color))
        return (0);
    position_dot->x += c_allow.x * c_ratio.x;
    position_dot->y += c_allow.y * c_ratio.y;
    position_dot->z += c_allow.z * c_ratio.z;
    return (1);
}

void    ft_auto_line_draw(t_param param, t_dot position_dot, t_dot next_dot)
{
    t_xyz c_ratio;
    t_xyz c_allow;

    ft_ratio_init(&c_ratio, position_dot, next_dot);
    ft_allow_init(&c_allow, position_dot, next_dot);

    if (c_ratio.x == 1)
    {
        while (ft_abs(position_dot.x) <= ft_abs(next_dot.x))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    }
    else if (c_ratio.y == 1)
    {
        while (ft_abs(position_dot.y) <= ft_abs(next_dot.y))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    }
    else if (c_ratio.z == 1)
    {
        while (ft_abs(position_dot.z) <= ft_abs(next_dot.z))
            ft_auto_ratio_draw(param, &position_dot, c_allow, c_ratio);
    }
}

void ft_draw_dot_auto(t_param param)
{
    t_dot   tmp_dot;
    t_dot   head_dot;
    
    if (!param.head_dot)
        return ;
    head_dot = *param.head_dot;
    while (head_dot.life)
    {
        tmp_dot = head_dot;
        while (tmp_dot.life)
        {
            if (tmp_dot.x_p)
                ft_auto_line_draw(param, ft_symtax_pixel(param, tmp_dot), ft_symtax_pixel(param, *tmp_dot.x_p));
            if (tmp_dot.y_p)
                ft_auto_line_draw(param, ft_symtax_pixel(param, tmp_dot), ft_symtax_pixel(param, *tmp_dot.y_p));
            if (tmp_dot.x_m)
                ft_auto_line_draw(param, ft_symtax_pixel(param, tmp_dot), ft_symtax_pixel(param, *tmp_dot.x_m));
            if (tmp_dot.y_m)
                ft_auto_line_draw(param, ft_symtax_pixel(param, tmp_dot), ft_symtax_pixel(param, *tmp_dot.y_m));
            if (!tmp_dot.x_p)
                break;
            tmp_dot = *tmp_dot.x_p;
        }
        if (!head_dot.y_p)
            break;
        head_dot = *head_dot.y_p;
    }
}