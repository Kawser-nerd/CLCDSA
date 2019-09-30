#include<stdio.h>

#define N 100001

int han(int n){
	int i,f=0;
	for(i=2;i*i<=n;i++){
		if(n%i==0){
			f=1;
			break;
		}
	}
	if(f==1)return 0;
	//if(han((n+1)/2))return 0;
	return 1;
}

int main(){
	int q,i,j,su[N]={0},lr[N][2];
	for(i=3;i<N;i++){
		su[i]=su[i-1];
		//printf("%d\n",han(i));
		if(han(i)==1&&han((i+1)/2)==1)su[i]++;
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)scanf("%d%d",&lr[i][0],&lr[i][1]);
	for(i=0;i<q;i++)printf("%d\n",su[lr[i][1]]-su[lr[i][0]-1]);
	//for(i=0;i<10;i++)printf("%d\n",su[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:26:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<q;i++)scanf("%d%d",&lr[i][0],&lr[i][1]);
                  ^