#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <ctype.h>

//Error
typedef enum e_error {
    INVLD_CMD_ARGS,
    FILE_DEXIST,
    FILE_EMPTY,
    INVLD_FRST_LINE,
    INVLD_LINE,
    INVLD_NUM_ISLDS
} t_error;

//Struct
typedef struct s_island t_island;
typedef struct s_link t_link;
typedef struct s_path t_path;
typedef struct s_algorithm t_algorithm;
typedef struct s_file t_file;
typedef struct s_main t_main;

struct s_island {
    int index;
    char *name;
    t_link *links;
    t_path **paths;
    t_island *next;
};

struct s_link {
    int weight;
    t_island *linked_island;
    t_link *next;
};

struct s_path {
    t_link *route;
    int dist;
    bool is_shortest;
    t_path *next;
};
struct s_algorithm {
    t_island *start;
    t_island *end;
    int weight;
    t_island *start_remainder;
};

struct s_file {
    int fd;
    char *name;
    char **array;
};

struct s_main {
    t_file *file;
    t_island *islands;
    t_algorithm *algorithm;
    int count_island;
};

//Validation
void mx_printerr_pf(t_error err, const char *s);
void mx_validation(t_main *main);
void mx_validation_cmd_args(int argc);
void mx_validation_file_dexist(t_main *main);
void mx_validation_first_line(t_main *main);
void mx_validation_num_islnd(t_main *main);
void mx_validation_check_delim(char **array);
void mx_validation_check_island_one_isalpha(char **array);
void mx_validation_check_island_two_isalpha(char **array);
void mx_validation_check_number(char **array);
//Graph island
t_island *mx_graph_island_create(char *name);
void mx_graph_island_add(t_island **islands, t_island *island);
t_island *mx_graph_island_get(t_island **islands, char *name);
//Graph link
t_link *mx_graph_link_create(t_island *linked_island);
void mx_graph_link_add(t_link **links, t_link *link);
void mx_graph_link_push_back(t_link **links, t_link *link);
void mx_graph_link_pop_back(t_link **links);
void mx_graph_link_set(t_link **links, t_island *linked_island, int weight);
//Graph path
t_path *mx_graph_path_create(t_link *routes);
void mx_graph_path_push_front(t_path **paths, t_path *path);
void mx_graph_path_push_back(t_path **paths, t_path *path);
//Pathainder
void mx_pathainder_parse(t_main *main);
void mx_pathainder_algorithm(t_main *m);
void mx_pathainder_prepare_for_algorithm(t_main *main);
void mx_pathainder_print_paths(t_main *main);
//Until
char **mx_until_file_to_arr(char *file);
void mx_until_bzero(void *s, size_t n);
void *mx_until_memalloc(size_t size);
//Main
t_file *mx_crate_file(char *argv[]);
t_algorithm *mx_create_algorithm();
t_main *mx_create_main(char *argv[]);
int main(int argc, char *argv[]);

#endif
