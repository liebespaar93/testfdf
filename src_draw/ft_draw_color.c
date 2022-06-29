
#include <ft_draw.h>

int ft_draw_color(int num)
{
    t_color c_color;
    int     flag;

    flag = 1;
    c_color.num = 0x0000FF00;
    if (num > 0)
    {
        while (num--)
        {
            if (c_color.s_bit.r < 0xFF)
                c_color.s_bit.r++;
            else if (c_color.s_bit.g > 0 && c_color.s_bit.b == 0)
                c_color.s_bit.g--;
            else if (c_color.num < 0x00FFFFFF && ++c_color.s_bit.b)
                c_color.s_bit.g++;
            else
                break ;
        }
    }
    else
    {
        while (num++)
        {
            if (c_color.s_bit.b < 0xFF)
                c_color.s_bit.b++;
            else if (c_color.s_bit.g > 0)
                c_color.s_bit.g--;
            else if (c_color.num > 0x00000000)
                c_color.s_bit.b--;
            else
                break ;
        }
    }
    return (c_color.num);
}