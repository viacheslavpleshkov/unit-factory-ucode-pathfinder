#include "pathfinder.h"

void mx_validation(t_main *main)
{
    char *file = NULL;
    char **filearr = NULL;

    mx_validation_file_dexist(main);
    file = mx_file_to_str(main->filename);
    filearr = mx_strsplit(file, '\n');
    mx_validation_first_line(filearr);
    mx_validation_check_line(filearr);
    // mx_validation_num_islnd(filearr);
    // mx_del_strarr(&filearr);
}
