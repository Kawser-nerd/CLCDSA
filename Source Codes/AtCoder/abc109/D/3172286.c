#include <stdio.h>

int a[505][505];
int move[300000][4];

int main(){

	int H,W;

	scanf("%d %d",&H,&W);

	int i,j;

	for(i=1;i<=H;i++){
		for(j=1;j<=W;j++){
			scanf(" %d",&a[i][j]);
		}
	}

	int N=0;

	for(i=H;i>=2;i--){
		int sum1=0;
		for(j=1;j<=W;j++){
			sum1+=a[i][j];
		}
		if(sum1%2==1){
			int flag=0;
			for(j=1;j<=W;j++){
				if(flag==0&&a[i][j]%2==1){
					a[i][j]--;
					a[i-1][j]++;
					move[N][0]=i;
					move[N][1]=j;
					move[N][2]=i-1;
					move[N][3]=j;
					N++;
					flag=1;
				}
				else if(a[i][j]%2==1 && j<W){
					a[i][j]--;
					a[i][j+1]++;
					move[N][0]=i;
					move[N][1]=j;
					move[N][2]=i;
					move[N][3]=j+1;
					N++;
				}
			}
		}
		else{
			for(j=1;j<W;j++){
				if(a[i][j]%2==1){
					a[i][j]--;
					a[i][j+1]++;
					move[N][0]=i;
					move[N][1]=j;
					move[N][2]=i;
					move[N][3]=j+1;
					N++;
				}
			}
		}
	}

	for(j=1;j<W;j++){
		if(a[1][j]%2==1){
			a[1][j]--;
			a[1][j+1]++;
			move[N][0]=1;
			move[N][1]=j;
			move[N][2]=1;
			move[N][3]=j+1;
			N++;
		}
	}
	printf("%d\n",N);
	for(i=0;i<N;i++){
	printf("%d %d %d %d\n",move[i][0],move[i][1],move[i][2],move[i][3]);
	}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&H,&W);
  ^
./Main.c:16:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %d",&a[i][j]);
    ^