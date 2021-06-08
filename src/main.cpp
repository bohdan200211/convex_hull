#include <Polygon.hpp>

int main() {


    Polygon ConvexHull;


    Polygon P({{0, 3}, {2, 2}, {1, 1}, {2, 1},
               {3, 0}, {0, 0}, {3, 3}});


    ConvexHull = P.GetConvexHullJarvisAlgorithm();


    //Print
    std::copy(ConvexHull.begin(),
              ConvexHull.end(),
              std::ostream_iterator<Point>(std::cout, "\n"));

    return 0;
}
