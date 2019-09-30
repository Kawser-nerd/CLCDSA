#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<int> acs(n+1);
    int cur = 0;
    for (int i = 0; i < n+1; i++) {
        if (i+1 < n && s[i] == 'A' && s[i+1] == 'C') {
            acs[i] = acs[i+1] = cur;
            cur++;
            i++;
        } else {
            acs[i] = cur;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << acs[r] - acs[l] << std::endl;
    }
}