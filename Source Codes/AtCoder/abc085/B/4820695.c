#include<stdio.h>
int main(void){
	int kazu,siz[100]={0},i,j,buff,G=0;
	scanf("%d",&kazu);
	for(i=0;i<kazu;i++){
		scanf("%d",&siz[i]);
	}
	for(i=0;i<kazu;i++){
		for(j=i;j<kazu;j++){
			if(siz[i]<siz[j]){
				buff=siz[i];
				siz[i]=siz[j];
				siz[j]=buff;
			}
		}
	}
	for(i=0;i<kazu;i++){
		if(siz[i]!=siz[i+1]){
			G++;
		}
	}
	printf("%d\n",G);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&kazu);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&siz[i]);
   ^