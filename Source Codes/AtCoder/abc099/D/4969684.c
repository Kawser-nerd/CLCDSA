#include<stdio.h>

int main(){
	int i,j,k,p,check=0,min=2147483647,N,C,D[30][30],color[3][30]={0};
	scanf("%d",&N);
	scanf("%d",&C);

	for(i=0;i<C;i++){
		for(j=0;j<C;j++){
			scanf("%d",&D[i][j]);
		}
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&k);
			p=(i+j)%3;
			color[p][k-1]++;
		}
	}

	for(i=0;i<C;i++){
		for(j=0;j<C;j++){
			if(i==j)continue;
			for(k=0;k<C;k++){
				if(k==i || k==j)continue;

				for(p=0;p<C;p++){
					if(p==i)continue;
					check+=color[0][p]*D[p][i];
				}
				for(p=0;p<C;p++){
					if(p==j)continue;
					check+=color[1][p]*D[p][j];
				}
				for(p=0;p<C;p++){
					if(p==k)continue;
					check+=color[2][p]*D[p][k];
				}

				if(min>check)min=check;
				check=0;
			}
		}
	}
	printf("%d",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&C);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&D[i][j]);
    ^
./Main.c:16:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&k);
    ^