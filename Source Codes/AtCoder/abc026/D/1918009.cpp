#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

double f(int a, int b, int c, double t) {
    return a * t + b * sin(c * t * M_PI);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // [low, high)
    double low = 0;
    double high = INF;

    for(int i = 0; i < 1e3; i++){
        double mid = (high + low) / 2;
        if(f(a, b, c, mid) > 100){
            high = mid;
        }else{
            low = mid;
        }
    }

    cout << std::fixed << std::setprecision(16) << low << endl;

    return 0;
}