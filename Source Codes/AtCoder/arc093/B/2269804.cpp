#include <iostream>
#include <vector>

int main()
{
    int A, B;
    std::cin >> A >> B;
    int n_white, n_black;
    n_white = A - 1;
    n_black = B - 1;
    std::vector<std::vector<char> > grid(50, std::vector<char>(100));
    for (unsigned i = 0; i < grid.size(); ++i) {
        for (unsigned j = 0; j < 100; ++j) {
            if (j < 50) {
                grid.at(i).at(j) = '.';
            } else {
                grid.at(i).at(j) = '#';
            }
        }
    }

    // create white blocks
    for (unsigned i = 0; i < grid.size(); i += 2) {
        for (unsigned j = 1; j < 49; j += 2) {
            if (n_black > 0) {
                grid.at(i).at(j) = '#';
                --n_black;
            }
        }
        for (unsigned j = 51; j < 99; j += 2) {
            if (n_white > 0) {
                grid.at(i).at(j) = '.';
                --n_white;
            }
        }
    }

    std::cout << 50 << " " << 100 << std::endl;
    for (unsigned i = 0; i < grid.size(); ++i) {
        for (unsigned j = 0; j < 100; ++j) {
            std::cout << grid.at(i).at(j);
        }
        std::cout << std::endl;
    }

    return 0;
}