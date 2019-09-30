#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N, M;
    int X[100005];
    int diff[100005];
    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> X[i];

    sort(X, X+M);
    for (int i = 0; i < M-1; ++i) diff[i] = X[i+1] - X[i];
    sort(diff, diff+(M-1));
    
    int ans = 0;
    for (int i = 0; i < M-N; ++i) ans += diff[i];    
    cout << ans << endl;

    return 0;
}