#include<stdio.h>

#define N 100001
#define max(a,b) ((a)>(b)?(a):(b))

int main(){
	int n,i,a[N],hyo[N]={0},fn=0;
	for(i=0;i<N;i++)hyo[i]=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	int ans=1;
	for(i=0;i<n;i++){
		if(hyo[a[i]]<0){
			ans=max(ans,i-fn+1);
			hyo[a[i]]=i;
		}else{
//			puts("ok");
			for(;fn<=hyo[a[i]];fn++){
				hyo[a[fn]]=-1;
			}
//			fn=hyo[a[i]]+1;
			hyo[a[i]]=i;
		}
//		for(int j=1;j<5;j++)printf("%d,",hyo[j]);
//	printf("\t%d,%d\n",i,fn);
		}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^