#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    int n; std::cin >> n;
    int res = 0;
    std::string s; std::cin >> s;
    std::vector<char> us;

    for (char c : s) {
        if (std::count(us.begin(), us.end(), c) == 0) {
            us.push_back(c);
        }
    }
    // std::cout << "us???" << std::endl;
    // for (char c: us) {
    //     std::cout << c << std::endl;
    // }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (char c : us) {

            // int leftSideCount = std::count(s.begin(), s.begin() + i, c);
            // int rightSideCount = std::count(s.begin() + i, s.end(), c);
            // std::cout << "i:" << i << std::endl;
            // std::cout << "c: " << c << std::endl;
            // std::cout << "leftSideCount: " << leftSideCount << std::endl;
            // std::cout << "rightSideCount: " << rightSideCount << std::endl;
            // std::cout << "* * * *" << std::endl;
            if (std::count(s.begin(), s.begin() + i, c) != 0 && std::count(s.begin() + i, s.end(), c) != 0) {
                cnt++;
            }
            // std::cout << "cnt: " << cnt << std::endl;
        }
        res = std::max(cnt, res);
    }

    std::cout << res << std::endl;

    return 0;
}