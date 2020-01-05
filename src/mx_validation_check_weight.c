#include "pathfinder.h"

void mx_validation_check_weight(int i, int weight) {
    if (weight < -1)
        mx_printerr_pf(INVLD_LINE, mx_itoa(i + 1));
}
