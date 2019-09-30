#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    std::vector<int> alpha(26, 0);
    std::string s;

    std::cin >> s;

    for (auto a : s) {
        int c = a - 97;
        alpha.at(c) += 1;
    }

    // ?????????-1???????
    for (auto a : alpha) {
        if (a > 1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    // ???1????????
    for (int i = 0; i < alpha.size(); ++i) {
        if (alpha.at(i) == 0) {
            char new_char = static_cast<char>(i + 97);
            std::cout << s + new_char << std::endl;
            return 0;
        }
    }

    // ????????
    std::string s_rev = s;
    std::reverse(s_rev.begin(), s_rev.end());
    for (int i = 0; i < s_rev.size(); ++i) {
        int c_int = static_cast<int>(s_rev.at(i) - 97);
        for (; c_int < alpha.size(); ++c_int) {
            if (alpha.at(c_int) == 0) {
                char new_char = static_cast<char>(c_int + 97);
                std::string new_s = s.substr(0, s.size()-i-1);
                std::cout << new_s + new_char << std::endl;
                return 0;
            }
        }
        alpha.at(static_cast<int>(s_rev.at(i) - 97)) = 0;
    }
    std::cout << -1 << std::endl;

    return 0;
}