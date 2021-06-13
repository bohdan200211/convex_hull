//
// Created by Bohdan on 6/8/2021.
//

#include <doctest/doctest.h>

#include <Polygon.hpp>

TEST_CASE("Jarvis's Algorithm") {
    AlgoIterator Correct1 ({
        {
            { Point(0, 4), Point(1, 0), Line::LinkType::Solid }
        },
        {
            { Point(1, 0), Point(4, 4), Line::LinkType::Solid }
        },
        {
            { Point(0, 4), Point(4, 4), Line::LinkType::Solid },
            { Point(0, 4), Point(1, 0), Line::LinkType::Dashed },
            { Point(1, 0), Point(4, 4), Line::LinkType::Dashed }
        },
        {
            { Point(4, 4), Point(5, 0), Line::LinkType::Solid }
        },
        {
            { Point(5, 0), Point(4, 4), Line::LinkType::Solid }
        },
        {
            { Point(4, 4), Point(1, 0), Line::LinkType::Solid }
        },
        {
            { Point(5, 0), Point(1, 0), Line::LinkType::Solid },
            { Point(5, 0), Point(4, 4), Line::LinkType::Dashed },
            { Point(4, 4), Point(1, 0), Line::LinkType::Dashed }
        },
        {
            { Point(1, 0), Point(0, 4), Line::LinkType::Solid }
        }
    }
    );

    SUBCASE("test1") {
        Polygon ConvexHull;


        Polygon P({
            {0, 3}, {2, 2}, {1, 1}, {2, 1},
            {3, 0}, {0, 0}, {3, 3}
        });


        ConvexHull = P.GetStepsOfJarvisAlgorithm();

        CHECK(ConvexHull.isEqual(Correct1));
    }

    SUBCASE("test2") {
        Polygon ConvexHull;


        Polygon P({
            {-1, -2}, {-3, 1}, {0, 5}, {6, 4},
            {8, 1}, {6, -4}, {0, 0}, {1, 3},
            {5, -3}, {4, 1}
        });


        ConvexHull = P.GetStepsOfJarvisAlgorithm();

        CHECK(ConvexHull.isEqual(Correct2));
    }
}
