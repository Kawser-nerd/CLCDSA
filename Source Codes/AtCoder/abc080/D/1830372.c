#include<stdio.h>
int main(){
int n,C;
int s[100000];
int t[100000];
int c[100000];

scanf("%d %d",&n,&C);
for(int i=0;i<n;i++){
	scanf("%d %d %d",&s[i],&t[i],&c[i]);
}
int m=100001;
int T[31][100001];
for(int i=0;i<C+1;i++){
	for(int j=0;j<m;j++){
		T[i][j]=0;
	}
}
for(int i=0;i<n;i++){
	for(int j=s[i];j<=t[i];j++){
		if(T[c[i]][j]==0){
			T[c[i]][j]=1;
		}
	}
}
int x=0;
for(int i=0;i<m;i++){
	int y=0;
	for(int j=0;j<C+1;j++){
		y=y+T[j][i];
	}
	if(x<y){
		x=y;
	}
}
printf("%d\n",x);
} ./Main.c: In function ‘main’:
./Main.c:8:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d",&n,&C);
 ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&s[i],&t[i],&c[i]);
  ^