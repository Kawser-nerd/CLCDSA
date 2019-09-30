#include<stdio.h>

int ab(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	int H,W,D;
	scanf("%d%d%d",&H,&W,&D);
	int pos[H*W+1];
	int d[H*W+1];
	
	for(int i=0;i<H*W;i++){
		int A;
		scanf("%d",&A);
		pos[A]=i;
	}
	for(int i=1;i<=H*W;i++)d[i]=0;
	for(int i=1;i<=H*W-D;i++){
		int x1=pos[i]/W,y1=pos[i]%W;
		int x2=pos[i+D]/W,y2=pos[i+D]%W;
		d[i+D]=d[i]+ab(x1-x2)+ab(y1-y2);
	}
	
	int Q;
	scanf("%d",&Q);
	int L[Q],R[Q],ans[Q];
	for(int i=0;i<Q;i++){
		scanf("%d%d",&L[i],&R[i]);
		ans[i]=d[R[i]]-d[L[i]];
	}
	for(int i=0;i<Q;i++)printf("%d\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&H,&W,&D);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A);
   ^
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&Q);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&L[i],&R[i]);
   ^