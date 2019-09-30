#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;   cin >> n >> m;
    int cities[50] = {};
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cities[a-1]++;
        cities[b-1]++;
    }
    for (int i = 0; i < n; i++) cout << cities[i] << endl;
    return 0;
}