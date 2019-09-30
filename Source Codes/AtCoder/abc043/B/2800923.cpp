#include <iostream>
#include <cstdio>
#include <string>

int main() {
    std::string str;   std::cin >> str;
    std::string ans;
    for (auto s: str) {
        if (s != 'B') ans += s;
        else if (!ans.empty()) {
            auto it = ans.end();
            ans.erase(--it);
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}