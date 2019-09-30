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
using namespace std;
typedef long long lint;

lint solve(lint a, lint b, lint c, lint x, lint y){
    lint price = 1LL<<32;
    // case 1
    price = min(price, a * x + b * y);
    // case 2
    if(y >= x){
        price = min(price, c * (2 * x) + b * (y - x));
    }
    // case 3
    if(x >= y){
        price = min(price, a * (x - y) + c * (2 * y));
    }
    // case 4
    price = min(price, c * max(2 * x, 2 * y));
    return price;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    lint a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    cout << solve(a, b, c, x, y) << endl;
    return 0;
}