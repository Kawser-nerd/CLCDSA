#include <stdio.h>
#include <string.h>
int main(void){
	char S[301];
	int k,i,idx=0,flag,j;
	scanf("%s %d",S,&k);
	int l=strlen(S);
	char kouho[301][301],a[301];
	for(i=0;i<=l-k;i++){
		flag=0;
		for(j=0;j<k;j++)a[j]=S[i+j];
		a[j]='\0';
		for(j=0;j<idx;j++){
			if(strcmp(kouho[j],a)==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(kouho[idx],a);
			idx++;
		}
	}
	printf("%d\n",idx);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %d",S,&k);
  ^