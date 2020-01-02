#include "pathfinder.h"

t_island *mx_graph_island_get(t_island **islands, char *name) {
    t_island *temp_islands = *islands;
    t_island *last_island;

    if (!temp_islands) {
        *islands = mx_graph_island_create(name);
        return *islands;
    }
    while (temp_islands) {
        if (mx_strcmp(temp_islands->name, name) == 0) {
            mx_strdel(&name);
            return temp_islands;
        }
        if (temp_islands->next == NULL)
            last_island = temp_islands;
        temp_islands = temp_islands->next;
    }
    last_island->next = mx_graph_island_create(name);
    return last_island->next;
}
