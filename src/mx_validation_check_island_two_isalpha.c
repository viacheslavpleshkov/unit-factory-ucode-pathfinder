#include "pathfinder.h"

void mx_validation_check_island_two_isalpha(char **array) {
    char **arr = array;
    bool status = false;

    for (int i = 1; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != ','; j++) {
            if (arr[i][j] == '-') {
                status = true;
                j++;
            }
            if ((status == true) && (mx_isalpha(arr[i][j]) == false))
                mx_printerr_pf(INVLD_LINE, mx_itoa(i + 1));
        }
        status = false;
    }
}
