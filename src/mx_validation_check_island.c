#include "pathfinder.h"

static int check_list(t_list **list, char *str)
{
    if (*list == NULL)
        return 0;
    t_list *buf = *list;
    while (buf != NULL)
    {
        if (mx_strcmp(str, buf->data) == 0)
            return 1;
        buf = buf->next;
    }
    return 0;
}

t_list *mx_validation_check_island(char **array)
{
    char **ptr = NULL;
    char *ptr1 = NULL;
    char *temp = NULL;
    t_list *list = NULL;
    for (int i = 1; array[i] != NULL; i++)
    {
        ptr = mx_strsplit(array[i], '-');
        temp = mx_strdup(ptr[0]);
        if (check_list(&list, temp) == 0)
            mx_push_back(&list, temp);
        mx_strdel(&temp);
        ptr1 = mx_strdup(ptr[1]);
        mx_del_strarr(&ptr);
        ptr = mx_strsplit(ptr1, ',');
        mx_strdel(&ptr1);
        temp = mx_strdup(ptr[0]);
        mx_del_strarr(&ptr);
        if (check_list(&list, temp) == 0)
            mx_push_back(&list, temp);
        mx_strdel(&temp);
    }
    return list;
}
