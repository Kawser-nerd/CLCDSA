#include <stdio.h>

main(){
	int N,M;
	scanf("%d %d",&N,&M);

	int y[100001];
	int i,j,k;
	for(i=1;i<=N;i++)
		y[i]=2*N;

	int a,b;

	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		if(b<y[a])
			y[a]=b;
	}
	for(i=1;i<N;i++){
		if(y[i]==2*N)continue;
		for(k=i+1;k<y[i];k++){
			if(y[k]<=y[i]){//ganni
				y[i]=2*N;
				break;
			}
			else{	//and
				y[k]=y[i];
				y[i]=2*N;
				break;
			}
		}
	}
	int rt=0;
	for(i=1;i<N;i++)
		if(y[i]!=2*N)
			rt++;
	printf("%d\n",rt);

	return 0;
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^