//MADE BY lordmonsoon A.I.
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<iostream>
#include<utility>
#include<bitset>

using namespace std;

#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define fst first
#define snd second
#define pb push_back
#define SIZE(a) (int)(a.size())
#define LENGTH(a) (int)(a.length())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define FORD(i,n,m) for(int i=(n);i>=(m);i--)
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define ABS(a) ( (a)<0 ? -(a) : (a))
#define STRUMIEN(A,B) istringstream A(B)
#define SORT(A) sort(A.begin(),A.end())


////////////////////////////////////////////////////////////////////////////////


int A[2000000];
int PR[2000000],pr;
int P[2000000];
int find(int p)
{
      if(P[p]!=p) P[p] = find(P[p]);
      return P[p];
}

void unite(int a,int b)
{
      a = find(a);
      b = find(b);
      P[a] = b;
}


int t;
long long a,b,prime;

int main()
{
      FOR(i,2,1000) if(A[i] == 0)
      {
            int j = i + i;
            while(j<=1000001) {A[j] = 1;j+=i;}
      }
      pr = 0;
      FOR(i,2,1000001) if(A[i] == 0) PR[pr++] = i;
      
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            scanf("%I64d %I64d %I64d",&a,&b,&prime);
            for(long long i = a;i<=b;i++)
                  P[(int)(i-a)] = i - a;
            
            REP(i,pr) if(PR[i]>=prime && PR[i]<=b)
            {
                  long long start = a + (PR[i] - a%PR[i])%PR[i];
                  long long tmp = start + PR[i];
                  while(tmp<=b)
                  {
                        if(find(tmp-a) != find(start-a)) unite(tmp-a,start-a);
                        tmp += PR[i];
                  }
            }
            
            
            int ans = 0;
            for(long long i = a;i<=b;i++)
                  if(P[(int)(i-a)]==i-a) ans++;
            printf("Case #%d: %d\n",t2,ans);
      }
      return 0;
}
