#include "pathfinder.h"

void mx_graph_link_add(t_link **links, t_link *link) {
    if (!*links) {
        *links = link;
        return;
    }
    link->next = *links;
    *links = link;
}
