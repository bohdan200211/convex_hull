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

    [[nodiscard]] PointContainer::const_iterator begin() const { return m_Points.begin(); }

    [[nodiscard]] PointContainer::const_iterator end() const { return m_Points.end(); }

private:
    [[nodiscard]] Orientation GetOrientation(Point p, Point q, Point r) const noexcept;
};

