#include "pathfinder.h"

static int get_counter_in_array(char *array, char name)
{
    int counter = 0;
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
static char *strncdup(const char *s1, int end, int start)
{
    int i = start + 1;
    char *duplicate = mx_strnew(end - i);

    int counter = 0;
    while (i != end)
    {
        duplicate[counter] = s1[i];
        counter++;
        i++;
    }
    return duplicate;
}

t_list *mx_validation_check_island(char **array)
{
    char **arr = array;
    int dedline1 = 0;
    int dedline2 = 0;
    char *temp = NULL;
    t_list *list = NULL;
    for (int i = 1; arr[i] != NULL; i++)
    {
        dedline1 = 0;
        dedline2 = 0;
        dedline1 = get_counter_in_array(arr[i], '-');
        temp = mx_strndup(arr[i], dedline1);
        if (check_list(&list, temp) == 0)
            mx_push_back(&list, temp);
        temp = NULL;
        mx_strdel(&temp);
        dedline2 = get_counter_in_array(arr[i], ',');
        temp = strncdup(arr[i], dedline2, dedline1);
        if (check_list(&list, temp) == 0)
            mx_push_back(&list, temp);
        temp = NULL;
        mx_strdel(&temp);
    }
    mx_strdel(arr);
    return list;
}
