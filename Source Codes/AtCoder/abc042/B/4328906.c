#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int n,l,i,j;
	char **text;
	char *tmp;
	scanf("%d %d",&n,&l);
	text = malloc(sizeof(char *) * n);
	tmp = malloc(sizeof(char) * l);
	for(i=0;i<n;i++){
		text[i] = malloc(sizeof(char) * l);
		scanf("%s",text[i]);
	}
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(strcmp(text[j-1],text[j])>0){
				strcpy(tmp,text[j-1]);
				strcpy(text[j-1],text[j]);
				strcpy(text[j],tmp);
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%s",text[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&l);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",text[i]);
   ^