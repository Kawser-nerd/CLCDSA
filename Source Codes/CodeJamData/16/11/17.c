#include <stdio.h>
#include <string.h>
#define FORN(n) for(i=0;i<n;i++)
#define FORIN(i,n) for(i=0;i<n;i++)

char*
solve(char *s, char *res){
	int i, len = strlen(s);
	int idx[2]={1024,1024};
	FORN(len){
		if(i==0){
			res[idx[0]]=s[i];
			//printf("[D] res[%d]='%c'\n",idx[0], res[idx[0]]);
			idx[0]--; idx[1]++;
		}else{
			if(res[idx[0]+1]<=s[i]){
				res[idx[0]--]=s[i];
				//printf("[D] res[%d]='%c'\n",idx[0]+1, res[idx[0]+1]);
			}else{
				res[idx[1]++]=s[i];
				//printf("[D] res[%d]='%c'\n",idx[1]-1, res[idx[1]-1]);
			}
		}
	}
	res[idx[0]]=res[idx[1]]=0;
	return &res[idx[0]+1];
}

int main(){
	int cases, T;
	char s[1024], res[2048];

	scanf("%d", &T);
	FORIN(cases,T){
		scanf("%s",s);
		char *real = solve(s, res);
		printf("Case #%d: %s\n", cases+1, real);
	}
	return 0;
}

