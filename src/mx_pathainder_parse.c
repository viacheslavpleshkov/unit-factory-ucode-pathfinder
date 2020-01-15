#include "pathfinder.h"

static void save_islands(t_island *island1, t_island *island2, int weight, int i) {
    mx_graph_link_set(&island1->links, island2, weight);
    mx_graph_link_set(&island2->links, island1, weight);
    mx_validation_check_weight(i, weight);
}

void mx_pathainder_parse(t_main *main) {
    char **ptr = NULL;
    char *ptr1 = NULL;
    t_island *island1 = NULL;
    t_island *island2 = NULL;
    int weight;

    for (int i = 1; main->file->array[i] != NULL; i++) {
        ptr = mx_strsplit(main->file->array[i], '-');
        island1 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
        ptr1 = mx_strdup(ptr[1]);
        mx_del_strarr(&ptr);
        ptr = mx_strsplit(ptr1, ',');
        mx_strdel(&ptr1);
        island2 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
        weight = mx_atoi(ptr[1]);
        mx_del_strarr(&ptr);
        save_islands(island1, island2, weight, i);
    }
    mx_validation_num_islnd(main);
}
