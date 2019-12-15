#include "pathfinder.h"

t_island *mx_create_island(char *name)
{
    t_island *island = malloc(sizeof(t_island));

    island->links = NULL;
    island->name = name;
    island->next = NULL;
    return island;
}
