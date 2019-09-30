#include <algorithm>
#include <iostream>
#define N 1001

using namespace std;
typedef long double ld;

long double T[N],E[N],F[N],FI[N];
long double P[N][N];

main()
{
  ld f=1.0,fi=1.0; F[0]=FI[0]=1.0;
  for(int i=1;i<N;i++) { f*=i; fi/=i; F[i]=f; FI[i]=fi; }
  for(int i=N-1;i>=0;i--)
  {
    ld t=0; for(int j=i;j>=0;j--) if (j&1) t-=FI[j]; else t+=FI[j];
    E[i] = t;
  }
  for(int i=0;i<N;i++) for(int j=0;j<=i;j++)
  {
    P[i][j] = FI[j] * E[i-j];
  }

  T[0] = T[1] = 0;

  for(int i=2;i<N;i++)
  {
    T[i]=1.0;
    for(int j=1;j<=i;j++) T[i] += P[i][j]*T[i-j];
    T[i]/=(1-E[i]);
  }

//int q; while(cin>>q) printf("%0.6Lf\n", T[q]);
  
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    printf("Case #%d: ",loop);
    int n; cin >> n; int fp=0,x;
    for(int i=1;i<=n;i++) { cin>>x; fp+=(x!=i); }
    fprintf(stderr, "Got %d unfixed points\n", fp);
    printf("%0.6Lf\n", T[fp]);
  }
}
