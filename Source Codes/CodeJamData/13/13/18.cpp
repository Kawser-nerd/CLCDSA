#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned short us;
typedef unsigned char uc;

double fac[20];
vector<string> Name; vector<double> Freq; vector<map<int, int>* > Dist;

void doit(int *q, int n)
{
  string s="";
  for(int i=0;i<n;i++) s += ('0'+q[i]);
  Name.push_back(s);

  double freq = 1; int cur=1;
  for(int i=1;i<n;i++) if (q[i]==q[i-1]) cur++; else {freq*=fac[cur]; cur=1;}
  freq *= fac[cur];

  Freq.push_back(log(freq));

  map<int,int>* pdist = new map<int,int>;

  for(int j=0;j<(1<<n);j++)
  {
    ull t=1;
    for(int i=0;i<n;i++) if (j & (1<<i)) t *= q[i];
    (*pdist)[t]++;
  }

  Dist.push_back(pdist);
}

int main()
{
  fac[0] = 1; for(int i=1;i<20;i++) fac[i]=fac[i-1]*i;

  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    int r,n,m,k; cin >> r >> n >> m >> k;
    int q[n];

    for(int i=0;i<n;i++) q[i]=2;
    doit(q,n);

    for(;;)
    {
      int ptr = n-1;
      while(ptr >= 0 && q[ptr]==m) ptr--;
      if (ptr < 0) break;
      int x = ++q[ptr]; for(;ptr<n;ptr++) q[ptr]=x;
      doit(q,n);
    }

int M = Dist.size(); assert(M==Freq.size()); assert(M==Name.size());
fprintf(stderr, "%d cases\n",M);

    printf("Case #%d:\n",loop);

    for(int inner=0;inner < r;inner++)
    {
      vector<double> scores(M,0);
      for(int a=0;a<M;a++) scores[a] = -Freq[a];

      for(int i=0;i<k;i++)
      {
        ull x; cin >> x;
        for(int a=0;a<M;a++) if (scores[a] > -1e9) scores[a] += log((*(Dist[a]))[x]);
      }

 //     for(int a=0;a<M;a++) { cerr << Name[a] << ": " << scores[a] << endl; }
      int b=0; for(int a=0;a<M;a++) if ( scores[a] > scores[b] ) b=a;
      cout << Name[b] << endl;
//assert(scores[b] > -100);
    }
    // puts("");
  }
}
