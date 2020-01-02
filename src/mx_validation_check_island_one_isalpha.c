#include "pathfinder.h"

void mx_validation_check_island_one_isalpha(char **array) {
    char **arr = array;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '-'; j++) {
            if (mx_isalpha(arr[i][j]) == false)
                mx_printerr_pf(INVLD_LINE, mx_itoa(i + 1));
        }
        if (mx_isalpha(arr[i][0]) == false)
            mx_printerr_pf(INVLD_LINE, mx_itoa(i + 1));
    }
}
