#include<iostream>
using namespace std;
int N, sum = 0;

int main() {
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int k = 0; k < N; k++) {
        sum += a[k] - 1;
    }
    cout << sum << endl;
    
    return 0;
}