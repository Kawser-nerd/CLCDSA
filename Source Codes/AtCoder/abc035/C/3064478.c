#include<stdio.h>

int main(){
		int n,q;
		scanf("%d%d",&n,&q);
		int osero[n];
		int i,j,lr[q][2];
		int tmp=q;
		if(n>q)tmp=n;
		for(i=0;i<tmp;i++){
				if(i<n)osero[i]=0;
				if(i<q)scanf("%d %d",&lr[i][0],&lr[i][1]);
		}
		for(i=0;i<q;i++){
				osero[lr[i][0]-1]++;
				osero[lr[i][1]]--;
		}
		for(i=0;i<n;i++){
				if(i>0)osero[i]+=osero[i-1];
				if(osero[i]%2==0)putchar('0');
				else putchar('1');
		}
		puts("");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:12:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     if(i<q)scanf("%d %d",&lr[i][0],&lr[i][1]);
            ^