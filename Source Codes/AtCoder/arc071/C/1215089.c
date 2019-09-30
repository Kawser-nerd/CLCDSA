#include <stdio.h>
#include <stdlib.h>

#define N 100000

int BITs[N+1], BITt[N+1];

int sum(int i, int *bit){
	int s=0;
	
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}

	return s;
}

void add(int i, int x, int *bit, int n){
	while(i <= n){
		bit[i] += x;
		i += i & -i;
	}
}

int main(void){
	char s[N+1], t[N+1], c;
	int lens=0, lent=0;
	int q, abcd[4];
	int i, j;
	
	while((c = getchar()) != '\n'){
		s[lens++] = c;
	}
	s[lens] = '\0';
	while((c = getchar()) != '\n'){
		t[lent++] = c;
	}
	t[lent] = '\0';
	for(i=0; i<lens; i++){
		if(s[i] == 'A') add(i+1, 1, BITs, lens);
		else add (i+1, 2, BITs, lens);
	}
	for(i=0; i<lent; i++){
		if(t[i] == 'A') add(i+1, 1, BITt, lent);
		else add(i+1, 2, BITt, lent);
	}
	
	scanf("%d", &q);
	for(i=0; i<q; i++){
		for(j=0; j<4; j++){
			scanf("%d", &abcd[j]);
		}
		if((sum(abcd[1], BITs)-sum(abcd[0]-1, BITs))%3 == (sum(abcd[3], BITt)-sum(abcd[2]-1, BITt))%3)
			printf("YES\n");
		else printf("NO\n");
	}
	


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &q);
  ^
./Main.c:52:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &abcd[j]);
    ^