#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

#define MAX 100

int main() {
    int N;
    double x[MAX], y[MAX];
    double length = 0;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
 
    for (int l = 0; l < N; ++l) {
        for (int m = 0; m < l; ++m) {
            length = max(length, sqrt(pow(x[m] - x[l], 2) + pow(y[m] - y[l], 2)));
        }
    }
    
    cout << setprecision(6) << length << endl;

    return 0;
}