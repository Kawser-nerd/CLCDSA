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
long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    ll n;
    cin>>t;
    forn(i,0,t) {
        cout<<"Case #"<<i+1<<": ";
        cin>>n;
        if(n==0) {
            cout<<"INSOMNIA"<<endl;
            continue;
        }
        vb seen(10,false);
        ll k=0;
        while(1){
            k++;
            ll m = n*(ll)k;
            while(m>0) {
                seen[m%10]=true;
                m/=10;
            }
            bool f =true;
            forn(i,0,10) f=f&&seen[i];
            if(f) cout<<n*(ll)k<<endl;
            if(f)break;
        }
    }
}