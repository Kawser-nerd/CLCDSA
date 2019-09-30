#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define ll long long
#define INF 1000000000000000000

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <ios>
#include <iomanip>

using namespace std;

//=================================================================
//Grand Contest 029 A
int main(){
    string S;
    cin >> S;
    ll b=0;
    ll w=0;
    ll ans=0;
    ll ans2=0;

    for(ll i=0; i< S.length(); i++){
        if(S[i]=='B'){
            b++;
        }else{
            ans += b;
            ans2 += i-w;
            w++;
        }
        //cout << ans << " " << ans2 << endl;
    }
    cout << ans2 << endl;
}