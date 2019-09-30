#include <iostream>
using namespace std;
const int M {100002};

int main() {
    int n, x, b[M] {0};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        b[x]++;
        b[x+1]++;
        b[x+2]++;
    }
    cout << *max_element(b, b + M) << endl;

    return 0;
}