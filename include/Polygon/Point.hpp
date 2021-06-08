//
// Created by Bohdan on 6/8/2021.
//

#pragma once

#include <iostream>


class Point {
public:
    int x;
    int y;

    Point()
            : x(0)
            , y(0) {}

    Point(int _x, int _y)
            : x(_x)
            , y(_y) {}

    friend std::ostream & operator<<(std::ostream & out, const Point & p) {
        out << "("
            << p.x << ", " << p.y
            << ")";

        return out;
    }
};


