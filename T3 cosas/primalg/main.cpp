#include <iostream>
#include "GraphMatrix.h"

int main()
{
    GraphMatrix matrix(9);
    matrix.CombinePoint(1,2,10);
    matrix.CombinePoint(1,6,11);
    matrix.CombinePoint(2,3,18);
    matrix.CombinePoint(2,7,16);
    matrix.CombinePoint(2,9,12);
    matrix.CombinePoint(3,4,22);
    matrix.CombinePoint(3,9,8);
    matrix.CombinePoint(4,5,20);
    matrix.CombinePoint(4,7,24);
    matrix.CombinePoint(4,8,16);
    matrix.CombinePoint(4,9,21);
    matrix.CombinePoint(5,6,26);
    matrix.CombinePoint(5,8,7);
    matrix.CombinePoint(6,7,17);
    matrix.CombinePoint(7,8,19);
    matrix.PrintAll();
    matrix.Prim(1);

    return 0;
}