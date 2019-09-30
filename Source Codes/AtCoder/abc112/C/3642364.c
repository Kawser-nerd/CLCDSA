#include<stdio.h>

int N,H;
int x[100],y[100],h[100];

int ab(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d%d%d",&x[i],&y[i],&h[i]);
	
	//sort
	int r=N;
	int swapped=0;
	while(r>1 || swapped==1){
		if(r>1)r=r*10/13;
		swapped=0;
		for(int i=0;i<N-r;i++){
			if(h[i]<h[i+r]){
				int tmp=h[i];
				h[i]=h[i+r];
				h[i+r]=tmp;
				tmp=x[i];
				x[i]=x[i+r];
				x[i+r]=tmp;
				tmp=y[i];
				y[i]=y[i+r];
				y[i+r]=tmp;
				swapped=1;
			}
		}
	}
	
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			H=ab(i-x[0])+ab(j-y[0])+h[0];
			int flag=1;
			for(int k=1;k<N;k++){
				int dist=ab(i-x[k])+ab(j-y[k]);
				if((h[k]==0 && dist<H) || (h[k]>0 && dist!=H-h[k])){
					flag=0;
					break;
				}
			}
			if(flag==1){
				printf("%d %d %d\n",i,j,H);
				return 0;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<N;i++)scanf("%d%d%d",&x[i],&y[i],&h[i]);
                      ^