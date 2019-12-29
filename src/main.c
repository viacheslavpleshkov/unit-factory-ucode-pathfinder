#include "pathfinder.h"

t_main *main_install(t_main *main, char *argv[])
{
    int file;
    file = open(argv[1], O_RDONLY);
    main = mx_main_create();
    main->filename = argv[1];
    main->file = file;
    return main;
}

int main(int argc, char *argv[])
{
    t_main *main = NULL;
    mx_validation_cmd_args(argc);
    main = main_install(main, argv);
    mx_validation(main);
    mx_graph_parse(main);

    //mx_graph_algorithm(main);
    //mx_print_paths(main);
    system("leaks -q pathfinder");
}
