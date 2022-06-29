#include <ft_dot.h>

t_dot *ft_dot_add_x(t_dot **dot_ptr, t_dot *new_dot, int sign)
{
    if (!*dot_ptr)
    {
        *dot_ptr = new_dot;
        return new_dot;
    }
    if (sign > 0)
    {
        (*dot_ptr)->x_p = new_dot;
        new_dot->x_m = *dot_ptr;
    }
    else if (sign < 0)
    {
        (*dot_ptr)->x_m = new_dot;
        new_dot->x_p = *dot_ptr;
    }
    else
        return (*dot_ptr);
    return new_dot;
}

t_dot *ft_dot_add_y(t_dot **dot_ptr, t_dot *new_dot, int sign)
{
    if (!*dot_ptr)
    {
        *dot_ptr = new_dot;
        return new_dot;
    }
    if (sign > 0)
    {
        (*dot_ptr)->y_p = new_dot;
        new_dot->y_m = *dot_ptr;
    }
    else if (sign < 0)
    {
        (*dot_ptr)->y_m = new_dot;
        new_dot->y_p = *dot_ptr;
    }
    else
        return (*dot_ptr);
    return new_dot;
}

t_dot *ft_dot_add_z(t_dot **dot_ptr, t_dot *new_dot, int sign)
{
    if (!*dot_ptr)
    {
        *dot_ptr = new_dot;
        return new_dot;
    }
    if (sign > 0)
    {
        (*dot_ptr)->z_p = new_dot;
        new_dot->z_m = *dot_ptr;
    }
    else if (sign < 0)
    {
        (*dot_ptr)->z_m = new_dot;
        new_dot->z_p = *dot_ptr;
    }
    else
        return (*dot_ptr);
    return new_dot;
}
