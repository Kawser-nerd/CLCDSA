#include <stdio.h>
#include <string.h>

#define SIZE 501
char welcome[]="welcome to code jam";
int cache[SIZE][SIZE];

int match(int i,int j, char* str){
	//fprintf(stderr,"i=%d j=%d\n",i,j);
	if (welcome[j]==0) return 1;
	else if (str[i]==0) return 0;
	else if (cache[i][j]!=-1) return cache[i][j];
	else{
		int ret=0;
		if (str[i]==welcome[j]) ret=(ret+match(i+1,j+1, str))%10000;
		ret=(ret+match(i+1,j, str))%10000;
		return cache[i][j]=ret;
	}
}

char buffer[SIZE];
int main(){
	int N,cas;
	scanf("%d", &N);
	gets(buffer);
	for(cas=1;cas<=N;cas++){
		int i,answer=0;
		gets(buffer);
		memset(cache,-1,sizeof(cache));
		//for(i=0;buffer[i];i++) answer=(answer+match(i,0,buffer))%10000;
		answer=match(0,0,buffer);
		printf("Case #%d: %04d\n", cas, answer);
	}
}
