// Jakub Radoszewski

//#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<numeric>
#include<cassert>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

int los(int m)
{
  return (int)((double)m*(rand()/(RAND_MAX+1.0)));
}

char st[10000];
string s;
int ile[300];
int wyn[10];

void tc()
{
  scanf("%s",st);
  s=string(st);
  memset(ile,0,sizeof(ile));
  REP(i,SIZE(s)) ++ile[int(s[i])];
  memset(wyn,0,sizeof(wyn));
  wyn[0]=ile[char('Z')];
  wyn[2]=ile[char('W')];
  wyn[4]=ile[char('U')];
  wyn[6]=ile[char('X')];
  wyn[8]=ile[char('G')];
  wyn[1]=ile[char('O')]-wyn[0]-wyn[2]-wyn[4];
  wyn[3]=ile[char('R')]-wyn[0]-wyn[4];
  wyn[5]=ile[char('F')]-wyn[4];
  wyn[7]=ile[char('S')]-wyn[6];
  wyn[9]=ile[char('I')]-wyn[5]-wyn[6]-wyn[8];
  REP(i,10) REP(j,wyn[i]) putchar(char('0'+i));
  puts("");
}

int main()
{
  int ILE;
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d:\n",iii);
    tc();
  }
  return 0;
}
