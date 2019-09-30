#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
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
#define pii pair<int,int>

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

int main(){

  char s[100010];
  scanf("%s", s);

  int len = strlen(s);
  int res = 0;
  bool b = true;
  REP(i,len){
    if(s[i] == '+'){
      if(b){
        res++;
      }
      b = true;
    }else if(s[i] == '*'){
      continue;
    }else{
      if(s[i] == '0'){
        b = false;
      }
    }
  }

  if(b){
    res++;
  }

  printf("%d\n", res);

  return 0;
}