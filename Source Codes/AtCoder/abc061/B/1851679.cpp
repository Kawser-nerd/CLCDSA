#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    int N,M;
    std::cin >> N >> M;

    std::vector<int> road_map(N);
    for(int road_index = 0 ; road_index < M ; road_index++ )
    {
        int start_pos;
        int dist_pos;
        std::cin >> start_pos >> dist_pos;
        road_map[start_pos - 1]++;
        road_map[dist_pos - 1]++;
    }

    for(const auto& show_road_times : road_map )
    {
        std::cout << show_road_times << '\n';
    }

    return 0;
}