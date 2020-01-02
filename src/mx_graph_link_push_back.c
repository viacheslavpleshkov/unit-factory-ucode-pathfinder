#include "pathfinder.h"

void mx_graph_link_push_back(t_link **links, t_link *link) {
    t_link *iter = *links;

    if (!*links) {
        *links = link;
        return;
    }
    while (iter->next)
        iter = iter->next;
    iter->next = link;
}
