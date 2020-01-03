#include "pathfinder.h"

static void file_dexist(const char *s) {
    mx_printerr("error: file ");
    mx_printerr(s);
    mx_printerr(" does not exist\n");
}

static void file_empty(const char *s) {
    mx_printerr("error: file ");
    mx_printerr(s);
    mx_printerr(" is empty\n");
}

static void invld_line(const char *s) {
    mx_printerr("error: line ");
    mx_printerr(s);
    mx_printerr(" is not valid\n");
}

void mx_printerr_pf(t_error err, const char *s) {
    if (err == INVLD_CMD_ARGS)
        mx_printerr("usage: ./pathfinder [filename]\n");
    if (err == FILE_DEXIST)
        file_dexist(s);
    if (err == FILE_EMPTY)
        file_empty(s);
    if (err == INVLD_FRST_LINE)
        mx_printerr("error: line 1 is not valid\n");
    if (err == INVLD_LINE)
        invld_line(s);
    if(err == INVLD_NUM_ISLDS)
        mx_printerr("error: invalid number of islands\n");
    exit(1);
}
