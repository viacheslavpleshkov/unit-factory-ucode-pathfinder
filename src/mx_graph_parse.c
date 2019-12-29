#include "pathfinder.h"

void mx_graph_parse(t_main *main)
{
    char **array = mx_file_to_arr(main->filename);
    char **ptr;
    char *ptr1;
    t_island *island1;
    t_island *island2;
    int weight;
    for (int i = 1; array[i] != NULL; i++)
    {
        ptr = mx_strsplit(array[i], '-');
        island1 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
        ptr1 = mx_strdup(ptr[1]);
        mx_del_strarr(&ptr);
        ptr = mx_strsplit(ptr1, ',');
        mx_strdel(&ptr1);
        island2 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
        weight = mx_atoi(ptr[1]);
        mx_del_strarr(&ptr);
        mx_graph_link_set(&island1->links, island2, weight);
        mx_graph_link_set(&island2->links, island1, weight);
    }
}
