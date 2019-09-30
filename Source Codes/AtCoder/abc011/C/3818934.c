#include<stdio.h>
short min(short a, short b, short c);

short MAX=16384;
short N, NG[3], i;
short n[301];
int main(){
	scanf("%hd", &N);
	scanf("%hd%hd%hd", &NG[0], &NG[1], &NG[2]);
	n[NG[0]]=MAX;
	n[NG[1]]=MAX;
	n[NG[2]]=MAX;
	if(n[1]!=MAX){n[1]=1;}
	if(n[2]!=MAX){n[2]=1;}
	for(i=3; i<=N; ++i){
		if(n[i]!=MAX){n[i]=min(n[i-3], n[i-2], n[i-1])+1;}
	}
	if(n[N]>100){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}

short min(short a, short b, short c){
	return (b>c?(a>c?c:a):(a>b?b:a));
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd", &N);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd%hd%hd", &NG[0], &NG[1], &NG[2]);
  ^