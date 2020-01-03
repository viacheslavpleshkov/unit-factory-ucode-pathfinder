#include "pathfinder.h"

int static get_file_length(const char *file) {
    int length = 0;
    int file_descriptor = -1;
    char buffer[1];

    if (!file)
        return -1;
    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor < 0)
        return -1;
    while (read(file_descriptor, buffer, 1))
        length++;
    if (close(file_descriptor) < 0)
        return -1;
    return length;
}

void mx_validation_file_empty(t_main *main) {
    if (get_file_length(main->file->name) == 0)
        mx_printerr_pf(FILE_EMPTY, main->file->name);
}
