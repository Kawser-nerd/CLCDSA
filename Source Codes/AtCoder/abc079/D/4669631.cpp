#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int H,W;
	scanf("%d%d",&H,&W);
	int c[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)scanf("%d",&c[i][j]);
	}

	for(int k=0;k<10;k++){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<H*W;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp!=-1)ans+=c[tmp][1];
	}
	printf("%d\n",ans);
	return 0;
}