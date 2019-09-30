#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    int T,A;
    cin >> N;
    cin >> T >> A;
    int h[N];
    for (int i = 0;i<N;i++){
        cin >> h[i];
    }
    double temin = abs(A - (T - 0.006*h[0]));
    int p = 0;
    double n;
    for (int i = 0;i<N;i++){
        n = abs(A - (T - 0.006*h[i]));
        if (n < temin){
            p = i;
            temin = n;
        }
    }
    cout << p + 1 <<endl;
}