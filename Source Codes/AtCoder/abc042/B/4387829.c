#include<stdio.h>
#include<string.h>
char s[110][11000];
char temp[11000];
int main(){
	int n,l;
	while(~scanf("%d%d",&n,&l)){
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){
				if(strcmp(s[j],s[j+1])>0){
					memset(temp,'\0',sizeof(temp));
					strcpy(temp,s[j]);
					strcpy(s[j],s[j+1]);
					strcpy(s[j+1],temp);
				}
			}
		}
		
		for(int i=0;i<n;i++)
			printf("%s",s[i]);
		printf("\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",s[i]);
    ^