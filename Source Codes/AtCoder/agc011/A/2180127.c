#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;

int cmp(const void*a,const void*b)
{
	return *(ll *)a-*(ll *)b; 
}
int main(void)
{
   int n,i;
   ll c,k;
   ll s[101000];
   ll count=1,l=1,start;
   scanf("%d %lld %lld",&n,&c,&k);
   for(i=0;i<n;i++)
   scanf("%lld",&s[i]);
   qsort(s,n,sizeof(s[0]),cmp); 
   start=s[0];
	for(i=1;i<n;i++)
	{
		if(s[i]<=(start+k)&&l<c)
		l++;
		else if(l==c)
		{
			count++;
			l=1;
			start=s[i];
		}
		else if(s[i]>(start+k))
		{
			count++;
			l=1;
			start=s[i];
		}
	}
	printf("%lld\n",count);
 } ./Main.c: In function ‘main’:
./Main.c:17:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %lld %lld",&n,&c,&k);
    ^
./Main.c:19:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld",&s[i]);
    ^