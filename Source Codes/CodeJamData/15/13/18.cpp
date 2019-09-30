#include <iostream>
using namespace std;

typedef long long ll;

int T, N;
ll x[3005], y[3005];

int solve(int i){
    if(N == 0) return 0;
    int ans = N-1;

    for(int j=0; j<N; j++){
        if(i==j) continue;

        ll A = y[i] - y[j];
        ll B = x[j] - x[i];
        ll C = A * x[i] + B * y[i];

        int bl = 0;
        for(int k=0; k<N; k++)
            bl += A * x[k] + B * y[k] < C;

        ans = min(ans, bl);
        ans = min(ans, N-2-bl);
    }

    return ans;
}

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N;

        for(int i=0; i<N; i++)
            cin >> x[i] >> y[i];

        cout << "Case #" << t << ": \n";
        for(int i=0; i<N; i++)
            cout << solve(i) << "\n";
    }
}
