#include "pathfinder.h"

static bool mx_isnumber(char *s) {
    int i = -1;

    while (s[++i])
        if (!mx_isdigit(s[i]))
            return false;
    return true;
}

void mx_validation_first_line(t_main *main) {
    char **array = main->file->array;

    if (!mx_isnumber(array[0]))
        mx_printerr_pf(INVLD_FRST_LINE, NULL);
    else
        main->count_island = mx_atoi(array[0]);
}
