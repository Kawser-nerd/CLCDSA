#include<stdio.h>

int main(){
	char s[1001];scanf("%s",s);
	int nwes[4]={0},i=0;
	while(s[i]!=0){
		if(s[i]=='N')nwes[0]=1;
		if(s[i]=='W')nwes[1]=1;
		if(s[i]=='S')nwes[2]=1;
		if(s[i]=='E')nwes[3]=1;
		i++;
	}
	if(nwes[0]==1&&nwes[1]==1&&
	nwes[2]==1&&nwes[3]==1){
		puts("Yes");
		return 0;
	}else if(nwes[0]==1&&nwes[1]==0&&
	nwes[2]==1&&nwes[3]==0){
		puts("Yes");
		return 0;
	}else if(nwes[0]==0&&nwes[1]==1&&
	nwes[2]==0&&nwes[3]==1){
		puts("Yes");
		return 0;
	}else{
		puts("No");
		return 0;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  char s[1001];scanf("%s",s);
               ^