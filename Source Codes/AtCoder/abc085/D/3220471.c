#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int *A = (int *)a;
	int *B = (int *)b;
	if (*A > *B) return -1;
	if (*A < *B) return 1;
	return 0;
}


int main(){
	int N,H,ans=0;
	scanf("%d%d",&N,&H);
	int a[N],b[N];
	for(int i=0;i<N;i++)scanf("%d%d",&a[i],&b[i]);
	qsort(a,N,sizeof(int),compare);
	qsort(b,N,sizeof(int),compare);
	if(b[0]<a[0]){
		printf("%d\n",(H+a[0]-1)/a[0]);
		return 0;
	}
	int maxb=0;
	for(;maxb<N-1;maxb++)if(b[maxb+1]<a[0])break;
	for(int i=0;i<=maxb;i++){
		ans++;
		H-=b[i];
		if(H<=0)break;
	}
	if(H>0)ans+=(H+a[0]-1)/a[0];
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&H);
  ^
./Main.c:17:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<N;i++)scanf("%d%d",&a[i],&b[i]);
                      ^