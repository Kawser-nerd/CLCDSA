#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    int ans;

    if (N == 100){
        ans = pow(100, D) * (N + 1);
    } else {
        ans = pow(100, D) * N;        
    }

    cout << ans << endl;
    return 0;
}