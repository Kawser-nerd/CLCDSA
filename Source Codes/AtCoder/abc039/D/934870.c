#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

int judge(char **s,int x,int y){
	int i,j;
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if(s[x+i][y+j] == '.'){
				return false;
			}
		}
	}
	return true;
}
void resto(char **s,int x,int y){
	int i,j;
	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if(s[x+i][y+j] != '&'){
				s[x+i][y+j] = '$';
			}
		}
	}
	s[x][y] = '&';	
}



int main(void){
	/* === input paramater === */
	int h,w;
	char **s;
	/* === paramater === */
	int i,j;
	/* === input === */
	scanf("%d%d",&h,&w);
	s = calloc(sizeof(char*),h+2);
	for(i=0;i<h+2;i++){
		s[i] = calloc(sizeof(char),w+2);
		s[i]++;
	}
	s++;
	for(i=0;i<h;i++){
		scanf("%s",s[i]);
	}
	/* === pre operate === */

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(judge(s,i,j)){
				resto(s,i,j);
			}
		}
	}

	/* === operate === */
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(s[i][j] == '#'){
				printf("impossible\n");
				return 0;
			}else if(s[i][j] == '$'){
				s[i][j] = '.';
			}else if(s[i][j] == '&'){
				s[i][j] = '#';
			}
		}
	}
	/* === output === */
	printf("possible\n");
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i]);
   ^