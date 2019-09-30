#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int W, H;
    cin >> W >> H;

    cout << (W / 4 * 3 == H ? "4:3" : "16:9") << endl;
    return 0;
}