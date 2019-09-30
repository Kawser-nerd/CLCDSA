#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[]) {
    int N;
    std::cin >> N;

    std::vector<int> house_positions;
    for(int times = 0 ; times < N ; times++ )
    {
        int house_position;
        std::cin >> house_position;
        house_positions.push_back(house_position);
    }

    auto max_distance_house = std::max_element(house_positions.begin(),house_positions.end());
    auto min_distance_house = std::min_element(house_positions.begin(),house_positions.end());

    std::cout << *max_distance_house - *min_distance_house << '\n';

    return 0;
}