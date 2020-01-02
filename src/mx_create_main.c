#include "pathfinder.h"

t_main *mx_create_main(char *argv[]) {
    t_main *main = malloc(sizeof(t_main));
    t_file *file = mx_crate_file(argv);
    t_algorithm *algorithm = mx_create_algorithm();

    main->file = file;
    main->islands = NULL;
    main->count_island = 0;
    main->algorithm = algorithm;
    return main;
}
