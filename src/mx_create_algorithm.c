#include "pathfinder.h"

t_algorithm *mx_create_algorithm() {
    t_algorithm *algorithm = malloc(sizeof(t_algorithm));

    algorithm->start = NULL;
    algorithm->end = NULL;
    algorithm->start_remainder = NULL;
    return algorithm;
}
