#include "pathfinder.h"

void mx_validation(t_main *main)
{
    char **filearr = NULL;

    mx_validation_file_dexist(main);
    filearr = main->file->array;
    mx_validation_first_line(filearr);
    mx_validation_check_line(filearr);
    mx_validation_num_islnd(filearr);
}
