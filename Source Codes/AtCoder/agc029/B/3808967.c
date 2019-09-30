#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


int compare_int(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}


int main(void)
{
	//?????
	int n;
	static int a[200010];
	static int b[200010];
	static int use[200010];

	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	llong int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;

	//????????
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		use[i]=0;
	}
	
	

//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	qsort(a, n, sizeof(int), compare_int);
	
//	for(i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}
//	pritnf("\n");
	
	j=0;
	for(i=0;i<n;i++){
		if(i==0){
			b[0]=a[0];
			temp=a[0];
			use[0]++;
		}else{
			if(a[i]!=temp){
				j++;
				b[j]=a[i];
				temp=a[i];
				use[j]++;
			}else{
				use[j]++;
			}
		}
	}
	
	n=j+1;
	
//	for(i=0;i<n;i++){
//		printf("%d?%d?\n",b[i],use[i]);
//	}
	
	i=0;
	k=0;
	l=0;
	while(i<n){
//		printf("i=%d,k=%d,l=%d\n",i,k,l);
		if(use[i]==0||flag==1){
//			printf("b[i]=%d????? use[i]=%d\n",b[i],use[i]);
//			for(j=0;j<n;j++){
//				printf("%d ",use[j]);
//			}
//			printf("\n");
			i++;
			flag=0;
		}else{
//			printf("tag0 temp=%lld,i=%d, b[i]=%d\n",temp,i,b[i]);
			temp=1;
			while(temp<b[i]+1){
//				printf("tag1\n");
				temp=temp*2;
			}
			
			k=i;
			l=n-1;
			
//			printf("tag1 temp=%lld,i=%d, b[i]=%d\n",temp,i,b[i]);
			
			if(temp==b[i]*2){
//				printf("%d,%d pair\n",b[i],b[k]);
					ans=ans+use[i]/2;
					use[i]=use[i]%2;
				flag=1;
			}else if(temp-b[i]==b[l]){
//				printf("%d,%d pair\n",b[i],b[l]);
				temp2=min(use[i],use[l]);
				ans=ans+temp2;
				use[i]=use[i]-temp2;
				use[l]=use[l]-temp2;
				flag=1;
			}else{
				while(l-k>1){
					j=(l+k)/2;
//					printf("tag2 i=%d,k=%d,l=%d j=%d b[j]=%d \n",i,k,l,j,b[j]);
					if(temp-b[i]==b[j]){
//						printf("%d,%d pair\n",b[i],b[j]);
						if(i==j){
							ans=ans+use[j]/2;
							use[j]=use[j]%2;
						}else{
							temp2=min(use[i],use[j]);
							ans=ans+temp2;
							use[i]=use[i]-temp2;
							use[j]=use[j]-temp2;
						}
						flag=1;
						break;
					}else if(temp-b[i]>b[j]){
//						printf("temp=%d,b[i]=%d,b[j]=%d k?j?\n",temp,b[i],b[j]);
						l=j;
					}else if(temp-b[i]<b[j]){
//						printf("temp=%d,b[i]=%d,b[j]=%d l?j?\n",temp,b[i],b[j]);
						k=j;
					}
				}
				if(l-k<=1){
					flag=1;
				}
			}
		}
	}
	
//	printf("??????\n");
	//??
	printf("%d",ans);
	
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^