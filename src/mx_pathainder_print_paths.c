#include "pathfinder.h"

static t_link *get_end_link(t_link *route) {
    t_link *iter = route;

    while (iter->next)
        iter = iter->next;
    return iter;
}

static void print_route(t_link *route) {
    t_link *rt = route;

    mx_printstr("Route: ");
    while (rt) {
        if (rt->next) {
            mx_printstr(rt->linked_island->name);
            mx_printstr(" -> ");
        }
        else
            mx_printstr(rt->linked_island->name);
        rt = rt->next;
    }
    mx_printchar('\n');
}

static void print_distance(t_link *route) {
    t_link *rt = route->next;
    int dist = 0;

    mx_printstr("Distance: ");
    if (!rt->next)
        mx_printint(rt->weight);
    else
        while (rt) {
            dist += rt->weight;
            if (rt->next) {
                mx_printint(rt->weight);
                mx_printstr(" + ");
            }
            else {
                mx_printint(rt->weight);
                mx_printstr(" = ");
                mx_printint(dist);
            }
            rt = rt->next;
        }
    mx_printchar('\n');
}

static void print_paths(t_path *path) {
    t_path *p = path;
    t_link *end_link;

    while (p) {
        if (p->is_shortest) {
            end_link = get_end_link(p->route);
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(p->route->linked_island->name);
            mx_printstr(" -> ");
            mx_printstr(end_link->linked_island->name);
            mx_printstr("\n");
            print_route(p->route);
            print_distance(p->route);
            mx_printstr("========================================\n");
        }
        p = p->next;
    }
}

void mx_pathainder_print_paths(t_main *main) {
    t_island *isl = main->islands;
    t_path *pth;

    while (isl) {
        for (int i = 0; i < main->count_island; i++) {
            pth = isl->paths[i];
            if (pth)
                print_paths(pth);
        }
        isl = isl->next;
    }
}
