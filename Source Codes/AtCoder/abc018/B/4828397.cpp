#include <iostream>
#include <algorithm>

int main(){
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    int l, r, len;
    std::string sBuf;
    for(int i = 0; i < n; ++i){
        std::cin >> l >> r;
        --l;
        --r;
        len = r - l + 1;
        sBuf = s.substr(l, len);
        std::reverse(sBuf.begin(), sBuf.end());
        for(int j = l; j <= r; ++j){
            s.at(j) = sBuf.at(j - l);
        }

    }

    std::cout << s << std::endl;

    return 0;
}