#include "pathfinder.h"
void mx_strdell(char **str)
{
    free(*str);
    *str = NULL;
}
char **mx_file_to_arr(char *file)
{
    char *filearr = NULL;
    char **array = NULL;
    char **temp = NULL;

    filearr = mx_file_to_str(file);
    array = mx_strsplit(filearr, '\n');

    temp = array;
    
    mx_del_strarr(&array);
    return temp;
}
