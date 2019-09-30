#include <stdio.h>
#include <string.h>

char S[100005];

int main(){

	scanf("%s",S);

	int len=strlen(S);

	int i;

	int pos=0;

	int ans=0;

	while(1){
		if(pos>=len){break;}
		int sum=1;
		for(i=pos;i<len;i++){
			if(S[i]=='+'){break;}
			else if(S[i]=='0'){sum=0;}
		}
		if(sum==1){ans++;}
		pos=i+1;
	}
	printf("%d\n",ans);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^