//
// Created by Bohdan on 6/12/2021.
//

#pragma once

#include "Point.hpp"

class Step {
public:
    enum class LinkType {Dashed = 0, Solid};

    Point p1;
    Point p2;
    LinkType type;

    Step(const Point & _p1, const Point & _p2, LinkType _type)
        : p1(_p1)
        , p2(_p2)
        , type(_type) {}

    friend std::ostream & operator<<(std::ostream & out, const Step & stp) {
        out << "\t{\n"
            << "\t\t"
            << stp.p1 << ", "
            << stp.p2 << ", "
            << (stp.type == Step::LinkType::Solid
                ? "Solid"
                : "Dashed")
            << "\n\t}";

        return out;
    }
};
