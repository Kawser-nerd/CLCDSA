#include <stdio.h>


int main(void){
	int N;
	scanf("%d",&N);
	int h[N];
	int i;
	int ans = 0;
	for(i=0;i<N;i++){
		scanf("%d",&h[i]);
	}
	int flag = 0;
	int check(){
		for(i=0;i<N;i++){
			if(h[i]!=0){
				return 1;
			}
		}
		return 0;
	}   
	while(check()>0){
		i = 0;
		while(h[i]==0 && i<N){
			i++;
		}
		while(h[i]!=0 && i<N){
			h[i]--;
			i++;
		}
		ans++;
	}
	printf("%d",ans);	
	
	//???0?????????
	//0?????1????????
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&h[i]);
   ^