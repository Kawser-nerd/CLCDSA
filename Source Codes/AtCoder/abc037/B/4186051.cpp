#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int a[N];
    
    for (int j {0}; j < N; j++) {
        a[j] = 0;
    }
    
    int l[Q];
    int r[Q];
    int t[Q];
    for (int i {0}; i < Q; i++) {
        cin >> l[i] >> r[i] >> t[i];
        for (int k {l[i] - 1}; k < r[i]; k++) {
            a[k] = t[i];
        }
    }
    
    for (int b {0}; b < N; b++) {
        cout << a[b] << endl;
    }
}