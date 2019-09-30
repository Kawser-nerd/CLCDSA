#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
int cmp(const void *a, const void *b)
{
	return *(ll *)a-*(ll *)b;
}
int main()
{
	ll N,C,K,T[100005];
	ll p_num,i,j,bus_num;
	scanf("%lld %lld %lld",&N,&C,&K);
	for (i=0;i<N;i++) {
		scanf("%lld",&T[i]);
	}
	qsort(T,N,sizeof(T[0]),cmp);
	bus_num=0;
	for (i=0;i<N;i++) {
		j=T[i]+K;
		p_num=0;
		while (T[i]<=j&&i<N) {
			p_num++;
			i++;
			if (p_num==C)
				break;
		}
		i--;
		bus_num++; 
	}
	printf("%lld\n",bus_num);
	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&N,&C,&K);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&T[i]);
   ^