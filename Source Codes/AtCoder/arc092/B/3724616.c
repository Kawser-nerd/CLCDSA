#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))

int compare_long(const void *a, const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}


int compare_long_inv(const void *a, const void *b)
{
	long *A = (long *)a;
	long *B = (long *)b;
	if (*B < *A) return 1;
	if (*B > *A) return -1;
	return 0;
}

int main(void)
{
	//?????
	int n;
	static llong int a[200010];
	static llong int b[200010];
	static llong int amod[200010];
	static llong int bmod[200010];
	static llong int ruijou;
	int sec1,sec2,sec3;
	int xor[30];
	
	//??????
	int i,j,k,l;
	int flag=0;
	llong int ans=0;
	int count=0;
	long long int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(i=0;i<n;i++){
		scanf("%lld",&b[i]);
	}
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<=28;i++){//????????
		if(i==0){
			ruijou=1;
		}else{
			ruijou=ruijou*2;
		}
		for(j=0;j<n;j++){
			amod[j]=a[j]%(ruijou*2);
			bmod[j]=b[j]%(ruijou*2);
		}
		
//		printf("i=%d\n",i);
//		for(j=0;j<n;j++){
//			printf("amod[%d]=%d\n",j,amod[j]);
//			printf("bmod[%d]=%d\n",j,bmod[j]);
//		}
		
		qsort(amod, n, sizeof(llong), compare_long);
		qsort(bmod, n, sizeof(llong), compare_long_inv);
		
//		for(j=0;j<n;j++){
//			printf("amod[%d]=%d\n",j,amod[j]);
//			printf("bmod[%d]=%d\n",j,bmod[j]);
//		}
		
		sec1=0;
		sec2=0;
		sec3=0;
		temp=0;
		for(j=0;j<n;j++){
			while(amod[j]+bmod[sec1]<ruijou&&sec1<n){
				sec1++;
			}
			sec2=max(sec1,sec2);
//			printf("amod[%d]=%d,bmod[%d]=%d\n",j,amod[j],sec2,bmod[sec2]);
			while(amod[j]+bmod[sec2]<2*ruijou&&sec2<n){
//				printf("amod[%d]=%d,bmod[%d]=%d\n",j,amod[j],sec2,bmod[sec2]);
				sec2++;
			}
//			printf("amod[%d]=%d,bmod[%d]=%d\n",j,amod[j],sec2,bmod[sec2]);
			
			sec3=max(sec2,sec3);
			while(amod[j]+bmod[sec3]<3*ruijou&&sec3<n){
				sec3++;
			}
//			printf("i=%d,j=%d,sec1=%d,sec2=%d,sec3=%d\n",i,j,sec1,sec2,sec3);
			temp=temp+n-sec3+sec2-sec1;
		}
		
		xor[i]=temp%2;
	}
	
	ans=0;
	for(i=28;i>=0;i--){
//		printf("xor[%d]=%d\n",i,xor[i]);
		ans=ans*2;
		ans=ans+xor[i];
	}
	
//	printf("??????\n");
	//??
	
	printf("%lld",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&b[i]);
   ^