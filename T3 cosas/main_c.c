#include <stdio.h>
#include <stdlib.h>
#include "module.h"
#define max 9999


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
  int node_count;
  fscanf(input_stream, "%d", &node_count);

  int array[node_count][2];
  int* array_p = calloc(2*node_count + 1, sizeof(int));
  int pos_x;
  int pos_y;
  for (int i=1; i<=node_count; i++) {
    fscanf(input_stream, "%d", &pos_x);
    fscanf(input_stream, "%d", &pos_y);
    array_p[2*i-1] = pos_x;
    array_p[2*i] = pos_y;
    //printf("%d ", array[i][0]);
    //printf("%d \n", array[i][1]);
  }

  int peso[node_count][node_count];
  int x, z;
  int aristas = 0;
  int vertices = node_count;

  for (x=1; x<=vertices;x++){
    for (z=1;z<=vertices;z++){
      //peso[x][z] = abs(array[x][0] - array[z][0]) + abs(array[x][1] - array[z][1]);
      //peso[z][x] = abs(array[x][0] - array[z][0]) + abs(array[x][1] - array[z][1]);
      peso[x][z] = abs(array_p[2*x-1]-array_p[2*z-1]) + abs(array_p[2*x]-array_p[2*z]);
      peso[z][x] = abs(array_p[2*x-1]-array_p[2*z-1]) + abs(array_p[2*x]-array_p[2*z]);
      //printf("Peso %d %d primer %d %d segundo %d %d %d\n", x, z,array_p[2*x-1],array_p[2*x],array_p[2*z-1],array_p[2*z], peso[x][z]);
      //printf("Resta %d %d\n", abs(array_p[2*x-1]-array_p[2*x]), abs(array_p[2*z-1]-array_p[2*z]));
      aristas++;
    }
  //printf("AAAA %d\n", peso[1][2]);
  }
  //printf("Vertices: %d\n", vertices);
  //printf("Artistas: %d\n", aristas);

  int* visitado = calloc(node_count + 1, sizeof(int));
  int* dis = calloc(node_count + 1, sizeof(int));
  int* dis_min = calloc(node_count + 1, sizeof(int));
  int* pos = calloc(node_count + 1, sizeof(int));
  int* pos_min = calloc(node_count + 1, sizeof(int));
  //int visitado[node_count];
  //int dis[node_count];

  /* for (int i=1; i<=vertices; i++){
    visitado[i] = 0;
    dis[i] = 10000;
  } */

  /* visitado[1] = 1;
  dis[1] = 0;
  int recorrido = 0;
  int actual = 1;
  int distancia = 0; */
  int* intersecciones = calloc(node_count + 1, sizeof(int));
  int* intersecciones_min = calloc(node_count + 1, sizeof(int));

  int combinacion = 1;
  int combinaciones = node_count;
  int minimo_intersecciones = 1000;
  int maximo_intersecciones = 0;
  int combinacion_min = 0;

  while (combinacion <= combinaciones) {

    for (int i=1; i<=vertices; i++){
      visitado[i] = 0;
      dis[i] = 10000;
      intersecciones[i] = 0;
    }

    visitado[combinacion] = 1;
    dis[combinacion] = 0;
    int recorrido = 0;
    int actual = combinacion;
    int distancia = 0;

    while (recorrido < node_count){
      for (int i = 1; i <= vertices; i++){
        if (peso[actual][i] != 0){
          if (visitado[i] == 0){
            if (dis[i] > peso[actual][i]){
              dis[i] = peso[actual][i];
              pos[i] = actual;
            }
          }
        }
      }
      //printf("Actual: %d \n", actual);
      for (int i = 1; i<=node_count; i++){
        //printf("%d: %d \n", i, dis[i]);
      }
      //dis va a ser un array con las distancias de cada vertice al actual
      //pos va a ser un array con los vertic
      int distancia = 100000;
      for (int i=1;i<=vertices;i++){
        if (visitado[i] == 0){
          if (dis[i] < distancia){
            distancia = dis[i];
            actual = i;
          }
        }
      }
      visitado[actual] = 1;
      recorrido++;
    } 

    distancia = 0;
    for (int i = 1; i <= vertices; i++){
      if (i != combinacion){
        intersecciones[i]++;
        intersecciones[pos[i]]++;
        distancia = distancia + dis[i];
        //printf("Arista %d %d \n", i, pos[i]);
      }
    }
    maximo_intersecciones = 0;
    for (int i = 1; i <= vertices; i++){
      //printf("Int nodo %d: %d\n", i, intersecciones[i]);
      if (intersecciones[i] > maximo_intersecciones){
        maximo_intersecciones = intersecciones[i];
      }
    }
    //printf("I %d  ", maximo_intersecciones);
    if (maximo_intersecciones <= minimo_intersecciones){
      for (int i = 1; i <= node_count; i++){
        dis_min[i] = dis[i];
        pos_min[i] = pos[i];
        intersecciones_min[i] = intersecciones[i];
      }
      combinacion_min = combinacion;
      minimo_intersecciones = maximo_intersecciones;
    }
    //printf("Distancia minima: %d \n", distancia);
    combinacion++;
  }

  int distancia = 0;
  for (int i = 1; i <= vertices; i++){
    if (i != combinacion){
      distancia = distancia + dis[i];
    }
  }
  //printf("Combinacion min %d interseccionmax: %d\n", combinacion_min, minimo_intersecciones);
  /* for (int i = 1; i <= vertices; i++){
      printf("Int nodo %d: %d\n", i, intersecciones_min[i]);
    } */

  //printf("El grafo termina asi: \n");
  fprintf(output_stream, "%d\n", distancia);
  for (int i = 1; i <= vertices; i++){;
    if (i != combinacion_min){
      fprintf(output_stream, "%d %d %d %d\n", array_p[2*i-1], array_p[2*i], array_p[2*pos_min[i]-1], array_p[2*pos_min[i]]);
    }
  }

  free(array_p);
  free(visitado);
  free(dis);
  free(dis_min);
  free(pos);
  free(pos_min);
  free(intersecciones);
  free(intersecciones_min);

  // Cerrar archivo de input
  fclose(input_stream);

  // Cerrar archivo de output
  fclose(output_stream);

  return 0;
}
