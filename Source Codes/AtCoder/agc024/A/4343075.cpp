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

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    long long a, b, c, k;
    std::cin >> a >> b >> c >> k;
    long long sign = (k % 2 == 0) ? 1 : -1;
    long long ans = (a - b) * sign;
    std::cout << ans << std::endl;
    return 0;
}