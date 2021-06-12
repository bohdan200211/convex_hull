//
// Created by Bohdan on 6/8/2021.
//

#pragma once

#include "Point.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <iterator>

class Polygon {
private:
    enum class Orientation {
        Colinear = 0, Clock, Counterclock
    };
    using PointContainer = std::vector<Point>;

    PointContainer m_Points;

public:
    Polygon() noexcept;

    explicit Polygon(const PointContainer &_arr);

    [[nodiscard]] Polygon GetConvexHullJarvisAlgorithm() const noexcept;

    [[nodiscard]] bool isContain (const Polygon & P) const noexcept;

    [[nodiscard]] bool isEqual (const Polygon & P) const noexcept;

    [[nodiscard]] PointContainer::const_iterator cbegin() const { return m_Points.begin(); }

    [[nodiscard]] PointContainer::const_iterator cend() const { return m_Points.end(); }

    void PrintPolygon (std::ostream & out, const char * delimiter) const noexcept;

private:
    [[nodiscard]] Orientation GetOrientation(Point p, Point q, Point r) const noexcept;
};

