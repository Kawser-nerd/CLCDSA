#include <iostream>
using namespace std;

typedef long long ll; 

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int main()
{
    ll n, a;
    
    cin >> n;
    
    cin >> a;
    
    int res = a;
    
    --n;
    
    while(n--)
    {
        cin >> a;
        res = gcd(res, a);
    }
    
    cout << res;
    
    return 0;
}