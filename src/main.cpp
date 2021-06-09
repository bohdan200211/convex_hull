#include <Polygon.hpp>

int main() {


    Polygon ConvexHull;


    Polygon P({{0, 3}, {2, 2}, {1, 1}, {2, 1},
               {3, 0}, {0, 0}, {3, 3}});


    ConvexHull = P.GetConvexHullJarvisAlgorithm();


    //Print
    ConvexHull.PrintPolygon();

    return 0;
}
