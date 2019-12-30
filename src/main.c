#include "pathfinder.h"

int main(int argc, char *argv[])
{
    t_main *main = NULL;
    mx_validation_cmd_args(argc);
    main = mx_main_create(argv);
    mx_validation(main);
    mx_graph_parse(main);
    mx_graph_algorithm(main);
    //mx_print_paths(main);
    system("leaks -q pathfinder");
}
