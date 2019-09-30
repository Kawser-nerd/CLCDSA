#include <iostream>
using namespace std;

int main() {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    cout << max({t1, t2, t3}) - min({t1, t2, t3}) << endl;
}