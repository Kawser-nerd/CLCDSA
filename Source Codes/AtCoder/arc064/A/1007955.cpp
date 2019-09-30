#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
    int n, x;
    cin >> n >> x;
    ll ans = 0, prev = 0;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(prev + a > x){
            ll eat = prev + a - x;
            ans += eat;
            prev = a - eat;
        }else{
            prev = a;
        }
    }
    cout << ans << endl;
    return 0;
}