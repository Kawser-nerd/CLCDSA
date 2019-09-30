#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// Let's Fight!

typedef long double ld;

const int MAXN = 524288;
const int INF = 1029384756;
const ld LINF = 1E20;
const ld TOLEPS = 1E-14;
const ld SEREPS = 1E-16;

int N;
ld F;
string s;

int onesum[MAXN];
ld arr[MAXN];
ld brr[MAXN];
int ord[MAXN], lord[MAXN];

ld BIT[MAXN];

bool cmp(int a, int b)
{
  return arr[a] > arr[b];
}

void input()
{
  cin>>N>>F>>s;
}

void init()
{
  onesum[0] = 0;
  for(int i=1; i<=N; i++)
    onesum[i] = onesum[i-1] + (s[i-1] == '1');
  for(int i=0; i<=N; i++)
    arr[i] = onesum[i] - i * F;
  for(int i=0; i<=N; i++)
    lord[i] = i;
  sort(lord, lord+N+1, cmp);
  for(int i=0; i<=N; i++)
    ord[lord[i]] = i;
}

void initBIT()
{
  for(int i=0; i<MAXN; i++)
    BIT[i] = LINF;
}

void addBIT(int pos, ld val)
{
  pos++;
  while(pos < MAXN)
  {
    BIT[pos] = min(BIT[pos], val);
    pos += pos&(-pos);
  }
}

ld qryBIT(int pos)
{
  ld ans = LINF;
  pos++;
  while(pos)
  {
    ans = min(ans, BIT[pos]);
    pos -= pos&(-pos);
  }
  return ans;
}

int realcalc(ld k, bool tol)
{
  initBIT();
  int ans = INF;
  for(int i=N; i>=0; i--)
  {
    int o = ord[i];
    ld val = qryBIT(o);
    val += -brr[i] + k * i;

    bool ok = false;
    if(tol) ok = (val < TOLEPS);
    else ok = (val < 0);
    if(ok) ans = i;
    addBIT(o, brr[i] - k * i);
  }

  return ans;
}

int calc(ld k, bool tol=false)
{
  for(int i=0; i<=N; i++)
    brr[i] = arr[i];
  int ans = realcalc(k, tol);

  for(int i=0; i<=N; i++)
    ord[i] = N - ord[i];

  for(int i=0; i<=N; i++)
    brr[i] = -arr[i];
  ans = min(ans, realcalc(k, tol));

  for(int i=0; i<=N; i++)
    ord[i] = N - ord[i];

  // cout<<k<<" ANS "<<ans<<endl;

  return ans;
}

int main(int argc, char** argv)
{
  IOS;
  int T;
  cin>>T;
  int nT = atoi(argv[1]);
  for(int i=1; i<=nT; i++)
    input();

  init();

  // for(int i=0; i<=N; i++) cout<<arr[i]<<" ";cout<<endl;
  // for(int i=0; i<=N; i++) cout<<ord[i]<<" ";cout<<endl;

  ld lb = 0, rb = 2;
  while(rb - lb > SEREPS)
  {
    ld mb = (rb + lb) / 2;
    int res = calc(mb);
    if(res < INF)
      rb = mb;
    else
      lb = mb;
  }

  ld bb = (lb + rb) / 2;

  int ans = calc(bb, true);

  // cout<<"DIFF "<<bb<<endl;

  cout<<"Case #"<<nT<<": "<<ans<<endl;

	return 0;
}
