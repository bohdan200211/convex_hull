//
// Created by Bohdan on 6/12/2021.
//

#pragma once

#include <sstream>
#include "Point.hpp"

class Line {
public:
    enum class LinkType {Dashed = 0, Solid};

    Point p1;
    Point p2;
    LinkType type;

    Line(const Point & _p1, const Point & _p2, LinkType _type)
        : p1(_p1)
        , p2(_p2)
        , type(_type) {}

    friend std::ostream & operator<<(std::ostream & out, const Line & stp) {
        out << "\t"
            << "{ "
            << stp.p1 << ", "
            << stp.p2 << ", "
            << (stp.type == Line::LinkType::Solid
                ? "Line::LinkType::Solid"
                : "Line::LinkType::Dashed")
            << " },";

        return out;
    }

    std::string to_json () const noexcept {
        std::stringstream out;
        out << "{"
            << "\"startPoint\":"
            << p1.to_json() << ","
            << "\"endPoint\":"
            << p2.to_json() << ","
            << "\"isSolid\"" << ":"
            << (type == Line::LinkType::Solid
                ? 1
                : 0)
            << "}";

        return out.str();
    }
};
