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

int p,q;
Vb Q;
Mi M;

int coins(int a, int b) {
  if (a>=b) return 0;
  int &m=M[a][b];
  if (m==-1) {
    bool found=false;
    m=1000000000;
    for (int i=a; i<=b; i++)
      if (Q[i]) {
        found=true;
        m=min(m,coins(a,i-1)+coins(i+1,b)+b-a);
      }
    if (!found) m=0;
  }
  return m;
}

int main() {
  int T; cin >> T;
  forUp(t,T) {
    cin >> p >> q;
    M=Mi(p+1,Vi(p+1,-1));
    Q=Vb(p+1);
    forUp(i,q) {
      int j;
      cin >> j;
      Q[j]=true;
    }

    printf("Case #%d: %d\n",t+1,coins(1,p)); 
  }
  return 0;
}






