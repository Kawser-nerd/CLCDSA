#include<stdio.h>

int main(){
		int c[3][3],i,j,ab[2][3][2];
		for(i=0;i<3;i++){
				for(j=0;j<3;j++)scanf("%d",&c[i][j]);
		}
		for(i=0;i<3;i++){
				ab[0][i][0]=c[i][0]-c[i][1];
				ab[0][i][1]=c[i][1]-c[i][2];
		}
		for(i=0;i<3;i++){
				ab[1][i][0]=c[0][i]-c[1][i];
				ab[1][i][1]=c[1][i]-c[2][i];
		}
		if(ab[0][0][0]==ab[0][1][0]&&ab[0][1][0]==ab[0][2][0]&&
		ab[0][0][1]==ab[0][1][1]&&ab[0][1][1]==ab[0][2][1]&&
		ab[1][0][0]==ab[1][1][0]&&ab[1][1][0]==ab[1][2][0]&&
		ab[1][0][1]==ab[1][1][1]&&ab[1][1][1]==ab[1][2][1]){
				puts("Yes");
				return 0;
		}
		puts("No");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(j=0;j<3;j++)scanf("%d",&c[i][j]);
                     ^