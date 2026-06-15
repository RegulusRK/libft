#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *node_c;

    if (lst == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }

    node_c = *lst;
    while (node_c->next != NULL)
    {
        node_c = node_c->next;
    }
    node_c->next = new;
}