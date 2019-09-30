#include <stdio.h>
#include <string.h>
char cc[26][26];
int cv[26][26];
int cvn[26];
int main(){
	int Ti,T;
	scanf("%d",&T);
	for(Ti=1;Ti<=T;++Ti){
		int R,C;
		memset(cc,0,26*26);
		memset(cv,0,26*26*sizeof(int));
		memset(cvn,0,26*sizeof(int));
		scanf("%d %d",&R,&C);
		for(int i=0;i<R;++i)scanf("%s",cc[i]);
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(cc[i][j]=='?')continue;
				cv[i][cvn[i]++]=j;
			}
		}
		int k=0;
		for(int i=0;i<R;++i){
			if(cvn[i]==0&&!k)continue;
			if(cvn[i]==0)for(int j=0;j<C;++j)cc[i][j]=cc[i-1][j];
			if(cvn[i]>0){
				int v=0;
				for(int j=0;j<C;++j){
					if(cc[i][j]=='?')cc[i][j]=cc[i][cv[i][v]];
					else if(v+1<cvn[i])++v;
				}
				if(!k)for(;k<i;++k)for(int j=0;j<C;++j)cc[k][j]=cc[i][j];
				k=1;
			}
		}
		printf("Case #%d:\n",Ti);
		for(int i=0;i<R;++i)printf("%s\n",cc[i]);
	}
	return 0;
}
