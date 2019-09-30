#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;


int main(){

   
    ll n,k;
    cin >> n >> k;
    //cout << n << k << endl;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
        if(a[i] == 0){
            cout << n << endl;
            return 0;
        }
    }

    ll i = 0,j = 0;
    ll ans = 0;
    ll now = 1;
    ll len = 0;

    while(j < n){

        if(now * a[j] <= k){
            now *= a[j];
            j++;
            len++;
        }else{

            ans = max(ans,len);

            while(now * a[j] > k && i <j){
                now /= a[i];
                i++;
                len--;
            }
            
            if(j == i &&a[j]*now>k){
                now = 1;
                j++;
                i++;
                len = 0;
            }
        }
    
    }
    cout << max(ans,len) << endl;

    return 0;
}