#include "pathfinder.h"

void mx_validation_num_islnd(char **array)
{
    t_list *name = mx_validation_check_island(array);
    int leng = mx_list_size(name);

    if (leng != mx_atoi(array[0]))
        mx_printerr_pf(INVLD_NUM_ISLDS, NULL);
    mx_del_list(name, leng);
}
