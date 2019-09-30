#include<stdio.h>

#define MAXN 100

int N;
int last[MAXN];
char word[MAXN];

int main() {
	int t,T,i,j,k,c;
	scanf("%d\n",&T);
	for(t=1;t<=T;t++) {
		scanf("%d",&N);
		for(i=0;i<N;i++) {
			scanf("%s",word);
			last[i] = -1;
			for(j=0;j<N;j++) {
				if(word[j]=='1') last[i] = j;
			}
		}
		c=0;
		for(i=0;i<N;i++) {
			for(k=i;k<N;k++) if(last[k] <= i) break;
			while(k>i) {
				c++;
				j = last[k];
				last[k] = last[k-1];
				last[k-1] = j;
				k--;
			}
		}
		printf("Case #%d: %d\n",t,c);
	}
	return 0;
}
