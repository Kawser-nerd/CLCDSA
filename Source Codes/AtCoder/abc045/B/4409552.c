#include <stdio.h>

int searchabc(char st[]){
	int i=0;
	while(st[i] != '\0'){
		if(st[i] != 'o'){
			return i;
		}
		i++;
	}
	return -1;
}

int main(void){
	char s[3][100];
	char box;
	int t=0,i=0;
	scanf("%s %s %s",s[0],s[1],s[2]);
	while(1){
		i = searchabc(s[t]);
		if(i == -1){
			break;
		}else{
			box = s[t][i];
			s[t][i] = 'o';
		}
		if(box == 'a')t = 0;
		else if(box == 'b')t = 1;
		else t = 2;
	}
	if(t == 0)printf("A\n");
	else if(t == 1)printf("B\n");
	else printf("C\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",s[0],s[1],s[2]);
  ^