#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

Int N,C;

Int solve(vector<Int> &X,vector<Int> &V) {
    vector<Int> dp(N+1,0);
    Int sum = 0;
    for(int i = 0;i < N;i++) {
        sum += V[i];
        dp[i+1] = max(dp[i],sum-2*X[i]);
    }

    Int ret = 0;
    sum = 0;
    for(int i = N-1;i >= 0;i--) {
        sum += V[i];
        Int res = sum - (C-X[i]) + dp[i];
        ret = max(ret,res);
    }

    return ret;
}

int main(void) {
    cin>>N>>C;

    vector<Int> XL(N),VL(N);
    vector<Int> XR(N),VR(N);

    for(int i = 0;i < N;i++) {
        cin>>XL[i]>>VL[i];
        XR[N-i-1] = C-XL[i];
        VR[N-i-1] = VL[i];
    }

    Int ans1 = solve(XL,VL);
    Int ans2 = solve(XR,VR);


    Int ans = max(ans1,ans2);

    cout<<ans<<endl;

    return 0;
}