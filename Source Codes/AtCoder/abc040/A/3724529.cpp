#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    cout << min(x-1, n-x) << endl;
}