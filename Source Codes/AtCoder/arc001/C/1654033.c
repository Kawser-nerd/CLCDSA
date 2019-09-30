#include<stdio.h>
#include<stdlib.h>
int Y[]={0,1,1,1,0,-1,-1,-1};
int X[]={1,1,0,-1,-1,-1,0,1};
int d[10][10],q[10][10];
	int f(int s,int c){
	int x,y,i,j,k,l;
	if(c==8)return 1;
	for(i=s;i<64;i++){
		y=i/8+1;
		x=i%8+1;
		if(d[y][x]-1)continue;
		for(k=0;k<4;k++){
			for(l=0;d[y+Y[k]*l][x+X[k]*l];l++)d[y+Y[k]*l][x+X[k]*l]++;
		}
		q[y][x]=1;
		if(f(i+1,c+1))return 1;
		for(k=0;k<4;k++){
			for(l=0;d[y+Y[k]*l][x+X[k]*l];l++)d[y+Y[k]*l][x+X[k]*l]--;
		}
		q[y][x]=0;
	}
	return 0;
}
int main(){
	int i,j,k,l,s=1;
	char c;
	for(i=1;i<9;i++){
		for(j=1;j<9;j++)d[i][j]=1;
	}
	for(i=1;i<9;i++){
		for(j=1;j<9;j++){
			scanf(" %c",&c);
			if(c=='Q'){
				q[i][j]=1;
				if(d[i][j]-1)s=0;
				for(k=0;k<8;k++){
					for(l=0;d[i+Y[k]*l][j+X[k]*l];l++)d[i+Y[k]*l][j+X[k]*l]=2;
				}
			}
		}
	}
	if(s&&f(0,3)){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++)printf("%c",q[i+1][j+1]?'Q':'.');
			printf("\n");
		}
	}
	else printf("No Answer\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c",&c);
    ^