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

    [[nodiscard]] int GetQuadrant () const noexcept {
        if (x >= 0 && y >= 0) {
            return 1;
        } else if (x <= 0 && y >= 0) {
            return 2;
        } else if (x <= 0 && y <= 0) {
            return 3;
        } else {
            return 4;
        }
    }


    friend std::ostream & operator<<(std::ostream & out, const Point & p) {
        out << "("
            << p.x << ", " << p.y
            << ")";

        return out;
    }

    friend bool operator==(const Point & lhs, const Point & rhs) {
        return  lhs.x == rhs.x
                & lhs.y == rhs.y;
    }
};


