#include<stdio.h>
#include<stdlib.h>

int sortfnc(const void *a,const void *b){
    if(*(long long*)a == *(long long*)b){return 0;}
    if(*(long long*)a > *(long long*)b){return -1;}
    return 1;
}

int main(void){
	long long i,j,n,k,a[8192],sum=0,jud,dp[8192];
	long long s,f,mem;
	scanf("%lld%lld",&n,&k);
	for(i = 0;i < n;i++){scanf("%lld",&a[i]);sum+=a[i];}
	if(sum < k){printf("%d\n",n);return 0;}
	if(sum == k){printf("0\n");return 0;}
	qsort(a,n,sizeof(long long),sortfnc);
	s = 0;f = n-1;
	while(s<=f){
		jud = (s+f)/2;
		if(a[jud] >= k){s = jud+1;continue;}
		for(i = 0;i <= 8191;i++){dp[i] = 0;}
		for(i = 0;i < n;i++){
			mem = a[i];
			if(i == jud){continue;}
			if(mem >= k){continue;}
			for(j = k-1;j > 0;j--){
				if(dp[j] == 1){
					if(j+mem < k){dp[j+mem] = 1;}
				}
			}
			dp[mem] = 1;
		}
		mem = a[jud];
		for(i = k-1;i >= k-mem;i--){
			if(dp[i] == 1){s = jud+1;break;}
			if(i == k-mem){f = jud-1;break;}
		}
	}
	printf("%d\n",n-s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:21: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  if(sum < k){printf("%d\n",n);return 0;}
                     ^
./Main.c:40:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n",n-s);
         ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:14:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 0;i < n;i++){scanf("%lld",&a[i]);sum+=a[i];}
                       ^