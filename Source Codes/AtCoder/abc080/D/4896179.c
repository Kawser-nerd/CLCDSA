#include <stdio.h>

int main(void){
	int N,C,i,j;
	scanf("%d%d",&N,&C);
	int s[N],t[N],c[N];
	for(i=0;i<N;i++)scanf("%d%d%d",&s[i],&t[i],&c[i]);
	int time[200002];
	int ans=0,S[200002]={0};
	for(i=1;i<=C;i++){
		for(j=0;j<200002;j++)time[j]=0;
		for(j=0;j<N;j++){
			if(c[j]==i){
				time[s[j]*2-1]++;
				time[t[j]*2]--;
			}
		}
		for(j=1;j<200002;j++)time[j]+=time[j-1];
		for(j=0;j<200002;j++)if(time[j]>0)S[j]++;
	}
	for(i=0;i<200002;i++)ans = ans<S[i]?S[i]:ans;
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&C);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++)scanf("%d%d%d",&s[i],&t[i],&c[i]);
                  ^