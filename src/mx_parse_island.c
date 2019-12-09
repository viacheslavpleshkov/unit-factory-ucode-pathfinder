#include "pathfinder.h"

static int get_counter_in_array(char *array, char name, int i)
{
    int counter = i;
    while (array[counter] != name)
        counter++;
    return counter;
}
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

t_list *mx_graph_parse_island(char **array)
{
    char **arr = array;
    int dedline = 0;
    char *temp = NULL;
    t_list *list = NULL;
    for (int i = 1; arr[i] != NULL; i++)
    {
        dedline = 0;
        temp = NULL;

        dedline = get_counter_in_array(arr[i], '-', 0);
        temp = mx_strndup(arr[i], dedline);
        if (!check_list(&list, temp))
            mx_push_back(&list, temp);

        temp = NULL;

        dedline = get_counter_in_array(arr[i], ',', dedline);
        temp = mx_strndup(arr[i], dedline);
        if (!check_list(&list, temp))
            mx_push_back(&list, temp);
        mx_strdel(&temp);
    }
    return list;
}
