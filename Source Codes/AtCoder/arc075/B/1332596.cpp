#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
??????????? ???  
????? ??? ??´<_? ?? Welcome to My Coding Space!
???? ? ´_?`??/? ?i     
?????????? ?  |?|     
??? /?? /????/??|  
? ?_(__??/?    ?/ .| .|????  
? ????/????/??u??  
---------------------------------------------------------------------------------------------------*/
 
 
typedef long long ll;
int N, A, B, H[101010];
//---------------------------------------------------------------------------------------------------
bool check(ll x) {
    ll c = 0;
    rep(i, 0, N) {
        ll h = 1LL * H[i] - 1LL * x * B;
        if (h <= 0) continue;
        c += h / A;
        if (h % A) c++;
    }
    return c <= x;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> A >> B;
    A -= B;
    rep(i, 0, N) cin >> H[i];
 
    int ng = 0, ok = 1010101010;
    while (ng + 1 != ok) {
        int x = (ng + ok) / 2;
        if (check(x)) ok = x;
        else ng = x;
    }
    cout << ok << endl;
}