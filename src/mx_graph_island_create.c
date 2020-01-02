#include "pathfinder.h"

t_island *mx_graph_island_create(char *name) {
    t_island *island = malloc(sizeof(t_island));

    island->links = NULL;
    island->name = name;
    island->next = NULL;
    return island;
}
