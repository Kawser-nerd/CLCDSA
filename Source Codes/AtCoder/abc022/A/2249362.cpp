#include <iostream>

int main(void)
{
    int n, s, t, w;
    std::cin >> n >> s >> t >> w;
    int best = 0;
    auto diff = new int[n];
    diff[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> diff[i];
    }
    int weight = w;
    for (int i = 0; i < n; ++i)
    {
        weight += diff[i];
        if ((s <= weight) && (weight <= t))
        {
            ++best;
        }
    }
    std::cout << best << std::endl;
    return 0;
}