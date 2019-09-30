#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<long> h(N);
    for (int i = 0; i < N; ++i){
        cin >> h[i];
    } 
    sort(h.begin(), h.end());
    long MIN = 1000000001;
    K--;
    for(int i = 0; i < (N - K); ++i){
        MIN = min(h[i+K] - h[i], MIN);
    }
    cout << MIN << endl;
    return 0;
}