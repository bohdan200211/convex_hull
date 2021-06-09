//
// Created by Bohdan on 6/8/2021.
//

#include <doctest/doctest.h>

#include <Polygon.hpp>

TEST_CASE("Jarvis's Algorithm") {
    Polygon Correct1 ({{3, 0}, {0, 0}, {3, 3}, {0, 3}});
    Polygon Correct2 ({{-1, -2}, {-3, 1}, {0, 5}, {6, 4}, {8, 1}, {6, -4}});

    SUBCASE("test1") {
        Polygon ConvexHull;


        Polygon P({{0, 3}, {2, 2}, {1, 1}, {2, 1},
                   {3, 0}, {0, 0}, {3, 3}});


        ConvexHull = P.GetConvexHullJarvisAlgorithm();

        CHECK(ConvexHull.isEqual(Correct1));
    }

    SUBCASE("test2") {
        Polygon ConvexHull;


        Polygon P({
            {-1, -2}, {-3, 1}, {0, 5}, {6, 4},
            {8, 1}, {6, -4}, {0, 0}, {1, 3},
            {5, -3}, {4, 1}
        });


        ConvexHull = P.GetConvexHullJarvisAlgorithm();

        CHECK(ConvexHull.isEqual(Correct2));
    }
}
