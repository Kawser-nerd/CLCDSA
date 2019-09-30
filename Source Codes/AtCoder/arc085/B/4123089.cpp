#include <iostream>

using namespace std;

int main(){
    int N, Z, W;
    cin >> N >> Z >> W;
    int X[2000];
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }
    int ans = abs(X[N-1]-W);
    if(N >= 2) ans = max(ans, abs(X[N-1]-X[N-2]));
    cout << ans << endl;
}