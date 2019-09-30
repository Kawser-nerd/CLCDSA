#include <iostream>
#include <climits>
#include <cmath>
#define endl '\n'
#define ll long long

using namespace std;
ll max(ll a, ll b) { return a > b ? a : b;}
int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    ll ret = LLONG_MAX;
    
    for(int i = 0; i < 2000001; i += 2)
    {
        ll A_pizza = max(0, X - i / 2);
        ll B_pizza = max(0, Y - i / 2);
        ll total = A_pizza * A + B_pizza * B + i * C;
        ret = min(ret, total);
    }
    cout << ret << endl;
    return 0;
}