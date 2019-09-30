#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define MP make_pair

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

int v[10][10];
int n, k;
bool solve(int sum, int x){
  if(x == n){
    return (sum == 0);
  }
  REP(i,k){
    if(solve(sum ^ v[x][i], x + 1)){
      return true;
    }
  }
  return false;
}

typedef pair<int,int> pii;

int main(){

  scanf("%d %d", &n, &k);

  REP(i,n){
    REP(j,k){
      scanf("%d", &v[i][j]);
    }
  }

  if(solve(0,0)){
    printf("Found\n");
  }else{
    printf("Nothing\n");
  }
  
  return 0;
}