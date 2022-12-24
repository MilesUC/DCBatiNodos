#include "graph.h"

void insert_neighbor(Node *node, Node *neighbor, int cost) {
    node->neighbors[node->neighbors_count] = neighbor;
    node->distancias[node->neighbors_count] = cost;
    node->neighbors_count++;

    neighbor->neighbors[neighbor->neighbors_count] = node;
    neighbor->distancias[neighbor->neighbors_count] = cost;
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
    new_node->distancias = calloc(MAX_NEIGHBORS, sizeof(int));
    new_node->next = NULL;
    prev->next = new_node;
    return new_node;
}

Node* initialize_root(int id) {
    Node *root = calloc(1, sizeof(Node));
    root->id = id;
    root->neighbors = calloc(MAX_NEIGHBORS, sizeof(Node*));
    root->neighbors_count = 0;
    root->distancias = calloc(MAX_NEIGHBORS, sizeof(int));
    root->next = NULL;
    root->visited = 0;
    return root;
}

int djkastra(Node* root, int inicial, int final, int n){
    Node* inicio = root;
    int distancia = 0;
    int count = 0;
    int distancias[n];

    while (inicio != NULL){
        if (inicio->id == inicial){
            inicio->visited = 1;
            break;
        }
        inicio = inicio->next;
    }

    if (inicio == NULL){
        printf("Vertice no encontrado");
        return 0;
    }

    for (int h = 0; h < n; h ++){
        int esta = 0;
        int dis;
        for (int j = 0; j < inicio->neighbors_count; j++){
            if (inicio->neighbors[j]->id == h){
                esta = 1;
                dis = inicio->distancias[j];
            }
        }
        if (esta == 1){
            distancias[h] = dis;
        }
        else if (h == inicio->id){
            distancias[h] = 0;
        }
        else{
            distancias[h] = 1000000;
        }
    }

    /* for (int i = 0; i < n; i++){
        printf("%d\n", distancias[i]);
    } */

    Node* actual = inicio;
    while (count < n-1){
        if (!actual){
            break;
        }
        int minimo = 1000000;
        Node* nodo_minimo = NULL;
        for (int j = 0; j < actual->neighbors_count; j++){
            if (actual->distancias[j] < minimo && actual->distancias[j] != 0 && actual->neighbors[j]->visited == 0){
                minimo = actual->distancias[j];
                nodo_minimo = actual->neighbors[j];
            }
        }
        /* printf("%d %d\n", nodo_minimo->id ,minimo); */
        nodo_minimo->visited = 1;
        count++;

        for (int k = 0; k < nodo_minimo->neighbors_count; k++){
            if (distancias[nodo_minimo->neighbors[k]->id] > distancias[nodo_minimo->id] + nodo_minimo->distancias[k]){
                distancias[nodo_minimo->neighbors[k]->id] = distancias[nodo_minimo->id] + nodo_minimo->distancias[k];
            }
        }
        actual = actual->next;
    }
    /* printf("Distancias:\n");
    for (int i = 0; i < n; i++){
        printf("%d\n", distancias[i]);
    }
    printf("End\n"); */
    return distancias[final];
}