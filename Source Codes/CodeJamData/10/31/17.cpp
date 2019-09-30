
//Written by Alex Hamed Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int maxn=1100;
int n;
int a[maxn];
int b[maxn];

void clear() {
}

void solve(int cnum) {
  cin>>n;
  FOR (i,n) cin>>a[i]>>b[i];
  int cnt=0;
  
  FOR (i,n)
	FOR (j,n)
	if (a[i]<a[j] && b[i]>b[j])
	  cnt++;

  cout<<"Case #"<<cnum<<": "<<cnt<<endl;
  cerr<<"Case #"<<cnum<<": "<<cnt<<endl;
}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
