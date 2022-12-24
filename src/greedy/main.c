#include <stdio.h>
#include <stdlib.h>

//Basado en código extraido de https://programmerclick.com/article/33681712894/

int graph[10000][10000];  // MaxSize es el número máximo de vértices
int dis[10000];             // dis [i] es la distancia más corta desde el punto de origen al vértice i
int visit[10000];            // visit [i] marca si se ha encontrado la ruta más corta del vértice i. visit [i] == 1 significa que se ha encontrado
int prevetrix[10000];       // Punto de conducción delantero
void dij(int n, int start)
{    
    int count = 0;          // recuento es el número de vértices que han encontrado el camino más corto
    visit[start] = 1;    
    prevetrix[start] = 0;    
    count++;    
    for (int i = 1; i < n; i++)    // inicialización
    {        
        dis[i] = graph[start][i];       
        //printf("Start: %d i: %d\n", start, i); 
        prevetrix[i] = 0;    
    }          
    while (count < n)    
    {        
        int min = 100000, target_index;        
        for (int i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && min > dis[i])         // Encuentra el vértice con la distancia más corta desde la fuente target_index
            {                
                min = dis[i];                
                target_index = i;    
                //printf("Target definido: %d min: %d\n", target_index, min);          
            }        
        }        
        visit[target_index] = 1;        
        count++;        
        for (int i = 1; i < n; i++)        
        {            
            //if (count < 50){printf("target: %d i: %d aux: %d\n", target_index, i, graph[target_index][i]);} 
            if (visit[i] == 0 && dis[target_index] + graph[target_index][i] < dis[i])            //Actualizar
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

  int inputs[m][3];

  int a, b, w, path[n];    
  for (int i = 0; i < n; i++)    
  {        
      for (int j = 0; j < n; j++)        
      {            
          graph[i][j] = 100000; 
          graph[j][i] = 100000;         
      }    
  }    
  for (int i = 0; i < m; i++)    
  {        
      fscanf(input_stream, "%d %d %d", &a, &b, &w);     
      inputs[i][0] = a;
      inputs[i][1] = b;
      inputs[i][2] = w;   
      graph[a][b] = w;  
      graph[b][a] = w;    
  }     


  dij(n, start);    
  printf("\n\n");   

  fprintf(output_stream, "%d", dis[end]);

  
  // Cerrar archivo de input
  fclose(input_stream);

  // Cerrar archivo de output
  fclose(output_stream);

  return 0;
}
