//
// Created by Bohdan on 6/8/2021.
//

#include "Polygon.hpp"

Polygon::Polygon() noexcept
        : m_Points({}) {}

Polygon::Polygon(const PointContainer & _arr) {
    if (_arr.size() < 3) {
        throw std::runtime_error("Must be at least 3 points");
    }

    m_Points = _arr;

    std::sort(m_Points.begin(),
              m_Points.end(),
              [] (const Point & p1, const Point & p2) -> bool {
                  return p1.x < p2.x;
              }
    );
}

Polygon::Orientation Polygon::GetOrientation(Point p, Point q, Point r) const noexcept {
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    return (val == 0)
           ? Orientation::Colinear
           : (val > 0)
             ? Orientation::Clock
             : Orientation::Counterclock;
}

AlgoIterator Polygon::GetStepsOfJarvisAlgorithm() const noexcept {
    const size_t n = m_Points.size();
    std::list<std::list<Line>> AlgorithmSteps;


//    bool isUpperPartFinished = false;
    int currentPoint = 0;

    //можна використати модифікований стек
    std::vector<int> ConvexHull(n + 1);
    int stackIterator = -1;



    ConvexHull[++stackIterator] = currentPoint;
    currentPoint = currentPoint + 1;

    while (currentPoint < n) {
        std::list<Line> lstOfLines1;
        lstOfLines1.emplace_back(m_Points[ConvexHull[stackIterator]],
                                 m_Points[currentPoint],
                                 Line::LinkType::Solid);
        AlgorithmSteps.push_back(lstOfLines1);


        ConvexHull[++stackIterator] = currentPoint;

        while (stackIterator > 1
               && GetOrientation(m_Points[ConvexHull[stackIterator]],
                                 m_Points[ConvexHull[stackIterator - 2]],
                                 m_Points[ConvexHull[stackIterator - 1]])
                                 == Orientation::Counterclock) {

            std::list<Line> lstOfLines2;
            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 2]],
                                     m_Points[ConvexHull[stackIterator]],
                                     Line::LinkType::Solid);

            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 2]],
                                     m_Points[ConvexHull[stackIterator - 1]],
                                     Line::LinkType::Dashed);

            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 1]],
                                     m_Points[ConvexHull[stackIterator]],
                                     Line::LinkType::Dashed);
            AlgorithmSteps.push_back(lstOfLines2);

            ConvexHull[stackIterator - 1] = ConvexHull[stackIterator];
            --stackIterator;
        }
        currentPoint = currentPoint + 1;
    }



    int sizeOfUpperHull = stackIterator;

    currentPoint = currentPoint - 2;
    while (currentPoint > -1) {
        std::list<Line> lstOfLines1;
        lstOfLines1.emplace_back(m_Points[ConvexHull[stackIterator]],
                                 m_Points[currentPoint],
                                 Line::LinkType::Solid);
        AlgorithmSteps.push_back(lstOfLines1);


        ConvexHull[++stackIterator] = currentPoint;

        while (stackIterator - sizeOfUpperHull > 1
               && GetOrientation(m_Points[ConvexHull[stackIterator]],
                                 m_Points[ConvexHull[stackIterator - 2]],
                                 m_Points[ConvexHull[stackIterator - 1]])
                                 == Orientation::Counterclock) {

            std::list<Line> lstOfLines2;
            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 2]],
                                     m_Points[ConvexHull[stackIterator]],
                                     Line::LinkType::Solid);

            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 2]],
                                     m_Points[ConvexHull[stackIterator - 1]],
                                     Line::LinkType::Dashed);

            lstOfLines2.emplace_back(m_Points[ConvexHull[stackIterator - 1]],
                                     m_Points[ConvexHull[stackIterator]],
                                     Line::LinkType::Dashed);
            AlgorithmSteps.push_back(lstOfLines2);

            ConvexHull[stackIterator - 1] = ConvexHull[stackIterator];
            --stackIterator;
        }
        currentPoint = currentPoint - 1;
    }



    return AlgoIterator(AlgorithmSteps);
//    return Polygon(PointContainer(result.cbegin(), result.cend()));
}

bool Polygon::isContain(const Polygon & P) const noexcept {
    return std::all_of(P.cbegin(),
                       P.cend(),
                       [&] (const Point & q) -> bool {
                           return std::find(m_Points.cbegin(), m_Points.cend(), q)
                                            != m_Points.cend();
                       }
    );
}

bool Polygon::isEqual(const Polygon & P) const noexcept {
    return m_Points.size() == P.m_Points.size() && isContain(P);
}

void Polygon::PrintPolygon(std::ostream & out, const char * delimiter) const noexcept {
    std::copy(m_Points.cbegin(),
              m_Points.cend(),
              std::ostream_iterator<Point>(out, delimiter));
}
