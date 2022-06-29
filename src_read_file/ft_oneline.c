#include <ft_readfile.h>

t_oneline	*ft_new_oneline(char const *data)
{
	t_oneline   *new_oneline;

	new_oneline = (t_oneline *)malloc(sizeof(t_oneline));
	if (!new_oneline)
		return (NULL);
    ft_memset(new_oneline, 0, sizeof(t_oneline));
	if (!data)
		return (new_oneline);
    new_oneline->data_size = ft_strlen(data);
	new_oneline->data = (char *)data;
	return (new_oneline);
}

t_oneline	*ft_oneline_add(t_oneline **oneline_ptr, char const *data)
{
	t_oneline   *new_oneline;
    t_oneline   *tmp_oneline;
    
    if (!data)
        return (NULL);
    tmp_oneline = *oneline_ptr;
    new_oneline = ft_new_oneline(data);
    if (!tmp_oneline)
    {
        *oneline_ptr = new_oneline;
        return (new_oneline);
    }
    while (tmp_oneline->next)
        tmp_oneline = tmp_oneline->next;
    tmp_oneline->next = new_oneline;
    return (new_oneline);
}

t_oneline   *ft_free_oneline(t_oneline **oneline_ptr)
{
    t_oneline   *oneline_tmp;

    oneline_tmp = *oneline_ptr;
    while (*oneline_ptr)
    {
        oneline_tmp = *oneline_ptr;
        *oneline_ptr = (*oneline_ptr)->next;
        free(oneline_tmp->data);
        free(oneline_tmp);
    }
    return (*oneline_ptr);
}