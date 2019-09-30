#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    long ans = 0;
    if(K == 0){
        cout << (long)N*(long)N << endl;
        return 0;
    }
    for(int i = K+1; i <= N; i++){
        int m = N%i;
        int n = N/i;
        ans += n*(i-K);
        if(m >= K) ans += m-K+1;
        //cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
}