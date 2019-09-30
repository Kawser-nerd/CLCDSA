#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **pass;

void init(){
	pass = malloc(sizeof(char*) * 300);
	for(int i = 0; i < 300; i++)
		pass[i] = NULL;
}

int cmp(char *in, int len){
	int i;
	for(i = 0; i < 300; i++){
		if(pass[i] == NULL)break;
		/*
		for(int j = 0; j < len; j++)
			putchar(pass[i][j]);
		putchar(':');
		for(int j = 0; j < len; j++)
			putchar(in[j]);
		putchar('\n');
		*/
		if(!strncmp(pass[i], in, len)){
			/*
			for(int j = 0; j < len; j++)
				putchar(in[j]);
			printf(" reject\n");
			*/
			return 0;
		}
	}
	pass[i] = in;
	/*
	printf("add[");
	for(int j = 0; j < len; j++)
		putchar(pass[i][j]);
	printf("]\n");
	*/
	return 1;
}

int main(void){
	init();
	char in[305];
	scanf("%s", in);
	int k;
	scanf("%d", &k);
	int count = 0;
	int len = strlen(in);
	if(len < k){
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < len - k + 1; i++){
		if(cmp(in + i, k))count++;
	}
	printf("%d\n", count);
	/*
	for(int i = 0; i < count; i++){
		for(int j = 0; j < k; j++)
			putchar(pass[i][j]);
		putchar('\n');
	}
	*/
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", in);
  ^
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^