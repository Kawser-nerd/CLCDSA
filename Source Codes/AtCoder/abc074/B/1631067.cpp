#include <iostream>
#include <cmath>
#include <vector>

int main(int argc, char const *argv[]) {

    int ball_num;
    int robot_b_start_position;
    std::vector<int> ball_positions;

    /** input datas **/
    std::cin >> ball_num >> robot_b_start_position;
    for (size_t i = 0; i < ball_num; i++) {
        int ball_position;
        std::cin >> ball_position;
        ball_positions.push_back(ball_position);
    }

    /** calculate distance between robot and ball **/
    int sumDistance = 0;
    for(auto ball_position : ball_positions){

        int distance_to_ball_forB = abs(ball_position - robot_b_start_position);
        int distance_to_ball_forA = abs(ball_position - 0);

        int nearDistance = std::min(distance_to_ball_forA,distance_to_ball_forB);
        int totalDistance = nearDistance * 2;

        sumDistance += totalDistance;
    }

    std::cout << sumDistance << '\n';

    return 0;
}