#include <stdio.h>

int a[100005];
int b[100005];

int main(){

	int N,M;

	scanf("%d %d",&N,&M);

	int X,Y;

	scanf("%d %d",&X,&Y);

	int i;

	for(i=0;i<N;i++){
	scanf(" %d",&a[i]);
	}
	for(i=0;i<M;i++){
	scanf(" %d",&b[i]);
	}

	int time=0;
	int next_A=0;
	int next_B=0;
	int ans=0;

	while(1){
		while(1){
			if(next_A==N){break;}
			if(a[next_A]>=time){break;}
			next_A++;
		}

		if(next_A==N){break;}

		time=a[next_A]+X;

		while(1){
			if(next_B==M){break;}
			if(b[next_B]>=time){break;}
			next_B++;
		}
		if(next_B==M){break;}

		time=b[next_B]+Y;

		ans++;
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&X,&Y);
  ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %d",&a[i]);
  ^
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %d",&b[i]);
  ^