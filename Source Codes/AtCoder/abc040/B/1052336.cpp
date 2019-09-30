#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min_cost = 100001;
    for(int i = (int)sqrt(n); i > 0; i--) {
        int other_edge = n / i;
        int rest_pieces = n - other_edge * i;
        int cost = rest_pieces + other_edge - i;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    cout << min_cost << endl;
}