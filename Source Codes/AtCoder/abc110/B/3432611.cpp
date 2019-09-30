#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x, y;
    for (size_t i = 0; i < N; i++) {
        int p;
        cin >> p;
        x.push_back(p);
    }
    x.push_back(X);
    for (size_t i = 0; i < M; i++) {
        int p;
        cin >> p;
        y.push_back(p);
    }
    y.push_back(Y);

    int x_max = *max_element(x.begin(), x.end());
    int y_min = *min_element(y.begin(), y.end());

    if( x_max < y_min ) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
}