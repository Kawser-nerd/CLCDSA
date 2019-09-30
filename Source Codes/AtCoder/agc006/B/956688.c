#include<stdio.h>

int main(void){
	int n,x,i,m,d[262144]={0},r[262144]={0};
	scanf("%d%d",&n,&x);
	if(x == 1 || x == 2*n-1){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i = 1;i <= 2*n-1;i++){
		d[i]=1;
	}
	if(x == 2*n - 2){
		r[n-1]=x-1;d[x-1]=0;
		r[n]=x+1;d[x+1]=0;
		r[n+1]=x;d[x]=0;
		r[n+2]=x-2;d[x-2]=0;
	}
	else{
		r[n-1]=x+1;d[x+1]=0;
		r[n]=x-1;d[x-1]=0;
		r[n+1]=x;d[x]=0;
		r[n+2]=x+2;d[x+2]=0;
	}
	m = 1;
	for(i=1;i<=2*n-1;i++){
		if(r[i]){continue;}
		while(1){
			if(d[m]){r[i] = m;m++;break;}
			m++;
		}
	}
	for(i = 1;i <= 2*n-1;i++){
		printf("%d\n",r[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^