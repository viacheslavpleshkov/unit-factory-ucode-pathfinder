#include "pathfinder.h"

void mx_prepare_for_algorithm(t_main *m)
{
    t_island *iter = m->islands;
    int i = 0;

    while (iter)
    {
        iter->index = i;
        iter->paths = malloc(sizeof(t_path *) * m->count_island);
        for (int i = 0; i < m->count_island; i++)
            iter->paths[i] = NULL;
        i++;
        iter = iter->next;
    }
}

int main(int argc, char *argv[])
{
    t_main *main = NULL;
    mx_validation_cmd_args(argc);
    main = mx_main_create(argv);
    mx_validation(main);
    mx_graph_parse(main);
    mx_prepare_for_algorithm(main);
    mx_graph_algorithm(main);
    mx_print_paths(main);
    system("leaks -q pathfinder");
}
