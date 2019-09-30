#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <cstdlib>
typedef long long ll;
#define fi first
#define se second

using namespace std;

int gcd(int a,int b){
    if(a < b){
        int c = a;
        a = b;
        b = c;
    }
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){

    int n,k;
    cin >> n >> k;

    int ans;
    cin >> ans;
    int mx = ans;
    if (ans == k){
        cout << "POSSIBLE";
        return 0;
    }
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        mx = max(mx,x);
        if(x == k){
            cout << "POSSIBLE";
            return 0;
        }
        ans = gcd(ans,x);
    }

    if(k%ans == 0 && k <= mx) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";

    return 0;
}