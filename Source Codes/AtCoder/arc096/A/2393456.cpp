#include <iostream>
#include <vector>
int main() {
    int A,B,C,X,Y;
    std::cin >> A >> B >> C >> X >> Y;
    
    int max_num = X>Y ? X : Y;
    std::vector<int> mon_ary(max_num+1);
    for (int i=0; i <= max_num; i++) {
        int temp_A_num = X-i > 0 ? X-i : 0;
        int temp_B_num = Y-i > 0 ? Y-i : 0;
        mon_ary[i] = temp_A_num*A + temp_B_num*B + 2*i*C;
    }
    std::cout << *std::min_element(mon_ary.begin(),mon_ary.end()) << std::endl;
    return 0;
}