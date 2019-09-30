#include <iostream>
using namespace std;

int main(){
    int N, S, T, W;
    cin >> N >> S >> T >> W;
    int ans = 0;
    
    if(S <= W && W <= T){
            ans++;
    }
    for(int i = 0; i < N-1; ++i){
        int a; cin >> a;
        W += a;
        if(S <= W && W <= T){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}