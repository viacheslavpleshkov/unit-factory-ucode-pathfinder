#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_main *main = NULL;

    mx_validation_cmd_args(argc);
    main = mx_create_main(argv);
    mx_validation(main);
    mx_pathainder_parse(main);
    mx_pathainder_prepare_for_algorithm(main);
    mx_pathainder_algorithm(main);
    mx_pathainder_print_paths(main);
    return 0;
}
