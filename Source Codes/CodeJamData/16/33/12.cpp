#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

void check(int a,int b,int c,int k) {
  if(k>c) k=c;
  int cnt1[10][10]={0};
  int cnt2[10][10]={0};
  int cnt3[10][10]={0};
  for(int i=0;i<a;i++)
    for(int j=0;j<b;j++)
      for(int h=0;h<k;h++) {
        int x=(h+i+j)%c;
        cnt1[i][j]++;
        assert(cnt1[i][j]<=k);
        cnt2[i][x]++;
        assert(cnt2[i][x]<=k);
        cnt3[j][x]++;
        assert(cnt3[j][x]<=k);
      }
}

int main()
{
  for(int a=1;a<=6;a++)
    for(int b=a;b<=6;b++)
      for(int c=b;c<=6;c++)
        for(int k=1;k<=6;k++)
          check(a,b,c,k);
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int a,b,c,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    if(k>c) k=c;
    printf("%d\n",a*b*k);
    int cnt1[10][10]={0};
    int cnt2[10][10]={0};
    int cnt3[10][10]={0};
    for(int i=0;i<a;i++)
      for(int j=0;j<b;j++)
        for(int h=0;h<k;h++) {
          int x=(h+i+j)%c;
          cnt1[i][j]++;
          assert(cnt1[i][j]<=k);
          cnt2[i][x]++;
          assert(cnt2[i][x]<=k);
          cnt3[j][x]++;
          assert(cnt3[j][x]<=k);
          printf("%d %d %d\n",i+1,j+1,x%c+1);
        }
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
