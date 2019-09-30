#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){return *(int*)b - *(int*)a;}

int main(void){
	int N,H,i,ans=0,m=0;
	scanf("%d%d",&N,&H);
	int a,b[N];
	for(i=0;i<N;i++){
		scanf("%d%d",&a,&b[i]);
		if(a>m) m=a;
	}
	qsort(b, N, sizeof(int), compare);
	i=0;
	while(b[i]>m && i<N && H>0){
		H-=b[i++];
		ans++;
	}
	if(H>0)	ans += (H+m-1)/m;
	
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&H);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b[i]);
   ^