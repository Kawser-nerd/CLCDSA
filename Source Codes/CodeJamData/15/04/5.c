#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	
	int testcase;
	int tmp=1;
	int x, r, c;
	int poss[6]={1, 1, 2, 5, 12, 35};
	scanf("%d", &testcase);
	
	for(tmp=1;tmp<=testcase;tmp++){
		
		scanf("%d %d %d", &x, &r, &c);

		if(x>=7) printf("Case #%d: RICHARD\n", tmp);
		else if(r*c%x!=0) printf("Case #%d: RICHARD\n",tmp);
		else if(r*c==x &&x>=3) printf("Case #%d: RICHARD\n", tmp);
		else if(r*c==x &&x<=2) printf("Case #%d: GABRIEL\n", tmp);
		else if(r<(x+1)/2 || c<(x+1)/2) printf("Case #%d: RICHARD\n", tmp);
		else if(x==1) printf("Case #%d: GABRIEL\n", tmp);
		else if(x==2 || x==3) printf("Case #%d: GABRIEL\n", tmp);
		else if(x==4){
			if(r*c!=8) printf("Case #%d: GABRIEL\n", tmp);
			else printf("Case #%d: RICHARD\n", tmp);
		}
		else if(x==5){
			if(r*c==15) printf("Case #%d: RICHARD\n", tmp);
			else printf("Case #%d: GABRIEL\n", tmp);
		}
		else if(x==6){
			if(r==3||c==3) printf("Case #%d: RICHARD\n", tmp);
			else printf("Case #%d: GABRIEL\n", tmp);
		}
		else{
			printf("Case #%d: GABRIEL\n", tmp);
		}
	}
	return 0;
}
