#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, T;
    int c[1000];
    int t[1000];
    
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> c[i] >> t[i];
    }
    
    int min_cost = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        if (T >= t[i]) {
            if (min_cost > c[i]) {
                min_cost = c[i];
            }
        }
    }
    
    if (min_cost == numeric_limits<int>::max()) {
        cout << "TLE" << endl;
    } else {
        cout << min_cost << endl;
    }
    
    return 0;
}