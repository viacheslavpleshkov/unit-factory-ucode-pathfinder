#include "pathfinder.h"

void mx_graph_path_push_back(t_path **paths, t_path *path) {
    if (paths == NULL || *paths == NULL)
        *paths = path;
    else {
        t_path *temp = *paths;
        
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = path;
    }
}
