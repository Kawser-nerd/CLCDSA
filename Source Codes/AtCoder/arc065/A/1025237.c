#include <stdio.h>
#include <stdlib.h>

#define N 100001
#define YES 1
#define NO  0

char *t[4] = {"dream", "dreamer", "erase", "eraser"};
char *ans[2] = {"NO", "YES"};

int match(char *);
int strncomp(char *, char *, int);
int strlength(char*);

int main(void){
	char str[N];
	int r;

	scanf("%s", str);
	r=match(str);
	printf("%s\n", ans[r]);
	
	
	return 0;
}

int match(char *str){
	int len, r=NO, flg, i;
	
	if(*str == '\0') return YES;
	for(i=0; i<4; i++){
		len = strlength(t[i]);
		if(strncomp(str, t[i], len) == 0){
			r = match(str+len);
			if(r == YES) return r;
		}
	}
	
	return NO;
}

int strlength(char *p){
	int cnt=0;

	while(p[cnt++] != '\0');
	cnt--;
	return cnt;
}

int strncomp(char *a, char *b, int size){
	int i;
	
	for(i=0; i<size; i++){
		if(a[i] >  b[i]) return -1;
		else if(a[i] < b[i]) return 1;
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^