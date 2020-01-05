#include "pathfinder.h"

void mx_validation_check_end_line(char *array) {
    int delim = 1;

    for (int i = 0; array[i]; i++) {
        if (array[i] == '\n') {
            delim++;
            if (array[i] == array[i + 1])
                mx_printerr_pf(INVLD_LINE, mx_itoa(delim));
        }
    }
    if (array[0] == '\n')
        mx_printerr_pf(INVLD_LINE, mx_itoa(1));
}
