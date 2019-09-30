#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
ll powM(ll k, ll n) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2);
    return (((x*x))*powM(k, n%2));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n = 32;
    int num =500;
    cout<<"Case #1 :"<<endl;
    forn(i,0,num) {
        string s;
        int f = i;
        forn(z,0,14) {
            s=to_string(f&1) + s;
            f/=2;
        }
        s="1"+s+"1";
        cout<<s<<s;
        forn(b,2,11) {
            ll degb = 1;
            ll p = 0;
            forn(x,0,16) {
                p+=degb*((int)(s[15-x]-'0'));
                degb*=b;
            }
            cout<<" "<<p;
        }
        cout<<endl;
    }
    // cout<<ans;
}