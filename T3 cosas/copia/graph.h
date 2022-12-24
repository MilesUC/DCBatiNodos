#pragma once

#include <stdlib.h>
#include <stdio.h>

#define MAX_NEIGHBORS 1024

typedef struct node_t {
    int id;
    struct node_t **neighbors;
    struct node_t *next;
    int visited;
    int neighbors_count;
    int *distancias;
} Node;

void insert_neighbor(Node *graph, Node *neighbor, int cost);

Node* find_or_create_node(Node *root, int id);

Node* initialize_root(int id);

int djkastra(Node* root, int inicial, int final, int n);