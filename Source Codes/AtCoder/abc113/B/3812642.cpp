#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int N;
int T,A;
int H[1100];
int main(){
  scanf("%d",&N);
  scanf("%d%d",&T,&A);
  int ans=0;
  double dif=1e9;
  repeat(i,N){
    scanf("%d",&H[i]);
    if(dif>abs(A-((double)T-0.006*H[i]))){
      dif=abs(A-((double)T-0.006*H[i]));
      ans=i+1;
    }
    //debug(dif);
  }
  printf("%d",ans);
  return 0;
}