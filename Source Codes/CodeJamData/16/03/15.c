#include "stdio.h"

char s[100];

int main(void){
	int T,N,J,i,j,pos;
	
	scanf("%d%d%d", &T, &N, &J);
	
	printf("Case #1:\n");
	
	for(i=0;i<J;i++){
		pos = 0;
		
		s[pos] = '1'; pos++;
		s[pos] = '1'; pos++;
		
		for(j=0;j<N/2-2;j++){
			if(i&(1<<j)){
				s[pos] = '1'; pos++;
				s[pos] = '1'; pos++;
			} else {
				s[pos] = '0'; pos++;
				s[pos] = '0'; pos++;
			}
		}
		
		s[pos] = '1'; pos++;
		s[pos] = '1'; pos++;
		
		s[pos] = '\0';
		
		printf("%s", s);
		for(j=2;j<=10;j++) printf(" %d", j + 1);
		printf("\n");
	}
	
	return 0;
}
