#include "pathfinder.h"

static void reverse(t_path **head_ref) {
    t_path *prev = NULL;
    t_path *current = *head_ref;
    t_path *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void mx_pathainder_reverse_paths(t_main *main) {
    t_island *islands = main->islands;

    while (islands) {
        for (int i = 0; i < main->count_island; i++)
            reverse(&(islands->paths[i]));
        islands = islands->next;
    }
}
