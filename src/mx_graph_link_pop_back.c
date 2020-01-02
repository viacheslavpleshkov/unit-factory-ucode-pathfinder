#include "pathfinder.h"

void mx_graph_link_pop_back(t_link **links) {
    t_link *l = *links;

    if (*links != NULL) {
        if (l->next == NULL) {
            l->linked_island = NULL;
            free(l);
        }
        else {
            while (l->next->next)
                l = l->next;
            l->next->linked_island = NULL;
            free(l->next);
            l->next = NULL;
        }
    }
}
