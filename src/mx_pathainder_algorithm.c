#include "pathfinder.h"

static bool is_visited(t_link *visited, t_island *i) {
    t_link *iter = visited;

    if (!iter)
        return false;
    while (iter) {
        if (iter->linked_island->name == i->name)
            return true;
        iter = iter->next;
    }
    return false;
}

static void set_distances(t_path *path) {
    t_path *iter = path;
    t_link *rt;
    int distance;

    while (iter) {
        if (!iter->dist) {
            rt = iter->route;
            distance = 0;
            while (rt) {
                distance += rt->weight;
                rt = rt->next;
            }
            iter->dist = distance;
            distance = 0;
        }
        iter = iter->next;
    }
}

static void check_is_shortest(t_path *path) {
    t_path *iter = path;
    int min_dist = path->dist;

    while (iter) {
        if (iter->dist < min_dist)
            min_dist = iter->dist;
        iter->is_shortest = false;
        iter = iter->next;
    }
    iter = path;
    while (iter) {
        if (iter->dist == min_dist)
            iter->is_shortest = true;
        iter = iter->next;
    }
}

static void find_path(t_main *main, t_link *visited, int weight,
                      t_path **paths) {
    t_link *iter = main->algorithm->start->links;
    t_link *visited_island = NULL;
    t_path *temp = NULL;

    if (is_visited(visited, main->algorithm->start))
        return;
    visited_island = mx_graph_link_create(main->algorithm->start);
    visited_island->weight = weight;
    mx_graph_link_push_back(&visited, visited_island);
    if (main->algorithm->start == main->algorithm->end) {
        temp = mx_graph_path_create(visited);
        mx_graph_path_push_back(&paths[main->algorithm->end->index], temp);
    } else
        while (iter) {
            main->algorithm->start = iter->linked_island;
            find_path(main, visited, iter->weight, paths);
            iter = iter->next;
        }
    mx_graph_link_pop_back(&visited);
}

void mx_pathainder_algorithm(t_main *main) {
    main->algorithm->start = main->islands;
    t_link *visited = NULL;
    //temp -> t
    t_path *t = NULL;

    while (main->algorithm->start) {
        main->algorithm->end = main->algorithm->start->next;
        main->algorithm->start_remainder = main->algorithm->start;
        while (main->algorithm->end) {
            if (main->algorithm->start != main->algorithm->end) {
                find_path(main, visited, 0, main->algorithm->start->paths);
                main->algorithm->start = main->algorithm->start_remainder;
                t = main->algorithm->start->paths[main->algorithm->end->index];
                set_distances(t);
                check_is_shortest(t);
            }
            main->algorithm->end = main->algorithm->end->next;
        }
        main->algorithm->start = main->algorithm->start->next;
    }
}
