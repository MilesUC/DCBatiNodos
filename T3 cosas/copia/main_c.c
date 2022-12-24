#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char** argv)
{
  if(argc != 3)
  {
    printf("Modo de uso: %s input output\nDonde:\n", argv[0]);
    printf("\t\"input\" es la ruta al archivo de input\n");
    printf("\t\"output\" es la ruta al archivo de output\n");
    return 1;
  }

  // Abrimos el archivo de input
  FILE* input_stream = fopen(argv[1], "r");

  // Abrimos el archivo de output
  FILE* output_stream = fopen(argv[2], "w");

  // Si alguno de los dos archivos no se pudo abrir
  if(!input_stream)
  {
    printf("El archivo %s no existe o no se puede leer\n", argv[1]);
    return 2;
  }
  if(!output_stream)
  {
    printf("El archivo %s no se pudo crear o no se puede escribir\n", argv[2]);
    printf("Recuerda que \"fopen\" no puede crear carpetas\n");
    fclose(input_stream);
    return 3;
  }

  // [Aqui va tu tarea]
  int n, m, start, end; 
  fscanf(input_stream, "%d", &n);
  fscanf(input_stream, "%d %d", &start, &end);
  fscanf(input_stream, "%d", &m);

  Node* root = NULL;
  Node* node1 = NULL;
  for (int i=0; i < n; i++){
    if (root == NULL){
      root = initialize_root(i);
    }
    node1 = find_or_create_node(root, i);
  }

  int a, b, w;        
  for (int i = 0; i < m; i++)    
  {        
      fscanf(input_stream, "%d %d %d", &a, &b, &w);   
      Node* node1 = find_or_create_node(root, a);
      Node* node2 = find_or_create_node(root, b);     
      insert_neighbor(node1, node2, w);
  }     

  int r = djkastra(root, start, end, n);
  printf("%d", r);
  //dij(n); 
  
  /* Node* actual = root;
  for (int i=0;i<n;i++){
    printf("Nodo %d\n", actual->id);
    for (int j = 0; j<actual->neighbors_count; j++){
      printf("%d\n", actual->distancias[j]);
    }
    actual = actual->next;
  } */

  // Cerrar archivo de input
  fclose(input_stream);

  // Cerrar archivo de output
  fclose(output_stream);

  return 0;
}
