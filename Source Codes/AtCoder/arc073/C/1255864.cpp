#include<cstdio>
#include<algorithm>
#include<iostream>
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,r,l) for(int i = r; i >= l; i--)
using namespace std;

const int MAXN = 200010;

typedef pair< int, int > item;

item a[MAXN];
item fmax[MAXN],fmin[MAXN],bmax[MAXN],bmin[MAXN];

int max(int x,int y){
  return x>y? x:y;
}

int min(int x,int y){
  return x>y?y:x;
}

item getmax(item x,item y){
  return make_pair(max(x.first,y.first),max(x.second,y.second));
}

item getmin(item x,item y){
  return make_pair(min(x.first,y.first),min(x.second,y.second));
}

long long calc(item u,item d){
  long long x = u.first - d.first;
  long long y = u.second - d.second;
  return x * y;
}

int main(){
  int n,x,y;
  scanf("%d",&n);
  FOR(i,1,n){
    scanf("%d%d",&x,&y);
    a[i] = make_pair(min(x,y),max(x,y));
  }
  sort(a+1, a+n+1);
  fmax[1] = a[1]; fmin[1] = a[1];
  FOR(i,2,n){
    fmax[i] = getmax(fmax[i-1],a[i]);
    fmin[i] = getmin(fmin[i-1],a[i]);
  }
  bmax[n]= a[n]; bmin[n] = a[n];
  ROF(i,n-1,1){
    bmax[i] = getmax(bmax[i+1],a[i]);
    bmin[i] = getmin(bmin[i+1],a[i]);
  }
  long long ans = calc(fmax[n],fmin[n]);
  FOR(i,1,n-1){
    item lu = make_pair(fmax[i].second,fmax[i].first);
    item ld = make_pair(fmin[i].second,fmin[i].first);

    lu = getmax(lu,bmax[i+1]);
    ld = getmin(ld,bmin[i+1]);

    long long k = calc(lu,ld);
    if (k < ans){
      ans = k;
    }
  }
  cout << ans;
  return 0;
}