#include "pathfinder.h"

void mx_graph_path_push_front(t_path **paths, t_path *path) {
    if (!*paths) {
        *paths = path;
        return;
    }
    path->next = *paths;
    *paths = path;
}
