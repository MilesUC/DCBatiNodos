#include "graph.h"

void insert_neighbor(Node *node, Node *neighbor) {
    node->neighbors[node->neighbors_count] = neighbor;
    node->neighbors_count++;

    neighbor->neighbors[neighbor->neighbors_count] = node;
    neighbor->neighbors_count++;
}

Node* find_or_create_node(Node *root, int id){
    Node *current = root;
    Node *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        prev = current;
        current = current->next;
    }

    Node *new_node = calloc(1, sizeof(Node));
    new_node->id = id;
    new_node->visited = 0;
    new_node->neighbors = calloc(MAX_NEIGHBORS, sizeof(Node*));
    new_node->neighbors_count = 0;
    new_node->next = NULL;
    prev->next = new_node;
    return new_node;
}

Node* initialize_root(int id) {
    Node *root = calloc(1, sizeof(Node));
    root->id = id;
    root->neighbors = calloc(MAX_NEIGHBORS, sizeof(Node*));
    root->neighbors_count = 0;
    root->next = NULL;
    root->visited = 0;
    return root;
}

int djkastra(Node* root, int inicial, int final){
    Node* actual = root;
    int distancia = 0;

    while (actual != NULL){
        if (actual->id == inicial){
            actual->visited = 1;
            break;
        }
        actual = actual->next;
    }

    if (actual == NULL){
        printf("Vertice no encontrado");
        return 0;
    }

    while(actual != NULL){
        for (i = 0, i < actual->neighbors_count; i++){
            if (actual->neighbors[i].)
        }
    }
}