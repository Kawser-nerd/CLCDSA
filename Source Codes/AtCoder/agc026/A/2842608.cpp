#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <limits.h>

using namespace std;

int main(int argc, char const* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int pre_color = 0;
    int color_count = 1;
    int count = 0;
    for (int i=0; i<N; ++i) {
        int ai;
        cin >> ai;
        if (ai == pre_color) {
            ++color_count;
        }
        else {
            count += color_count / 2;
            color_count = 1;
            pre_color = ai;
        }
    }
    count += color_count / 2;
    cout << count << endl;
    return 0;
}