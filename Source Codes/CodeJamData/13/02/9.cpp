#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	int casenum;
	scanf("%d",&casenum);
	for(int k=0;k<casenum;k++){
		int m,n;
		int map[100][100];
		int flag[100][100];
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&map[i][j]);
				flag[i][j]=3;
			}
		}
		for(int i=0;i<m;i++){
			int max=0;
			for(int j=0;j<n;j++){
				if(max<map[i][j])max=map[i][j];
			}
			for(int j=0;j<n;j++){
				if(max>map[i][j])flag[i][j]-=1;
			}
		}
		for(int j=0;j<n;j++){
			int max=0;
			for(int i=0;i<m;i++){
				if(max<map[i][j])max=map[i][j];
			}
			for(int i=0;i<m;i++){
				if(max>map[i][j])flag[i][j]-=2;
			}
		}
		bool canit=true;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(flag[i][j]==0)canit=false;
		if(canit){
			printf("Case #%d: YES\n",k+1);
		}else{
			printf("Case #%d: NO\n",k+1);
		}
	}
	//while(1);
	return 0;
}
