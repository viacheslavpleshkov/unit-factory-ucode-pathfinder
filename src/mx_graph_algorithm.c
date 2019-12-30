#include "pathfinder.h"

void mx_prepare_for_algorithm(t_main *m)
{
    t_island *iter = m->islands;
    int i = 0;

    while (iter)
    {
        iter->index = i;
        iter->paths = malloc(sizeof(t_island *) * m->count_island);
        for (int i = 0; i < m->count_island; i++)
            iter->paths[i] = NULL;
        i++;
        iter = iter->next;
    }
}

void mx_graph_algorithm(t_main *main)
{
    mx_prepare_for_algorithm(main);
}
