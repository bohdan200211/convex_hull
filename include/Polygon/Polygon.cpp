//
// Created by Bohdan on 6/8/2021.
//

#include "Polygon.hpp"

Polygon::Polygon() noexcept
        : m_Points({}) {}

Polygon::Polygon(const PointContainer &_arr) {
    if (_arr.size() < 3) {
        throw std::runtime_error("Must be at least 3 points");
    }

    m_Points = _arr;
}

Polygon::Orientation Polygon::GetOrientation(Point p, Point q, Point r) const noexcept {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    return (val == 0)
           ? Orientation::Colinear
           : (val > 0)
             ? Orientation::Clock
             : Orientation::Counterclock;
}

Polygon Polygon::GetConvexHullJarvisAlgorithm() const noexcept {
    const size_t n = m_Points.size();

    std::list<Point> result;

    auto tempLeft = std::min_element(m_Points.begin(),
                                     m_Points.end(),
                                     [](const Point &a, const Point &b) -> bool {
                                         return a.x < b.x;
                                     }
    );

    int l = std::distance(m_Points.begin(), tempLeft);
    int p = l;
    int q;

    do {
        result.push_back(m_Points[p]);

        q = (p + 1) % n;

        for (int i = 0; i < n; ++i) {
            if (GetOrientation(m_Points[p], m_Points[i], m_Points[q]) == Orientation::Counterclock) {
                q = i;
            }
        }

        p = q;

    } while (p != l);

    return Polygon(PointContainer(result.begin(), result.end()));
}