#include "pathfinder.h"

t_algorithm *mx_algorithm_create()
{
    t_algorithm *algorithm = malloc(sizeof(t_algorithm));

    algorithm->start = NULL;
    algorithm->end = NULL;
    algorithm->start_remainder = NULL;

    return algorithm;
}
