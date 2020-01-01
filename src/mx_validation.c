#include "pathfinder.h"

void mx_validation(t_main *main)
{
    char **filearr = NULL;

    mx_validation_file_dexist(main);
    filearr = main->file->array;
    mx_validation_first_line(main);
    mx_validation_check_delim(filearr);
    mx_validation_check_island_one_isalpha(filearr);
    mx_validation_check_island_two_isalpha(filearr);
    mx_validation_check_number(filearr);
    mx_validation_num_islnd(main);
}
