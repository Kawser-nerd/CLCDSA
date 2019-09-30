#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <cmath>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<long long> Vll;
typedef vector<double> Vd;
typedef vector<Vi> Mi;
#define forUp(x,y) for(int x=0;x<(y);x++)
#define forDown(x,y) for(int x=(y)-1;x>=0;x--)
#define LET(l,r) forUp(_t,1) for(typeof(r) l=r; !_t; _t=1)
#define forEach(x,c) LET(&_s,(c)) LET(_x,_s.begin()) for(;_x!=_s.end();_x++) LET(&x,*_x)

int main() {
  int T;
  cin >> T;
  string s;
  getline(cin,s);
  forUp(t,T) {
    getline(cin,s);
    map<char,int> val;
    int n=s.size();
    int base=0;
    forUp(i,n) {
      if (!val[s[i]]) {
        val[s[i]]=(base<=1)?2-base:base+1;
        base++;
      }
    }

    if (base==1) base=2;
    LL res=0;
    forUp(i,n) {
      res=res*base+(val[s[i]]-1);
    }

    cout << "Case #" << t+1 << ": " << res << endl;
  }
  
  return 0;
}






