//
// Created by Bohdan on 6/8/2021.
//

#pragma once

#include <iostream>


class Point {
public:
    double x;
    double y;

    Point()
            : x(0)
            , y(0) {}

    Point(double _x, double _y)
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
        out << "Point"
            << "("
            << p.x << ", " << p.y
            << ")";

        return out;
    }

    friend bool operator==(const Point & lhs, const Point & rhs) {
        return  lhs.x == rhs.x
                & lhs.y == rhs.y;
    }

    std::string to_json () const noexcept {
        std::stringstream out;
        out << "{"
            << "\"x\"" << ":" << x
            << ","
            << "\"y\"" << ":" << y
            << " }";

        return out.str();
    }
};


