#include "pathfinder.h"

t_main *mx_main_create(char *argv[])
{
    t_main *main = malloc(sizeof(t_main));
    t_file *file = mx_file_crate(argv);
    
    main->file = file;
    main->islands = NULL;
    main->invalid_line = 0;

    return main;
}
