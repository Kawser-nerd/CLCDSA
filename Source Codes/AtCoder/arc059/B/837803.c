#include <stdio.h>
#include <stdlib.h>
#define ASC 97
int main(void){
	char s[100009];
	scanf("%s",s);
	//int dist[26][100009];
	int i,j,k;
	int memo[26];
	for(i=0;i<26;i++){
		memo[i]=-1;
		//memo[i][0]=-1;//??
		//memo[i][1]=0;// i,j??????
		//for(j=0;j<100009;j++){
			//dist[i][j][0]=-100009;//??
			//dist[i][j][1]=-100009;
		//}
	}
	int moji;
	for(i=0;s[i]!='\0';i++){
		moji=(int)s[i]-ASC;
		if(memo[moji]==-1){
			memo[moji]=i;
		}else{
			//dist[i][ (memo[moji][1]) ][0]=memo[moji]-i+3;//?????????????
			//dist[i][ (memo[moji][1]) ][1]=memo[moji][0]+1;//??dist????si
			if(i-memo[moji]<=2){
				printf("%d %d",memo[moji]+1,i+1);
				return 0;
			}else{
				memo[moji]=i;
			}
			//memo[moji][0]=i;
			//memo[moji][1]+=1;
		}
	}
	/*for(i=0;i<26;i++){
		dist[i][(memo[moji][1])][1]=memo[moji][0]+1;
	}*/
/*
	for(i=0;i<26;i++){
		int dp[100009][2];
		dp[0]=dist[i][0][0];
		if(dp[0]>0){
			printf("%d %d",dist[i][0][1],dist[i][1][1]);
		}
		for(j=1;j<memo[i][1];j++){
			if(dp[j-1]+dist[i][j][0]>dist){
				printf("%d %d",dist[i][j-1])
			}

		}	
	}*/

	printf("-1 -1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^