#include <stdio.h>
#include <string.h>
char v[10101];
int main(){
	int Ti,T;
	scanf("%d",&T);
	for(Ti=1;Ti<=T;++Ti){
		printf("Case #%d: ",Ti);
		int K,i,j;
		int r=0;
		scanf("%s %d",v,&K);
		int l = strlen(v);
		for(i=0;i<l;++i){
			if(v[i]=='-'){
				if(i+K>l)goto impossible;
				for(j=0;j<K;++j)v[i+j]=(v[i+j]=='-'?'+':'-');
				++r;
			}
		}
		printf("%d\n",r);
		continue;
impossible:	printf("IMPOSSIBLE\n");
	}
}
