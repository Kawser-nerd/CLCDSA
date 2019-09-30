#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    int h, w;
    cin >> h >> w;
    
    cout << (H - h) * (W - w) << endl;
}