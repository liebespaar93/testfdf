
#ifndef FT_READFILE_H
# define FT_READFILE_H

#include <get_next_line.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct  s_oneline
{
  char    *data;
  size_t  data_size;
  struct s_oneline *next;
} t_oneline;

/* ft_oneline */
t_oneline	*ft_new_oneline(char const *data);
t_oneline	*ft_oneline_add(t_oneline **oneline_ptr, char const *data);
t_oneline *ft_free_oneline(t_oneline **oneline_ptr);

/* ft_readfile */
t_oneline *readfile(char *file_name);

#endif