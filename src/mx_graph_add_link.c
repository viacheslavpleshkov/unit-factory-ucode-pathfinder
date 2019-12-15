#include "pathfinder.h"

t_link *mx_graph_create_link(t_island *linked_island)
{
    t_link *link = malloc(sizeof(t_link));
    link->linked_island = linked_island;
    link->next = NULL;
    return link;
}
