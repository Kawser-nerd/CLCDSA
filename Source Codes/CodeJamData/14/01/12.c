#include <stdio.h>

long long a[20],i,j,k,l,m,n,b[10],t,tt;

int main()
{

scanf("%lld",&t);

for(tt=1;tt<=t;tt++) {

printf("Case #%lld: ",tt);


for(i=1;i<=16;i++) a[i] = 1;

scanf("%lld",&k);

for(i=1;i<=4;i++)
 for(j=1;j<=4;j++) {
   scanf("%lld",&l);
   if(i != k) a[l] = 0;
 }  

scanf("%lld",&k);

for(i=1;i<=4;i++)
 for(j=1;j<=4;j++) {
   scanf("%lld",&l);
   if(i != k) a[l] = 0;
 }  


k = 0;

for(i=1;i<=16;i++) {
 if(a[i] && k) {printf("Bad magician!\n"); k = 20; break;}
 if(a[i]) k = i;
 }

if(k == 0) printf("Volunteer cheated!\n");
if(k>0 && k<=16) printf("%lld\n",k);


}

return 0;
}