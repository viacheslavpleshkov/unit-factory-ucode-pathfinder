#include "pathfinder.h"

void mx_validation_file_dexist(t_main *main) {
    int fd = main->file->fd;

    if (fd < 0)
        mx_printerr_pf(FILE_DEXIST, main->file->name);
}
