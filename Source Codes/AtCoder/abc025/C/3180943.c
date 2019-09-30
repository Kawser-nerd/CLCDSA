#include <stdio.h>

int b[2][3];
int c[3][2];

int board[3][3];

int mini_max(int depth){

	int i,j;

	if(depth==9){

		int chokudai=0;

		for(i=0;i<2;i++){
			for(j=0;j<3;j++){
				if(board[i][j]==board[i+1][j]){
					chokudai+=b[i][j];
				}
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<2;j++){
				if(board[i][j]==board[i][j+1]){
					chokudai+=c[i][j];
				}
			}
		}
		return chokudai;
	}

	int max;
	int val;

	if(depth%2==0){max=-114514;}
	else{max=114514;}

	for(i=0;i<9;i++){
		if(board[i/3][i%3]==0 && depth%2==0){
			board[i/3][i%3]=1;
			val=mini_max(depth+1);
			board[i/3][i%3]=0;
			if(max<val){max=val;}
		}
		else if(board[i/3][i%3]==0 && depth%2==1){
			board[i/3][i%3]=2;
			val=mini_max(depth+1);
			board[i/3][i%3]=0;
			if(max>val){max=val;}
		}
	}
	return max;
}

int main(){

	int i,j;

	int sum=0;

	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			scanf(" %d",&b[i][j]);
			sum+=b[i][j];
		}
	}

	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			scanf(" %d",&c[i][j]);
			sum+=c[i][j];
		}
	}

	int chokudai=mini_max(0);

	printf("%d\n",chokudai);
	printf("%d\n",sum-chokudai);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:64:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %d",&b[i][j]);
    ^
./Main.c:71:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %d",&c[i][j]);
    ^