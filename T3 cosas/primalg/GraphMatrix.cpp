#include <stack>
#include "GraphMatrix.h"

GraphMatrix::GraphMatrix()
{
    matrix = NULL;
    m_size = 0;
}

GraphMatrix::GraphMatrix(int Size)
{
    m_size = Size;
    matrix = new int*[m_size];
    for(int i = 0;i < m_size;i ++)
        matrix[i] = new int[m_size];
    for(int i = 0;i < m_size;i ++)
    {
        for(int j = 0;j < m_size;j ++)
        {
            if(i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
        }
    }
}

GraphMatrix::~GraphMatrix()
{
    for(int i = 0;i < m_size;i ++)
        delete[] matrix[i];
    delete[] matrix;
}

bool GraphMatrix::CombinePoint(int a, int b)
{
    bool isCombine = false;
    if(a<=0||a>m_size||b<=0||b>m_size||a==b)
    {
        std::cout<<"Error index!"<<std::endl;
        return isCombine;
    }

    if((matrix[a-1][b-1] != 0 || matrix[b-1][a-1] != 0) && (matrix[a-1][b-1] != INF || matrix[b-1][a-1] != INF))
    {
        std::cout<<"Have combined point "<<a<<","<<b<<"!"<<std::endl;
        return isCombine;
    }
    isCombine = true;
    matrix[a-1][b-1] = 1;
    matrix[b-1][a-1] = 1;
    return isCombine;
}

bool GraphMatrix::CombinePoint(int a, int b, int power)
{
    bool isCombine = false;
    if(a<=0||a>m_size||b<=0||b>m_size||a==b)
    {
        std::cout<<"Error index!"<<std::endl;
        return isCombine;
    }

    if(power==0)
    {
        std::cout<<"Power can't be zero!"<<std::endl;
        return isCombine;
    }

    if((matrix[a-1][b-1] != 0 || matrix[b-1][a-1] != 0) && (matrix[a-1][b-1] != INF || matrix[b-1][a-1] != INF))
    {
        std::cout<<"Have combined point "<<a<<","<<b<<"!"<<std::endl;
        return isCombine;
    }
    isCombine = true;
    matrix[a-1][b-1] = power;
    matrix[b-1][a-1] = power;
    return isCombine;
}

void GraphMatrix::PrintAll()
{
    for(int i = 0;i < m_size;i ++)
    {
        //std::cout<<i+1<<"|";
        for(int j = 0;j < m_size;j ++)
        {
            /*if(matrix[i][j] == INF)
                std::cout<<"-1 ";
            else*/
                std::cout<<matrix[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }
}

void GraphMatrix::Prim(int start_index)// Función Prim en la clase GraphMatrix
{
    if(start_index<0||start_index>=m_size)
    {
        std::cout<<"Error index!"<<std::endl;
        return;
    }
    int lowcost[m_size]; // Almacena la ruta mínima de vértices relacionados
    int lowcostpoint;// Registra el vértice correspondiente al peso mínimo
    int min;// Seleccione el peso mínimo según su conveniencia
    
    bool visit[m_size];// Juzgar si el nodo ha sido visitado
    for(int i = 0;i < m_size;i ++)// Inicializar la matriz de acceso
        visit[i] = false;
    int cont = 0;//contar
    int adjvex[m_size];// Almacenar vértices relacionados
    int V[m_size];// Almacenar el orden de acceso
    

    V[cont] = start_index;// Agregar nodo de inicio
    visit[start_index-1] = true;
    cont++;

    int sum = 0;//Peso total
    for(int i = 0;i < m_size;i ++)
 	{
        lowcost[i] = matrix[start_index-1][i];
        adjvex[i] = start_index - 1;
    }

    for(int i = 1;i < m_size;i ++)// Debido a que se ha visitado el primer punto, para evitar el uso de cont para acceder a V fuera de límites, cambie i = 0 a i = 1
    {
        min = INF;
        for(int j = 0;j < m_size;j ++)// Encuentra el valor mínimo y el punto de bajo costo correspondiente
        {
            if(min > lowcost[j] && !visit[j] && lowcost[i] != 0)
            {
                min = lowcost[j];
                lowcostpoint = j;
            }
        }
        sum += lowcost[lowcostpoint];
        visit[lowcostpoint] = true;
        V[cont] = lowcostpoint + 1;
        cont++;
        for(int j = 0;j < m_size;j ++)
        {
            if(!visit[j])
            {
                min = INF;
                for(int k = 0;k < m_size;k ++)// Para un solo nodo que no ha sido visitado, busque el nodo con el menor peso para el nodo visitado
                {
                    if(min > matrix[j][k] && visit[k])// Lo que se necesita es el nodo que se ha visitado
                    {
                        min = matrix[j][k];
                        adjvex[j] = k;// Esto es necesario si necesita un árbol de expansión
                    }
                }
                lowcost[j] = min;
            }
            else// Ya visitado, el bajo costo se establece en INF
            {
                lowcost[j] = INF;
            }
        }
    }
    std::cout<<sum;
    std::cout<<std::endl;

    for(int i = 0;i < m_size;i ++)
    {
        std::cout<<V[i]<<" ";
    }
    std::cout<<std::endl;
}
