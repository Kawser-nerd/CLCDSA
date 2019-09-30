#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,z;
long long p,q,qq,d,e;
int main() {
  freopen("Al.in","r",stdin);
  freopen("Al.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%I64d/%I64d",&p,&q);
    d=__gcd(p,q);
    p/=d; q/=d;
    for (qq=q, z=0; qq%2==0 && qq>1; qq/=2,z++);
    printf("Case #%d: ",t);
    if (qq==1) {
      for (e=1; e<=p; e*=2, z--);
      printf("%d\n",z+1);
    } else puts("impossible");
  }
  return 0;
}
