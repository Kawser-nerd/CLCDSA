#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
struct position{
    int y, x;
};

int need_magic_cost[100000];
 
int main(){
    int H, W, D;
    cin >> H >> W >> D;
    position number_position[H * W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int num;
            cin >> num;
            number_position[num - 1] = {i, j};
        }
    }
    for(int i = H * W - D - 1; i >= 0; i--){
        need_magic_cost[i] = need_magic_cost[i + D] + abs(number_position[i].y - number_position[i + D].y) + abs(number_position[i].x - number_position[i + D].x);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int left, right;
        cin >> left >> right;
        cout << need_magic_cost[left - 1] - need_magic_cost[right - 1] << endl;
    }
}