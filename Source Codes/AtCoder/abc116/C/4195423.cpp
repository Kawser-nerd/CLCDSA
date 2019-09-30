#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, h[102];
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> h[i];
    }
    h[0] = 0;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(h[i-1] < h[i]){
            ans += h[i] - h[i-1];
        }
    }
    cout << ans <<"\n";
}