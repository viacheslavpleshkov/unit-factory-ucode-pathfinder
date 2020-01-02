#include "pathfinder.h"

char **mx_until_file_to_arr(char *file) {
    char *filearr = NULL;
    char **array = NULL;

    filearr = mx_file_to_str(file);
    array = mx_strsplit(filearr, '\n');
    mx_strdel(&filearr);
    return array;
}
