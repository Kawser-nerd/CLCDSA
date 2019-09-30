#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	//?????
	int h,w;
	int i,j;
	int map[60][60];
	char temp;
	char dummy;
	int sum;
	int quex[3000];
	int quey[3000];
	int queb[3000];
	
	//????????
	scanf("%d %d",&h,&w);
	scanf("%c",&dummy);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%c",&temp);
			if(temp=='.'){
				map[i][j]=1;
			}else{
				map[i][j]=0;
			}
		}
		scanf("%c",&dummy);
	}
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	sum=0;
	
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			sum=sum+map[i][j];
		}
	}
	
	for(i=0;i<3000;i++){
		queb[i]=0;
	}
	quex[0]=0;
	quey[0]=0;
	queb[0]=1;
	map[0][0]=0;
	
	i=1;//?????
	j=0;//?????
	while(queb[j]!=0){
//		printf("x=%d,y=%d,b=%d\n",quex[j],quey[j],queb[j]);
		if(quex[j]==h-1&&quey[j]==w-1){
			printf("%d",sum-queb[j]);
			return 0;
		}
		if(quex[j]!=0&&map[quex[j]-1][quey[j]]==1){
			quex[i]=quex[j]-1;
			quey[i]=quey[j];
			queb[i]=queb[j]+1;
			map[quex[j]-1][quey[j]]=0;
			i++;
		}
		if(quex[j]!=h-1&&map[quex[j]+1][quey[j]]==1){
			quex[i]=quex[j]+1;
			quey[i]=quey[j];
			queb[i]=queb[j]+1;
			map[quex[j]+1][quey[j]]=0;
			i++;
		}
		if(quey[j]!=0&&map[quex[j]][quey[j]-1]==1){
			quex[i]=quex[j];
			quey[i]=quey[j]-1;
			queb[i]=queb[j]+1;
			map[quex[j]][quey[j]-1]=0;
			i++;
		}
		if(quey[j]!=w-1&&map[quex[j]][quey[j]+1]==1){
			quex[i]=quex[j];
			quey[i]=quey[j]+1;
			queb[i]=queb[j]+1;
			map[quex[j]][quey[j]+1]=0;
			i++;
		}
		j++;
	}
	
//	printf("??????\n");
	
	//??
	
	printf("-1");
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&dummy);
  ^
./Main.c:25:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&temp);
    ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&dummy);
   ^