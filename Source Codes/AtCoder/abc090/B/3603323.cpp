#include <iostream>
 
int main() {
    int a, b;   std::cin >> a >> b;
    int ret = 0;
    for (int i = a; i <= b; i++) {
        int l = i / 1000;
        int r = i % 100;
 
        int ll = l / 10;
        int lr = l % 10;
        
        int rl = r / 10;
        int rr = r % 10;
 
        if (lr == rl && ll == rr)   ret++;
    }
 
    std::cout << ret << std::endl;
 
    return 0;
}