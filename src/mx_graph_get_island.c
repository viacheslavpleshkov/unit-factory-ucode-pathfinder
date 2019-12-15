#include "pathfinder.h"

void mx_graph_get_island(t_island **islands, char *name)
{
    t_island *temp_islands = *islands;
    t_island *last_island;

    if (!temp_islands)
    {
        *islands = mx_create_island(name);
        return *islands;
    }
    while (temp_islands)
    {
        if (mx_strcmp(temp_islands->name, name) == 0)
        {
            mx_strdel(&name);
            return temp_islands;
        }
        if (temp_islands->next == NULL)
            last_island = temp_islands;
        temp_islands = temp_islands->next;
    }
    last_island->next = mx_create_island(name);
    return last_island->next;
}