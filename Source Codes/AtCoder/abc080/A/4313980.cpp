#include <iostream>
using namespace std;


int main() {
    int n, a, b; cin >> n >> a >> b;
    cout << min(a*n, b) << endl;
    return 0;
}