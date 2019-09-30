#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#define endl '\n'
#define ll long long

// a > b
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll N, X; cin >> N >> X;
    vector<ll> vec; vec.push_back(X);
    for(int i = 0; i < N; i++) { ll temp; cin >> temp; vec.push_back(temp); }
    
    sort(vec.begin(), vec.end());
    
    ll ret = vec[1] - vec[0];
    for(int i = 1; i < N; i++)
    {
        ll dis = vec[i + 1] - vec[i];
        if(ret < dis) swap(ret, dis);
        ret = gcd(ret, dis);
    }
    cout << ret << endl;
    return 0;
}