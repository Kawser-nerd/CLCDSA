#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N,K;
    cin >> N >> K;
    int h[N];
    for (int i = 0;i<N;i++){
        cin >> h[i];
    }
    sort(h,h+N);
    int temin = h[K-1] - h[0];
    for (int i = 0;i < N -K + 1;i++){
        if((h[K-1+i] - h[i]) < temin){
            temin = h[K-1+i] - h[i];
        }
    }
    cout << temin << endl;
}