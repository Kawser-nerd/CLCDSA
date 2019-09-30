#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b){
    return *(long*)b - *(long*)a;
}

long gcd(long a,long b){
		if(a%b==0)return b;
		return gcd(b,a%b);
}

int main(){
		int n,i;
		long a[100000],k,b,max=0;
		scanf("%d%ld",&n,&k);
		scanf("%ld",&a[0]);b=a[0];
		for(i=1;i<n;i++){
				scanf("%ld",&a[i]);
				b=gcd(b,a[i]);
		}
		qsort(a,n,sizeof(long),compare_int);
		for(i=0;a[i]>=k;i++){
				if((a[i]-k)%b==0){
						puts("POSSIBLE");
						return 0;
				}
		}
		puts("IMPOSSIBLE");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%ld",&n,&k);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a[0]);b=a[0];
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^