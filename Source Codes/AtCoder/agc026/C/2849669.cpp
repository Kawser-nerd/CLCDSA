#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for(int i=2*n-1;i>=n;i--){
        t.push_back(s[i]);
    }
    ll ans = 0;
    for(int bit = 0;bit<(1<<n);bit++){
        string s1,s2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if((bit>>i)&1){
                s1.push_back(s[i]);
                cnt++;
            }else{
                s2.push_back(s[i]);
            }
        }
        ll dp[20][20][20]={};
        dp[0][0][0] = 1;
        for(int i=0;i<n;i++){
                for(int j=1;j<=cnt;j++){
                    for(int k=0;k<=n-cnt;k++){
                        if(t[i]==s1[j-1])dp[i+1][j][k] +=dp[i][j-1][k];
                    }
                }
                for(int j=0;j<=cnt;j++){
                    for(int k=1;k<=n-cnt;k++){
                        if(t[i]==s2[k-1])dp[i+1][j][k] +=dp[i][j][k-1];
                    }
                }
        }
        //cout << s1 << " " << s2 << " " << cnt<< endl;
        ans += dp[n][cnt][n-cnt];
        //cout << ans << endl;
        //if(bit%1000==0)cout << bit << endl;
    }
    cout << ans << endl;
    return 0;
}