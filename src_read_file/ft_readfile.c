#include <ft_readfile.h>

t_oneline *readfile(char *file_name)
{
    t_oneline   *head_oneline;
    
    int   fd;

    head_oneline = NULL;
    fd = open(file_name, O_RDONLY);
    while (ft_oneline_add(&head_oneline, get_next_line(fd)))
        ;
    close(fd);
    return (head_oneline);
}
