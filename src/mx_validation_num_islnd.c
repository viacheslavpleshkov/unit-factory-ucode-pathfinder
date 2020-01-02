#include "pathfinder.h"

void mx_validation_num_islnd(t_main *main) {
    t_island *iter = main->islands;
    int count = 0;

    while (iter) {
        count++;
        iter = iter->next;
    }
    if (main->count_island != count)
        mx_printerr_pf(INVLD_NUM_ISLDS, NULL);
}
