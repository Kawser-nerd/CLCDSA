#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::min;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += 2 * min(x[i], k - x[i]);
    }

    cout << sum << endl;
    return 0;
}