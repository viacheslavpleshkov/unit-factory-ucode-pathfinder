#include "pathfinder.h"

t_path *mx_graph_path_create(t_link *route) {
    t_path *path = mx_until_memalloc(sizeof(t_path));
    t_link *iter = route;
    t_link *ptr;

    path->route = mx_graph_link_create(route->linked_island);
    path->route->weight = route->weight;
    path->next = NULL;
    ptr = path->route;
    while (iter->next) {
        ptr->next = mx_graph_link_create(iter->next->linked_island);
        ptr->next->weight = iter->next->weight;
        ptr = ptr->next;
        iter = iter->next;
    }
    return path;
}
