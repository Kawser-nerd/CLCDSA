#include <stdio.h>

int group[1000];
int mg[1000][1000];
int table[1000][2];

int main(){
	int t,r,k,n,i,j,l,test,state;
	long long int euros;
	scanf("%d",&t);
	for(test=1;test<=t;test++){
		/* input */
		scanf("%d%d%d",&r,&k,&n);
		for(i=0;i<n;i++)
			scanf("%d",&group[i]);
		
		/* make table */
		for(i=0;i<n;i++){
			for(j=0,l=i;l<n;l++,j++)mg[i][j]=group[l];
			for(l=0;j<n;l++,j++)mg[i][j]=group[l];
		}
		for(i=0;i<n;i++){
			for(j=0,l=0;j<n&&l+mg[i][j]<=k;j++){
				l+=mg[i][j];
			}
			if(j==n)table[i][0]=i,table[i][1]=l;
			else{
				if(j<=n-i-1)table[i][0]=i+j,table[i][1]=l;
				else table[i][0]=j-(n-i),table[i][1]=l;
			}
		}
		/* simulation */
		state=0;
		euros=0;
		for(i=0;i<r;i++){
			euros+=(long long int) table[state][1];
			state=table[state][0];
		}
		printf("Case #%d: %lld\n",test,euros);
	}
	return 0;
}
