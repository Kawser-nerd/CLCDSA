#include<stdio.h>
#include<stdlib.h>

int connect[100000];

int topreturn(int n){
	while(connect[n]!=n){
		n=connect[n];
	}
	return n;
}

int main(void){
	int n,m,x,y,i,tmp;
	int p[100000];
	int j;

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
		connect[i]=i;
	}

	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		x=topreturn(x-1);
		y=topreturn(y-1);
		if(x>y){tmp=x; x=y; y=tmp;}
		connect[y]=connect[x];
	}

	tmp=0;
	for(i=0;i<n;i++){
		if(topreturn(i)==topreturn(p[i]-1)){
			tmp++;
		}
	}
	printf("%d\n",tmp);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p[i]);
   ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x,&y);
   ^