#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"


// Problem:
// Given N pairs of edges. Check if the graph is a spanning tree.
// INPUT:
// k lines with format a1 b1 a2 b2 that indicates an edge between nodes 1 and 2.
// OUTPUT:
// 1 if the graph is a spanning tree, 0 otherwise.


int main(int argc, char **argv) {
    int edges = 0;
    Node *root = NULL;

    FILE* input = fopen(argv[1], "r");

    int a1, b1;
    Node *node1, *node2;
    while (fscanf(input, "%d %d", &a1, &b1) == 2) {
        edges++;
        if (root == NULL) {
            root = initialize_root(a1);
        }

        node1 = find_or_create_node(root, a1);
        node2 = find_or_create_node(root, b1);
        insert_neighbor(node1, node2);
    }
    printf("Edges count: %d\n", edges);

    djkastra(root, inicial, final);

    return 0;
}