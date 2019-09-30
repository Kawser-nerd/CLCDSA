#include <stdio.h>
#include <math.h>
#define Lim 1000000007

int main( void ){
	int H,W,K;
	int pat[63][10]={0};
	int i,j,b,flg,cnt=0;
	unsigned long count[10]={0,1,0,0,0,0,0,0,0,0},count2[10];
	
	scanf("%d%d%d",&H,&W,&K);
	for(i=0;i<pow(2,W-1);i++){
		b=i;
		flg=1;
		for(j=1;j<9;j++){
			pat[cnt][j]=b%2;
			b=b/2;
			if( pat[cnt][j]==1 && pat[cnt][j-1]==1 ){
				flg=0;
				j=9;
			}
		}
		if( flg==1 ) cnt++;
	}

	for(i=0;i<H;i++){
		for(j=0;j<10;j++) count2[j]=0;
		for(j=0;j<cnt;j++){
			for(b=1;b<9;b++){
				if( pat[j][b]==1 ) count2[b+1]+=count[b];
				else if( pat[j][b-1]==1 ) count2[b-1]+=count[b];
				else count2[b]+=count[b];
				count2[b]=count2[b]%Lim;
			}
		}
		for(j=0;j<10;j++) count[j]=count2[j];
	}
	printf("%ld\n",count[K]%Lim);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&H,&W,&K);
  ^