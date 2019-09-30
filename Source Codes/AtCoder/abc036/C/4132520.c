#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(long*)a - *(long*)b;
}

struct soba{
		long a;
		int i;
};

int main(){
		int n,i,ans[100000]={0},c=0;
		struct soba a[100000];
		scanf("%d",&n);
		for(i=0;i<n;i++){
				scanf("%ld",&a[i].a);
				a[i].i=i;
		}
		qsort(a,n,sizeof(struct soba),compare_int);
		ans[a[0].i]=0;
		for(i=1;i<n;i++){
				if(a[i].a!=a[i-1].a)c++;
				ans[a[i].i]=c;
		}
		for(i=0;i<n;i++)printf("%d\n",ans[i]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i].a);
     ^