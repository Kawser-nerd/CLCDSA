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
int t,n,k;
int P[200];

int czapa = 1048576;
int Q[2097152];

void add(int i)
{
      i+=czapa;
      Q[i]++;
      while(i>1)
      {
            i>>=1;
            Q[i]++;
      }
}

void erase(int i)
{
      i+=czapa;
      Q[i]--;
      while(i>1)
      {
            i>>=1;
            Q[i]--;
      }
}

int find(int cnt)
{
      int i = 1;
      while(i < czapa)
      {
            i+=i;
            if(cnt>Q[i]) {cnt-=Q[i];i++;}
      }
      return i - czapa;
}

int count(int i)
{
      i += czapa;
      int cnt = 0;
      while(i>1)
      {
            if(!(i&1)) cnt+=Q[i+1];
            i>>=1;
      }
      return cnt;
}

int count2(int i)
{
      i += czapa;
      int cnt = 0;
      while(i>1)
      {
            if((i&1)) cnt+=Q[i-1];
            i>>=1;
      }
      return cnt;
}

int main()
{
      scanf("%d",&t);
      FOR(t2,1,t)
      {
            scanf("%d",&k);
            scanf("%d",&n);
            REP(i,n) scanf("%d",P+i);
            REP(i,k) A[i] = 0;
            REP(i,czapa+czapa) Q[i] = 0;
            REP(i,k) add(i);            
            A[0] = 1;
            erase(0);
            int ind = 0;
            FOR(i,2,k)
            {
                  int pp = count(ind);
                  
                  if(i<=pp)
                  {
                        ind = find(count2(ind) + i);
                        A[ind] = i;
                        erase(ind);
                  }
                  else
                  {
                        int cnt = i - pp;
//                        printf("%d\n",cnt);
                        cnt %= Q[1];if(cnt == 0) cnt = Q[1];
                        ind = find(cnt);
                        
                        A[ind] = i;
                        erase(ind);
                  }
//                  printf("%d %d\n",i,ind);
            }
            printf("Case #%d:",t2);
            REP(i,n) printf(" %d",A[P[i]-1]);
            printf("\n");
//            return 0;
      }
      return 0;
}
