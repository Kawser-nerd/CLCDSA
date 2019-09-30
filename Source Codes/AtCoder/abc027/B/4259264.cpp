#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define show(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    int ans = 0;
    int sum = 0;
    rep(i,n)sum += a[i];
    if(sum % n){
        cout << -1 << endl;
        return 0;
    }
    int num = sum / n;
    int hoge = 0;
    int cnt = 0;
    rep(i,n){
        cnt++;
        hoge += a[i];
        if(num * cnt == hoge){
            cnt = 0;
            hoge = 0;
        }else{
            ans++;
        }
    }
    cout << ans << endl;
}