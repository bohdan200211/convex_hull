//
// Created by Bohdan on 6/12/2021.
//

#pragma once

#include "Line.hpp"

#include <list>
#include <iterator>


class AlgoIterator {
public:
    template <class T>
    using container_type = std::list<T>;

    using data_type = Line;


    explicit AlgoIterator(const container_type<container_type<data_type>> & _container)
            : m_Data(_container) {
        m_StepsIterator = m_Data.begin();
        m_LinesIterator = m_StepsIterator->begin();
    }


    void FirstStep()  noexcept { m_StepsIterator = m_Data.begin(); }
    void NextStep()   noexcept { ++m_StepsIterator; }
    bool IsAlgoDone() noexcept { return m_StepsIterator == m_Data.end(); }


    void FirstLine()  noexcept { m_LinesIterator = m_StepsIterator->begin(); }
    void NextLine()   noexcept { ++m_LinesIterator; }
    bool IsStepDone() noexcept { return m_LinesIterator == m_StepsIterator->end(); }


    container_type<data_type>::iterator CurrentLine() { return m_LinesIterator; }

private:
    container_type<data_type>::iterator m_LinesIterator;
    container_type<container_type<data_type>>::iterator m_StepsIterator;
    container_type<container_type<data_type>> m_Data;
};
