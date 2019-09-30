#include <stdio.h>

char S[105][105];
char ans[105][105];
char inv[105][105];

int main() {

	int H,W;

	scanf("%d %d",&H,&W);

	int i,j,k;

	for(i=0;i<H;i++){
	scanf("%s",S[i]);
	}

	int dx[9]={-1,-1,-1,0,0,0,1,1,1};
	int dy[9]={-1,0,1,-1,0,1,-1,0,1};

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			int flag=0;
			for(k=0;k<9;k++){
				if(0<=i+dy[k]&&i+dy[k]<H&&0<=j+dx[k]&&j+dx[k]<W){
					if(S[i+dy[k]][j+dx[k]]=='.'){flag=1;}
				}
			}
			if(flag==0){ans[i][j]='#';}
			else{ans[i][j]='.';}
		}
	}

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			int flag=0;
			for(k=0;k<9;k++){
				if(0<=i+dy[k]&&i+dy[k]<H&&0<=j+dx[k]&&j+dx[k]<W){
					if(ans[i+dy[k]][j+dx[k]]=='#'){
						flag=1;
					}
				}
			}
			if(flag==1){inv[i][j]='#';}
			else{inv[i][j]='.';}
		}
	}

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(inv[i][j]!=S[i][j]){
				printf("impossible\n");
				return 0;
			}
		}
	}
	printf("possible\n");
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&H,&W);
  ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S[i]);
  ^