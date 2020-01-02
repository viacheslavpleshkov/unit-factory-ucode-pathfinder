#include "pathfinder.h"

void mx_graph_link_set(t_link **links, t_island *linked_island, int weight) {
    t_link *iter = *links;
    t_link *last_link;

    if (!iter) {
        *links = mx_graph_link_create(linked_island);
        (*links)->weight = weight;
        return;
    }
    while (iter) {
        if (linked_island == iter->linked_island)
            return;
        if (iter->next == NULL)
            last_link = iter;
        iter = iter->next;
    }
    last_link->next = mx_graph_link_create(linked_island);
    last_link->next->weight = weight;
}
