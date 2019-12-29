#include "pathfinder.h"

t_main *mx_main_create()
{
    t_main *main = malloc(sizeof(t_main));

    main->file = 0;
    main->filename = NULL;
    main->islands = NULL;

    return main;
}
