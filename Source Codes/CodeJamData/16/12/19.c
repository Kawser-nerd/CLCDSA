#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i,j,k,l,t,x,n,p;
	int hash[3000];
	for(i=0;i<3000;i++){
		hash[i] = 0;
	}
	scanf("%d",&t);
	for(p=1;p<=t;p++){
		scanf("%d",&n);
		
		for(i=0;i<3000;i++){
			hash[i] = 0;
		}
		
		for(i=1;i<2*n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&x);
				hash[x]++;
			}
		}
		printf("Case #%d:",p);
		for(i=0;i<3000;i++){
			if(hash[i]%2 == 1){
				printf(" %d",i);
			}
		}
		printf("\n");
	}
}
