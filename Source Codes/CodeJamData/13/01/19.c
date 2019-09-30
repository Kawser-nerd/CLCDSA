#include<stdio.h>
#include<string.h>

void setbit(int i, int j, int s[]){
	s[i] |= 1<<j;
	s[j+4] |= 1<<i;
	if(i==j)
		s[8] |= 1<<i;
	if(i+j==3)
		s[9] |= 1<<j;
}

int main(){
	FILE *fin, *fout;
	int N, os[10], xs[10], isComplete, ncase=1, i, j, XWin, OWin;
	char ch;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &N);
	getchar();
	while(N--){
		memset(os, 0, sizeof(os));
		memset(xs, 0, sizeof(xs));
		isComplete = 1;

		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				scanf("%c", &ch);
				switch(ch){
					case 'X':
						setbit(i, j, xs);
						break;
					case 'O':
						setbit(i, j, os);
						break;
					case '.':
						isComplete = 0;
						break;
					case 'T':
						setbit(i, j, xs);
						setbit(i, j, os);
						break;
				}
						
			}		
			getchar();
		}
		getchar();
		printf("Case #%d: ", ncase);
		ncase++;

		XWin = 0;
		OWin = 0;

		for(i=0; i<10; i++){
			if(xs[i] == 15){
				XWin = 1;
				break;
			}
		}

		for(i=0; i<10; i++){
			if(os[i] == 15){
				OWin = 1;
				break;
			}
		}

		if(XWin == 1)
			printf("X won\n");
		else if(OWin == 1)
			printf("O won\n");
		else if(!isComplete)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}

	return 0;
}
