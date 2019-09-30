#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;

long long int gcd(long long int x,long long int y){
    long long int r;
    if(x == 0 || y == 0)  return 0;
    while((r = x % y) != 0) 
    {
         x = y;
        y = r;
    }
    return y;
}

int main(){
    int t; cin >> t;
    rep(i,t){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        if(a < b || d < b){cout << "No" << endl; continue;}
        if(b <= c){cout << "Yes" << endl; continue;}
        if(b == 1){cout << "Yes" << endl; continue;}
      	if(d % b == 0 && a % b > c){cout << "No" << endl; continue;}
        else if(d % b == 0){cout << "Yes" << endl; continue;}
        d = d % b;
        ll gc = gcd(b , d);
        if(b-c-1 >= gc){cout << "No" << endl; continue;}
        if((c%gc) < a%gc){cout << "No" << endl; continue;}
      
		cout << "Yes" << endl;
    }
    return 0;
}