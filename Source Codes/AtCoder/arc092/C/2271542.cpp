#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<climits>
#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int N;
vector<Int> a(1001);
vector<Int> dp(1001);
vector<int> pre(1001);

int main(void) {
    cin>>N;
    for(int i = 1;i <= N;i++) {
        cin>>a[i];
        dp[i] = a[i];
    }

    for(int i = 1;i <= N;i++) {
        for(int j = i-2;j >= 1;j -=2) {
            if(dp[j]+a[i] > dp[i]) {
                dp[i] = dp[j] + a[i];
                pre[i] = j;
            }
        }
    }

    Int ans = -INT_MAX;
    int index = -1;
    for(int i = 1;i <= N;i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            index = i;
        }
    }

    cout<<ans<<endl;
    vector<int> method;
    for(int i = N;i > index;i--)
        method.push_back(i);
    N = index;

    while(pre[index]) {
        int mid = (index + pre[index]) / 2;
        int c = index - mid;
        while(c--)
        {
            method.push_back(mid);
            mid--;
        }
        index = pre[index];
    }
    for(int i = 1;i < index;i++) {
        method.push_back(1);
    }
    cout<<method.size()<<endl;
    for(auto &&t: method) {
        cout<<t<<endl;
    }

    return 0;
}