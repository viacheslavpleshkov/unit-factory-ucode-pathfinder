#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <ctype.h>

//Error
typedef enum e_error
{
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

struct s_island
{
    int index;
    char *name;
    t_link *links;
    t_link **paths;
    t_island *next;
};

struct s_link
{
    int weight; 
    t_island *linked_island;
    t_link *next;
};

//Validation
void mx_printerr_pf(t_error err, const char *s);
void mx_validation(int argc, char *argv[]);
void mx_validation_cmd_args(int argc);
void mx_validation_file_dexist(char *argv);
void mx_validation_first_line(char **array);
void mx_validation_num_islnd(char **array);
void mx_validation_check_line(char **array);
//Graph island
t_island mx_graph_create_island(char *name);
void mx_graph_add_island(t_island **islands, t_island *island);
void mx_graph_get_island(t_island **islands, char *name);
//Graph link
t_link *mx_graph_create_link(t_island *linked_island);
void mx_graph_add_link(t_link **links, t_link *l);
void mx_graph_push_back_link(t_link **links, t_link *l);
void mx_graph_set_link(t_link **links, t_island *linked_island, int weight);
//Main
char **mx_file_to_arr(char *file);
char *mx_parse_file(char *file);
t_list *mx_parse_island(char **array);
int main(int argc, char *argv[]);

#endif
