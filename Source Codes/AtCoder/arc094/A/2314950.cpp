#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int memo[128][128][128];

int main(void){
    vector<int> a(3);
    int ans = 0;

    rep(i,3) cin >> a[i];

    sort(a.begin(), a.end());
    int x;
    x = a[2] - a[0];
    x/=2;
    a[0] += x * 2;
    ans += x;

    x = a[2] - a[1];
    x/=2;
    a[1] += x * 2;
    ans += x;

    sort(a.begin(), a.end());
    if(a[0] + 1 == a[1] + 1 && a[1] + 1 == a[2]){
        ans += 1;
    }else if(a[0] + 1 == a[1] && a[1] == a[2]){
        ans += 2;
    }
    cout << ans << endl;
    return 0;
}