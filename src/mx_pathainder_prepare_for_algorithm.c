#include "pathfinder.h"

void mx_pathainder_prepare_for_algorithm(t_main *main) {
    t_island *iter = main->islands;
    int i = 0;

    while (iter) {
        iter->index = i;
        iter->paths = malloc(sizeof(t_path *) * main->count_island);
        for (int i = 0; i < main->count_island; i++)
            iter->paths[i] = NULL;
        i++;
        iter = iter->next;
    }
}
