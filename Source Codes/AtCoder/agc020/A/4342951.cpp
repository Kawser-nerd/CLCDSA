#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

std::string solve(int n, int a, int b){
    const std::string BORYS = "Borys";
    const std::string ALICE = "Alice";
    std::string ret = (abs(b - a) % 2 == 1) ? BORYS : ALICE;
    return ret;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string ans;
    ans = solve(n, a, b);
    std::cout << ans << std::endl;
    return 0;
}