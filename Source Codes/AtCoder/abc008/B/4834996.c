#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int main(){
	int N=0;
	scanf("%d",&N);
	char *namelist[MAX];
	int score[MAX];
	for(int i = 0;i < N;i++){
		score[i] = 0;
	}
	for(int i = 0;i < MAX;i++){
		namelist[i] = (char*)malloc(sizeof(char*) * 1);

	}
	char str[256];

	for(int i = 0;i < N;i++){
		scanf("%s",namelist[i]);		
	}
	int cnt = 0;
	for(int i=0;i < N;i++){
		for(int k = 0;k < N;k++){
			if(strcmp(namelist[i],namelist[k]) == 0){
				cnt++;	
			}	
		}
		score[i] = cnt;
		cnt = 0;	
	}
	int max = 0;
	int	id = 0;
	for(int i = 0;i < N;i++){
		if(score[i] >= max){
			max = score[i];
			id = i;	
		}
	}
	printf("%s\n",namelist[id]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",namelist[i]);  
   ^