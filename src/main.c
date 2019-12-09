#include "pathfinder.h"
#include <stdio.h>
typedef struct s_path
{
    int distance;
    char *a;
    char *b;
    int index_a;
    int index_b;
} t_path;
int mx_islands_index(t_path *p, int current, int max_index)
{
    int j = 0;

    if (current == 0)
    {
        p[current].index_a = 0;
        p[current].index_b = 1;
        max_index = 1;
    }
    while (j < current)
    {
        if (mx_strcmp(p[current].a, p[j].a) == 0)
            p[current].index_a = p[j].index_a;
        else if (mx_strcmp(p[current].a, p[j].b) == 0)
            p[current].index_a = p[j].index_b;
        else if (p[current].index_a == -1 && j == current - 1)
        {
            p[current].index_a = max_index + 1;
            max_index++;
        }
        if (mx_strcmp(p[current].b, p[j].a) == 0)
            p[current].index_b = p[j].index_a;
        else if (mx_strcmp(p[current].b, p[j].b) == 0)
            p[current].index_b = p[j].index_b;
        else if (p[current].index_b == -1 && j == current - 1)
        {
            p[current].index_b = max_index + 1;
            max_index++;
        }
        j++;
    }
    return max_index;
}
// static void graph_main(char *argv[])
// {
//     char **arr = mx_file_to_arr(argv[1]);
//     struct s_graph *graph = mx_graph_create(mx_atoi(arr[0]));
//     mx_graph_add_edge(graph, 0, 1);
//     mx_graph_add_edge(graph, 0, 2);
//     mx_graph_add_edge(graph, 1, 2);
//     mx_graph_add_edge(graph, 2, 3);

//     mx_graph_print(graph);
//     mx_graph_algorithm(graph, 2);
// }

void mx_islands(t_path *p, char *file)
{
    char *fl = mx_file_to_str(file);
    char **WordsA = mx_strsplit(fl, '\n');
    char **str1;
    char **str2;
    int max_index = 0;

    free(fl);
    for (int i = 0; WordsA[++i];)
    {
        str1 = mx_strsplit(WordsA[i], '-');
        str2 = mx_strsplit(str1[1], ',');
        p[i - 1].a = mx_strdup(str1[0]);
        p[i - 1].b = mx_strdup(str2[0]);
        p[i - 1].distance = mx_atoi(str2[1]);
        p[i - 1].index_a = -1;
        p[i - 1].index_b = -1;
        max_index = mx_islands_index(p, i - 1, max_index);
        mx_del_strarr(&str1);
        mx_del_strarr(&str2);
    }
    mx_del_strarr(&WordsA);
}

// int main(int argc, char *argv[])
// {
//     mx_validation(argc, argv);
//     graph_main(argv);
// }
static char **mx_perenos(char *file)
{
    char *str = mx_file_to_str(file);
    char **split = mx_strsplit(str, '\n');

    free(str);
    return split;
}
int main(int ac, char **av)
{
    if (ac == 300) {
        exit(1);
    }
    t_path *p;
    char **a = mx_perenos(av[1]);
    int count = mx_arrlen(a) - 1;
    printf("res = %d\n", count);

    p = (t_path *)malloc(sizeof(t_path) * count);
    mx_islands(p, av[1]);
    printf("----------------\n");
    for (int k = 0; k < count; k++)
    {
        printf("---Apex = %s\n---Apex = %s\n-distance = %d\n index a = %d\n index b = %d\n----------------\n",
               p[k].a, p[k].b, p[k].distance, p[k].index_a, p[k].index_b);
    }

    system("leaks -q a.out");
    return 0;
}
