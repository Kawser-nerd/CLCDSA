#include <cmath>
#include <map>
#include <iostream>

using namespace std;

static int a[2];

int doit(long n) {a[0]=2; a[1]=6; int i; for(i=2;i<=n+1;i++) {long j=(i%2), k=(i+1)%2; a[j]=(6*a[k]-4*a[j])%1000+1000; a[j]%=1000;} return a[(i%2)];} 

int main()
{
long N,m;

scanf("%d",&N);

for(long loop=1;loop<=N;loop++)
{
  scanf("%d",&m);
  if (m>500) m = 100+(m%100);
  printf("Case #%d: %03d\n",loop,(doit(m)+999)%1000);
}

}
