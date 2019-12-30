#include "pathfinder.h"

t_file *mx_file_crate(char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    t_file *file = malloc(sizeof(t_file));
    char **array = mx_file_to_arr(argv[1]);

    file->name = argv[1];
    file->fd = fd;
    file->array = array;

    return file;
}
