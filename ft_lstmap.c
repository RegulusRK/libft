#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_node;
    t_list  *new_lst;
    void    *new_content;

    new_lst = NULL;
    if (lst == NULL)
        return (NULL);
    if (f == NULL)
        return (NULL);
    if (del == NULL)
        return (NULL);
    while (lst != NULL)
    {
        new_content = f(lst->content);
        new_node = ft_lstnew(new_content);
        if (new_node == NULL)
        {
            del(new_content);
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }
    return (new_lst);
}