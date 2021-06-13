//
// Created by Bohdan on 6/13/2021.
//

#include <Polygon.hpp>

int main() {
    Polygon P1({
        {10, 0}, {6, 5}, {1, 1},
        {-2, 0}, {3, -2}, {9, -7}
    });

    Polygon P2({
        {0, 4}, {1, 0}, {4, 4}, {5, 0}
    });


    AlgoIterator itr = P2.GetStepsOfJarvisAlgorithm();


    itr.FirstStep();
    while (!itr.IsAlgoDone()) {
        itr.FirstLine();

        std::cout << "{" << std::endl;
        while (!itr.IsStepDone()) {
            std::cout << *itr.CurrentLine() << std::endl;

            itr.NextLine();
        }
        std::cout << "}," << std::endl;

        itr.NextStep();
    }


    std::cout << "end" << std::endl;

    return 0;
}
