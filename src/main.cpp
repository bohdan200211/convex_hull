#include <fstream>

#include <Polygon.hpp>

int main() {
    std::fstream txtFile;
    txtFile.open("ofstream.txt", std::ios_base::out);

    if (!txtFile.is_open()) {
        std::cout << "file is not open";
        abort();
    }

    Polygon P({{0, 3}, {2, 2}, {1, 1}, {2, 1},
               {3, 0}, {0, 0}, {3, 3}});


    //Print
    P.PrintPolygon(/*std::cout*/txtFile, "\n");

    return 0;
}
