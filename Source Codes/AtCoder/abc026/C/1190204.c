#include<stdio.h>

int main(void){
	int rs,n,blis[32][32],bn[32]={0},g[32]={0},i,j,m,gu,max,min;
	scanf("%d",&n);
	for(i = 2;i <= n;i++){
		scanf("%d",&m);
		bn[m]++;
		blis[m][(bn[m])] = i;
	}
	gu = n;
	for(i = 1;i <= n;i++){if(bn[i] == 0){g[i] = 1;gu--;}}
	while(gu){
		for(i = 1;i <= n;i++){
			if(g[i] != 0){continue;}
			for(j = 1;j <= bn[i];j++){
				rs = blis[i][j];
				if(g[rs] == 0){break;}
				if(j == 1){max = g[rs];min = g[rs];}
				else if(max < g[rs]){max = g[rs];}
				else if(g[rs] < min){min = g[rs];}
				if(j == bn[i]){g[i] = max+min+1;gu--;}
			}
		}
	}
	printf("%d\n",g[1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^