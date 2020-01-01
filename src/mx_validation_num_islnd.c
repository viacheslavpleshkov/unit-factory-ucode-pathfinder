#include "pathfinder.h"

void mx_validation_num_islnd(t_main *main)
{
    t_list *name = mx_validation_check_island(main->file->array);
    int leng = mx_list_size(name);

    if (leng != main->count_island)
        mx_printerr_pf(INVLD_NUM_ISLDS, NULL);
    mx_del_list(name, leng);
}
