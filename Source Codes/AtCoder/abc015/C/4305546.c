#include<stdio.h>
#include<stdbool.h>
int N,K,T[5][5];

bool next(int num,int value){
	if(num==N){
		if(value==0) return true;
		else return false;
	}
	for(int j=0;j<K;j++){
		if(next(num+1,value^T[num][j])) return true;
	}
	return false;
}

int main(){
	int i,j;
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		for(j=0;j<K;j++) scanf("%d",&T[i][j]);
	}
	
	if(next(0,0)) printf("Found");
	else printf("Nothing");
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(j=0;j<K;j++) scanf("%d",&T[i][j]);
                    ^