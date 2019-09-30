#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
struct position{
    int y, x;
};
 
int main(){
    int H, W, D;
    cin >> H >> W >> D;
    position number_position[H * W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int num;
            scanf("%d", &num);
            number_position[num - 1] = {i, j};
        }
    }
    int need_magic_cost[H * W];
    for(int i = H * W - D; i < H * W; i++){
        need_magic_cost[i] = 0;
    }
    for(int i = H * W - D - 1; i >= 0; i--){
        need_magic_cost[i] = need_magic_cost[i + D] + abs(number_position[i].y - number_position[i + D].y) + abs(number_position[i].x - number_position[i + D].x);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int left, right;
        scanf("%d%d", &left, &right);
        printf("%d\n", need_magic_cost[left - 1] - need_magic_cost[right - 1]);
    }
}