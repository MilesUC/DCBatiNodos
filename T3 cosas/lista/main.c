#include <stdio.h>
#include <stdlib.h>

#define INF 10000000
#define MaxSize 10000
int graph[MaxSize][MaxSize];  // MaxSize es el número máximo de vértices
int dis[MaxSize];             // dis [i] es la distancia más corta desde el punto de origen al vértice i
int visit[MaxSize];            // visit [i] marca si se ha encontrado la ruta más corta del vértice i. visit [i] == 1 significa que se ha encontrado
int prevetrix[MaxSize];       // Punto de conducción delantero
void dij(int n, int start)
{    
    int count = 0;          // recuento es el número de vértices que han encontrado el camino más corto
    visit[start] = 1;    
    prevetrix[start] = 0;    
    count++;    
    for (int i = 1; i < n; i++)    // inicialización
    {        
        dis[i] = graph[start][i];        
        prevetrix[i] = 0;    
    }    
    while (count < n)    
    {        
        int min = INF, target_index;        
        for (int i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && min > dis[i])         // Encuentra el vértice con la distancia más corta desde la fuente target_index
            {                
                min = dis[i];                
                target_index = i;            
            }        
        }        
        visit[target_index] = 1;        
        count++;        
        for (int i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && dis[target_index] + 
            graph[target_index][i] < dis[i])            //Actualizar
            {                
                dis[i] = dis[target_index] + graph[target_index][i];
                prevetrix[i] = target_index;            
            }        
        }    
    }
}

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

  int a, b, w, path[n];    
  for (int i = 0; i < n; i++)    
  {        
      for (int j = 0; j < n; j++)        
      {            
          graph[i][j] = INF; 
          graph[j][i] = INF;         
      }    
  }    
  for (int i = 0; i < m; i++)    
  {        
      fscanf(input_stream, "%d %d %d", &a, &b, &w);        
      graph[a][b] = w;  
      graph[b][a] = w;    
  }     
  dij(n, start);    
  printf("\n\n");   

  if (dis[end] == INF)        
  {            
      printf("No hay una ruta más corta desde el vértice %d al vértice %d \n",start, end);        
  }        
  else        
  {            
    printf("La ruta más corta desde el vértice %d al vértice %d es %d:",start, end,dis[end]);            
    int cur = end, index = 0;            
      path[index] = cur;            
      while (1)            
      {                
          path[index + 1] = prevetrix[path[index]];                
          if (path[index + 1] == 0)                    
              break;                
          index++;            
      }   
      printf("%d->", start);           
      for (int j = index; j > 0; j--)            
      {                
          printf("%d->", path[j]);            
      }            
      printf("%d\n", path[0]);        
  }    

  
  // Cerrar archivo de input
  fclose(input_stream);

  // Cerrar archivo de output
  fclose(output_stream);

  return 0;
}
