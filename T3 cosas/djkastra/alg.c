#include <stdio.h>
#define INF 10000000
#define MaxSize 50
int graph[MaxSize][MaxSize];  // MaxSize es el número máximo de vértices
int dis[MaxSize];             // dis [i] es la distancia más corta desde el punto de origen al vértice i
int visit[MaxSize];            // visit [i] marca si se ha encontrado la ruta más corta del vértice i. visit [i] == 1 significa que se ha encontrado
int prevetrix[MaxSize];       // Punto de conducción delantero
void dij(int n)
{    
    int count = 0;          // recuento es el número de vértices que han encontrado el camino más corto
    visit[0] = 1;    
    prevetrix[0] = 0;    
    count++;    
    for (int i = 1; i < n; i++)    // inicialización
    {        
        dis[i] = graph[0][i];        
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
int main()
{    
    int n, m;    
    scanf("%d %d", &n, &m);    
    int a, b, w, path[n];    
    for (int i = 0; i < n; i++)    
    {        
        for (int j = 0; j < n; j++)        
        {            
            graph[i][j] = INF;        
        }    
    }    
    for (int i = 0; i < m; i++)    
    {        
        scanf("%d %d %d", &a, &b, &w);        
        graph[a][b] = w;    
    }     
    dij(n);    
    printf("\n\n");    
    for (int i = 1; i < n; i++)    
    {        
        if (dis[i] == INF)        
        {            
            printf("No hay una ruta más corta desde el vértice 0 al vértice% d \ n", i);        
        }        
        else        
        {            
    	    printf("La ruta más corta desde el vértice 0 al vértice% d es% d:", i,dis[i]);            
    	    int cur = i, index = 0;            
            path[index] = cur;            
            while (1)            
            {                
                path[index + 1] = prevetrix[path[index]];                
                if (path[index + 1] == 0)                    
                    break;                
                index++;            
            }            
            for (int j = index + 1; j > 0; j--)            
            {                
                printf("%d->", path[j]);            
            }            
            printf("%d\n", path[0]);        
        }    
    }
}