#include "pathfinder.h"

void mx_graph_add_island(t_island **islands, t_island *island) {
    if (!*islands) {
        *islands = island;
        return;
    }
    island->next = *islands;
    *islands = island;
}