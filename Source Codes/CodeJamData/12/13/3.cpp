#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 64;

struct T{
  int a, b;
  int i, j;
  int t;
  
  bool operator <(const T& x) const{
    return a*x.b < x.a*b || a*x.b == x.a*b && t>x.t;
  }
};

int s[MAXN], p[MAXN];
int f[MAXN];
int r[MAXN];
T q[MAXN*MAXN];
char s1[2];
int n;

void merge(int a, int b, int x){
  if(b != f[b]){
    x ^= r[b];
    b = f[b];
  }
  if(a != f[a]){
    x ^= r[a];
    a = f[a];
  }
  if(r[b] != 2)
    swap(a, b);
  int i;
  r[b] = 0;
  for(i = 0; i < n; i++){
    if(f[i] == b){
      f[i] = a;
      r[i] ^= x;
    }
  }
}

int get(int i){
  if(i == f[i])
    return r[i];
  if(r[f[i]] == 2)
    return 2;
  return r[f[i]]^r[i];
}

int get1(int i){
  if(i == f[i])
    return 0;
  return r[i];
}

void check(int i, int a, int b){
  int j;
  for(j = 0; j < n; j++){
    if(i != j && abs(p[i]*b+a*s[i]-p[j]*b-a*s[j]) < 5*b)
      break;
  }
  if(j == n){
    if(f[i] != i){
      f[i] = i;
      r[i] = 2;
    }
    else{
      for(j = 0; j < n; j++)
        if(i != j && f[j] == i)
          break;
      if(j == n){
        r[i] = 2;
        return;
      }
      for(int k = 0; k < n; k++)
        if(k != i && k != j && f[k] == i){
          f[k] = j;
          r[k] ^= r[j];
        }
      if(r[i] == 2)
        r[j] = 2;
      else
        r[j] ^= r[i];
      r[i] = 2;
      f[i] = i;
      f[j] = j;
    }
  }
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int _;
  scanf("%d", &_);
  for(int i0 = 1; i0 <= _; i0++){
    printf("Case #%d: ", i0);
    int m;
    int i, j, k, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
      scanf("%s%d%d", s1, &s[i], &p[i]);
      f[i] = i;
      r[i] = s1[0]!='L';
    }
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++)
        if(i != j && abs(p[i]-p[j]) < 5)
          break;
      if(j == n)
        r[i] = 2;
    }
    m = 0;
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
        if(s[i] > s[j]){
          if(p[i] <= p[j]-5){
            T t;
            t.a = p[j]-5-p[i];
            t.b = s[i]-s[j];
            t.i = i;
            t.j = j;
            t.t = 0;
            q[m++] = t;
          }
          if(p[i] < p[j]+5){
            T t;
            t.a = p[j]+5-p[i];
            t.b = s[i]-s[j];
            t.i = i;
            t.j = j;
            t.t = 1;
            q[m++] = t;
          }
        }
    sort(q, q+m);
    for(k = 0; k < m; k++){
      i = q[k].i;
      j = q[k].j;
      if(q[k].t == 0){
        if(f[i] != f[j]){
          if(get(i) == 2 || get(j) == 2 || get(i) != get(j))
            merge(i, j, 1);
          else
            break;
        }
        else{
          if(get1(i) == get1(j))
            break;
        }
      }
      else{
        check(i, q[k].a, q[k].b);
        check(j, q[k].a, q[k].b);
      }
    }
    if(k < m){
      printf("%lf\n", (double)q[k].a/q[k].b);
    }
    else{
      printf("Possible\n");
    }
  }
  return 0;
}
