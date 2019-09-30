#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
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

int n;
string s[533333];
int maxL;

bool word(const string& q) {
  int j = lower_bound(s,s+n,q)-s;
  return j<n && s[j]==q;
}

bool pref(string q, int k) {
  q = q.substr(0,k);
  int j = lower_bound(s,s+n,q)-s;
  return j<n && s[j].substr(0,k) == q;
}

#define L 4444
const int K = 5;
int len;
char w[L];
int dp[K+1][L];

int DP(int k,int i) {
  if(k>K) k=K;
  int &res = dp[k][i];
  if(res>=0) return res;
  res = inf;
  if(i==len) return res=0;
  string q="";
  for(int m=1;m<=maxL && i+m<=len;m++)
  {
    q+=w[i+m-1];
    if(word(q)) {
      res = min(res,DP(k+m,i+m));
      continue;
    }

    bool found=false;
    for(int j=K-k;j<m && !found;j++)
    {
      if(!pref(q,j)) break;
      char cc = q[j];
      for(char c='a';c<='z' && !found;c++)
      {
        q[j]=c;
        if(word(q))
        {
          res = min(res,DP(m-j,i+m)+1);
          found = true;
        }
        q[j]=cc;
      }
    }
    if(found) continue;

    found=false;
    for(int j=K-k;j<m && !found;j++)
    {
      if(!pref(q,j)) break;
      char cj = q[j];
      for(char c1='a';c1<='z' && !found;c1++) if(c1 != cj)
      {
        q[j] = c1;
        for(int h=j+K;h<m && !found;h++)
        {
          if(!pref(q,h)) break;
          char ch = q[h];
          for(char c2='a';c2<='z' && !found;c2++) if(c2 != ch)
          {
            q[h] = c2;
            if(word(q))
            {
              res = min(res,DP(m-h,i+m)+2);
              found=true;
            }
            q[h] = ch;
          }
        }
        q[j]=cj;
      }
    }
  }
  return res;
}

int main()
{
	FILE * dict = fopen("dict.txt","r");
  char buf[111];
  while(fscanf(dict,"%s",buf)>0) {
    s[n++]=buf;
    int cur = strlen(buf);
    MAX(maxL, cur);
  }
  fprintf(stderr,"%d\n",maxL);
  sort(s,s+n);
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	int TST=0,tst=0;
	for(scanf("%d",&TST);TST-- > 0;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    scanf("%s",w);
    len=strlen(w);
    fill(dp,-1);
    int res = DP(K,0);
    printf("%d\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
