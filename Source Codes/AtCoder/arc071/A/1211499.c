#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N  50
#define Si 50
#define INF 100000

char str[N][Si+1];
int num[N][26];
int common[26];

int min(int x, int y){
	if(x < y) return x;
	else return y;
}

int main(void){
	int n, i, j, p;
	int ret=0;

	memset(num, 0, N*26*sizeof(int));
	for(i=0; i<26; i++) common[i] = INF;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", &str[i][0]);
	}
	
	for(i=0; i<n; i++){
		p=0;
		while(str[i][p] != '\0'){
			num[i][str[i][p] - 'a']++;
			p++;
		}
		
	}
	for(i=0; i<n; i++){
		for(j=0; j<26; j++){
			common[j] = min(common[j], num[i][j]);
		}
	}
	for(i=0; i<26; i++){
		for(j=0; j<common[i]; j++)
			printf("%c", 'a'+i);
	}
	printf("\n");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &str[i][0]);
   ^