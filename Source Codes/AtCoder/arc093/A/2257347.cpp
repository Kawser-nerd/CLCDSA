#include <iostream>
#include <vector>

static const int INF = 1001001001;

int main()
{
    int N;
    int sum = 0;
    std::cin >> N;
    std::vector<int> A(N + 2);
    A.at(0) = 0;
    for (unsigned i = 1; i < N + 1; ++i) {
        std::cin >> A.at(i);
    }
    A.at(N + 1) = 0;
    for (unsigned i = 0; i < N + 1; ++i) {
        sum += abs(A.at(i + 1) - A.at(i));
    }
    for (unsigned i = 0; i < N; ++i) {
        std::cout << sum - abs(A.at(i + 1) - A.at(i)) - abs(A.at(i + 2) - A.at(i + 1)) + abs(A.at(i + 2) - A.at(i)) << std::endl;
    }

    return 0;
}