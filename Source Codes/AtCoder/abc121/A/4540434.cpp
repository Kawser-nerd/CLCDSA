#include <iostream>

int main(){
    int H, W, h, w;
    std::cin >> H >> W >> h >> w;

    std::cout << H*W - (h*W + w*H - h*w) << std::endl;

    return 0;
}