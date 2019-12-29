#include "pathfinder.h"

void mx_graph_island_add(t_island **islands, t_island *island) {
    if (!*islands) {
        *islands = island;
        return;
    }
    island->next = *islands;
    *islands = island;
}
