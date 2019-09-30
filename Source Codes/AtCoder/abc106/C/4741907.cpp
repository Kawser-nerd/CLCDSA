#include <iostream>


int main() {
    std::string s;
    long long int k;
    std::cin >> s >> k;
    char ans = '1';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '1') {
            if (k > i) {
                ans = s[i];
                break;
            }
        }
    }
    std::cout << ans << std::endl;
}