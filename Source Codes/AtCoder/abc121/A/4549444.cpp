#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>

using namespace std;

int main(void) {
    int H,W;
    int h,w;
    cin >> H;
    cin >> W;
    cin >> h;
    cin >> w;

    int sum = H * W;
    int diff = (H * w) + (W * h - w * h);
    int ans = sum - diff;
    cout << ans << endl;  
    return 0;
}