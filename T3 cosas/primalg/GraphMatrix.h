#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include <cstddef>// NULL se define en esta función de encabezado
#include <iostream>
#define INF 65535

class GraphMatrix
{
    public:
        GraphMatrix();
        GraphMatrix(int Size);
        virtual ~GraphMatrix();

        bool CombinePoint(int a, int b);
        bool CombinePoint(int a, int b, int power);

        void PrintAll();

        void Prim(int start_index);
    private:
        int **matrix;
        int m_size;
};

#endif // GRAPHMATRIX_H
